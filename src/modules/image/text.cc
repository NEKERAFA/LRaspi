/*
    modules/image/text.cc - NEKERAFA - 27th aug 2019

    See Copyright Notice in lraspi.h
 */

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_render.h>

#include "common/type.h"
#include "common/exception.h"
#include "modules/screen/screen_mod.h"
#include "modules/font/font.h"
#include "modules/image/texture.h"
#include "modules/image/text.h"

namespace lraspi
{

Type Text::type(LRASPI_TEXT_NAME, &Texture::type);

Text::Text() : _font(nullptr),
               _quality(FAST)
{}

Text::~Text() {}

void Text::render()
{
    SDL_Surface* _sdl_surface;
    SDL_Texture* _sdl_texture = getSdlTexture();

    // Checks if a texture was loaded to remove it
    if (!_sdl_texture)
        SDL_DestroyTexture(_sdl_texture);

    // Render the text
    if (_quality == FAST)
        _sdl_surface = _font->getFastSdlSurface(_text.c_str());
    else
        _sdl_surface = _font->getSdlSurface(_text.c_str());
    
    if (_sdl_surface)
    {
        // Checks to convert the surface in a 2d acelerate texture
        if (!(_sdl_texture = SDL_CreateTextureFromSurface(screen::getRenderer(), _sdl_surface)))
        {
            throw Exception("Could not create texture from text renderer (%s)", SDL_GetError());
        }
        else
        {
            setSdlTexture(_sdl_texture);
            setRealWidth(_sdl_surface->w);
            setRealHeight(_sdl_surface->h);
            setWidth(_sdl_surface->w);
            setHeight(_sdl_surface->h);
        }
    }
}

void Text::render(Font* font, const char* text)
{
    _font = font;
    _text.assign(text);

    render();
}

void Text::setQuality(TextQuality quality)
{
    TextQuality _old_quality = _quality;
    _quality = quality;

    if (_old_quality != _quality)
        render();
}

TextQuality Text::getQuality()
{
    return _quality;
}

void Text::setText(const char* text)
{
    _text.assign(text);
    render();
}

void Text::addText(const char* text)
{
    _text.append("\n");
    _text.append(text);
    render();
}

void Text::clear()
{
    _text.clear();
}

bool Text::isInstanceOf(Type& other)
{
    return type.isInstanceOf(other);
}

const char* Text::name()
{
    return type.name();
}

} // namespace lraspi
