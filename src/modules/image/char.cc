/*
    modules/image/char.h - NEKERAFA - 24th sep 2019

    See Copyright Notice in lraspi.h
 */

#include <SDL2/SDL.h>
#include <GL/glu.h>

#include "modules/common/type.h"
#include "modules/common/exception.h"
#include "modules/font/font.h"
#include "modules/image/texture.h"
#include "modules/image/char.h"

namespace lraspi
{

Type Char::type(LRASPI_CHAR_NAME, &Texture::type);

Char::Char(Font* font, char16_t glyph)
{
    // Checks if a texture was loaded to remove it
    glDestroy();

    // Render the glyph
    SDL_Surface* _sdl_surface = font->getSdlSurface(glyph);

    if (_sdl_surface == nullptr)
        throw Exception("Could not render surface");
    
    setSdlSurface(_sdl_surface);
    SDL_FreeSurface(_sdl_surface);
}

Char::~Char() {}

bool Char::isInstanceOf(Type& other)
{
    return type.isInstanceOf(other);
}

const char* Char::name()
{
    return type.name();
}

} // namespace lraspi