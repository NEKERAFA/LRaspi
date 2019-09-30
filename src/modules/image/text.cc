/*
    modules/draw/text.cc - NEKERAFA - 27th aug 2019

    See Copyright Notice in lraspi.h
 */

#include <string>

#include <SDL2/SDL.h>
#include <GL/glu.h>

#include "modules/common/type.h"
#include "modules/common/exception.h"
#include "modules/screen/module.h"
#include "modules/font/font.h"
#include "modules/image/texture.h"
#include "modules/image/text.h"

namespace lraspi
{

Type Text::type(LRASPI_TEXT_NAME, &Texture::type);

Text::Text(Font* font, const char* text) : _font(font),
                                           _text(text)
{
    render();
}

Text::~Text() {}

void Text::render()
{
    // Checks if a texture was loaded to remove it
    glDestroy();

    // Render the text
    SDL_Surface* _sdl_surface = _font->getSdlSurface(_text.c_str());
    
    if (_sdl_surface == nullptr)
        throw Exception("Could not render text");

    setSdlSurface(_sdl_surface);
    SDL_FreeSurface(_sdl_surface);
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
