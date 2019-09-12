/*
    modules/window/window.cc - NEKERAFA - 26th july 2019

    See Copyright Notice in lraspi.h 
*/

#include <cstdint>

#include <SDL2/SDL.h>

#include "common/exception.h"
#include "modules/font/font.h"
#include "modules/color/color.h"
#include "modules/image/texture.h"
#include "modules/image/text.h"
#include "modules/screen/screen_mod.h"

namespace lraspi
{
namespace screen
{

static uint16_t  _height = 0;
static uint16_t  _width  = 0;
static bool _loaded = false;

static Font* _default_font;
static Font* _current_font;
static SDL_Window*   _sdl_window   = nullptr;
static SDL_Renderer* _sdl_renderer = nullptr;

void init()
{
    if (_loaded)
    {
        throw Exception("Window submodule already loaded");
    }

    SDL_Rect _display_bounds;

    if (SDL_Init(SDL_INIT_VIDEO))
    {
        throw Exception("Could not initialize video subsytem (%s)", SDL_GetError());
    }

    if (SDL_GetDisplayBounds(0, &_display_bounds))
    {
        throw Exception("Could not get display bounds (%s)", SDL_GetError());
    }

    _width  = _display_bounds.w;
    _height = _display_bounds.h;

    if (SDL_CreateWindowAndRenderer(_width, _height, SDL_WINDOW_BORDERLESS | SDL_WINDOW_SHOWN, &_sdl_window, &_sdl_renderer))
    {
        throw Exception("Could not create window (%s)", SDL_GetError());
    }

    _default_font = new Font();
    _default_font->create(LRASPI_FONT_SIZE);
    _current_font = _default_font;

    _loaded = true;
}

void close()
{
    if (!_loaded)
    {
        throw Exception("Window submodule not loaded");
    }

    delete _default_font;
    SDL_DestroyRenderer(_sdl_renderer);
    SDL_DestroyWindow(_sdl_window);
}

void clear(Color* color)
{
    uint8_t r, g, b, a;
    SDL_GetRenderDrawColor(_sdl_renderer, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(_sdl_renderer, color->red(), color->green(), color->blue(), color->alpha());
    SDL_RenderClear(_sdl_renderer);
    SDL_SetRenderDrawColor(_sdl_renderer, r, g, b, a);
}

SDL_Renderer* getRenderer()
{
    return _sdl_renderer;
}

void setTarget(SDL_Texture* texture)
{
    SDL_SetRenderTarget(_sdl_renderer, texture);
}

void blit(Texture* texture, int x, int y)
{
    SDL_Texture* _sdl_texture = texture->getSdlTexture();
    SDL_Rect _pos = {x, y, texture->getWidth(), texture->getHeight()};
    double _angle = texture->getAngle();
    SDL_Point _center = texture->getSdlCenterPoint();
    SDL_RendererFlip _flip = texture->getSdlFlipStatus();

    SDL_RenderCopyEx(_sdl_renderer, _sdl_texture, nullptr, &_pos, _angle, &_center, _flip);
}

void print(int x, int y, const char* textstring, Color* color)
{
    Text* text = new Text();
    text->render(_current_font, textstring);
    text->tint(color);
    blit(text, x, y);
    delete text;
}

void setFont(Font* font)
{
    _current_font = font;
}

Font* getFont()
{
    return _current_font;
}

bool update()
{
    bool quit = false;
    SDL_Event e;

    while(SDL_PollEvent(&e) != 0)
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

    if (!quit)
    {
        SDL_RenderPresent(_sdl_renderer);
    }

    return quit;
}

uint16_t getWidth()
{
    return _width;
}

uint16_t getHeight()
{
    return _height;
}

} // namespace screen
} // namespace lraspi