/*
    modules/window/window.cc - NEKERAFA - 26th july 2019

    See Copyright Notice in lraspi.h 
*/

#include <iostream>
#include <codecvt>
#include <locale>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>

#include "modules/common/exception.h"
#include "modules/common/cache/chrcache.h"
#include "modules/font/font.h"
#include "modules/color/color.h"
#include "modules/image/char.h"
#include "modules/screen/module.h"

namespace lraspi
{
uint16_t _height = 0;
uint16_t _width  = 0;
bool     _loaded = false;

std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> _converter;

Font*   _default_font = nullptr;
//Canvas* _current_canvas = nullptr;

SDL_Window*   _sdl_window = nullptr;
SDL_GLContext _sdl_gl_context;

void init_video()
{
    // Starts video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw Exception("Could not initialize video subsytem (%s)", SDL_GetError());
}

void init_gl()
{
// Uses OpenGL 2.1
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    // Create window
    _sdl_window = SDL_CreateWindow("lraspi", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _height, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS | SDL_WINDOW_SHOWN);

    if (_sdl_window == nullptr)
        throw Exception("Could not create window (%s)", SDL_GetError());

    // Create OpenGL Context
    _sdl_gl_context = SDL_GL_CreateContext(_sdl_window);

    if (_sdl_gl_context == nullptr)
        throw Exception("Could not create OpenGL context (%s)", SDL_GetError());

    // Enables VSync
    if (SDL_GL_SetSwapInterval(1) != 0)
        std::cerr << "Warning: Could not enable vsync (%s)" << SDL_GetError() << std::endl;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Enables blend color
    GLenum error = GL_NO_ERROR;

    // Initialize Project Matrix
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, _width, _height, 0);

    error = glGetError();
    if (error != GL_NO_ERROR)
        throw Exception("Could not initializing OpenGL projection matrix (%s)", gluErrorString(error));

    // Initialize ModelView Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    error = glGetError();
    if (error != GL_NO_ERROR)
        throw Exception("Could not initializing OpenGL model view matrix (%s)", gluErrorString(error));
}

void init_media()
{
    _default_font = new Font();
    chrcache::setDefaultFont(_default_font);
}

void screen::init()
{
    if (_loaded)
        throw Exception("Window submodule already loaded");

    init_video();

    // Gets display bounds
    SDL_Rect _display_bounds;
    if (SDL_GetDisplayBounds(0, &_display_bounds))
        throw Exception("Could not get display bounds (%s)", SDL_GetError());

#ifdef NDEBUG
    _width  = _display_bounds.w;
    _height = _display_bounds.h;
#else
    _width = 720;
    _height = 480;
#endif

    init_gl();
    init_media();

    _loaded = true;
}

void screen::close()
{
    if (!_loaded)
        throw Exception("Window submodule not loaded");

    delete _default_font;
    SDL_DestroyWindow(_sdl_window);
}

void screen::clear(Color* color)
{
    // Sets the background color
    glClearColor(color->rf(), color->gf(), color->bf(), color->af());
    // Clears the buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void screen::blit(float x, float y, Texture* texture)
{
    int cx, cy;
    texture->getCenter(&cx, &cy);

    // Remove previus transformations
    glPushMatrix();

    // Move to rendering point
    glTranslatef(x + cx, y + cy, 0.f);
    glRotatef(texture->getAngle(), 0.f, 0.f, 1.f);

    // Bind texture
    glBindTexture(GL_TEXTURE_2D, texture->glIdTexture());

    // Sets the tint color
    glColor4f(texture->getTintColor()->rf(), texture->getTintColor()->gf(), texture->getTintColor()->bf(), texture->getTintColor()->af());

    // Draw the texture
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);

    glTexCoord2i(0, 0);
    glVertex2f(-cx, -cy);
    glTexCoord2i(1, 0);
    glVertex2f(-cx + texture->getWidth(), -cy);
    glTexCoord2i(1, 1);
    glVertex2f(-cx + texture->getWidth(), -cy + texture->getHeight());
    glTexCoord2i(0, 1);
    glVertex2f(-cx, -cx + texture->getHeight());
    
    glEnd();
    glDisable(GL_TEXTURE_2D);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
        throw Exception("Could not render texture (%s)", gluErrorString(error));

    glPopMatrix();
}

void screen::print(float x, float y, const char* textstring, Color* color)
{
    std::u16string u16textstring = _converter.from_bytes(textstring);
    float dx = 0;
    float dy = 0;

    for (char16_t glyph : u16textstring)
    {
        if (glyph == '\n')
        {
            dx = 0;
            dy = chrcache::getDefaultFont()->getHeight() * chrcache::getDefaultFont()->getLineHeight();
        }
        else if (glyph > 31)
        {
            Char* chr = chrcache::getChar(glyph);
            Color* tint = chr->getTintColor();
            chr->tint(color);
            blit(x + dx, y + dy, chr);
            chr->tint(tint);
            dx += chr->getWidth();
        }
    }
}

void screen::setFont(Font* font)
{
    if (font == nullptr)
        chrcache::setDefaultFont(_default_font);
    else
        chrcache::setDefaultFont(font);
}

Font* screen::getFont()
{
    return chrcache::getDefaultFont();
}

bool screen::update()
{
    bool quit = false;
    SDL_Event e;

    // Updates all events
    while (SDL_PollEvent(&e) != 0)
    {
        switch (e.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        
        case SDL_KEYDOWN:
            if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                quit = true;
            break;
        }
    }

    // Swap draw buffer to window buffer
    if (!quit)
        SDL_GL_SwapWindow(_sdl_window);

    return quit;
}

uint16_t screen::getWidth()
{
    return _width;
}

uint16_t screen::getHeight()
{
    return _height;
}

} // namespace lraspi