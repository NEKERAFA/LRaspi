/*
    modules/draw/canvas.cc - NEKERAFA - 12th sep 2019

    See Copyright Notice in lraspi.h
 */

#include <stdexcept>

#include <SDL2/SDL.h>

#include "common/type.h"
#include "common/exception.h"
#include "modules/color/module.h"
#include "modules/screen/module.h"
#include "modules/draw/texture.h"
#include "modules/draw/canvas.h"

namespace lraspi
{

Type Canvas::type(LRASPI_CANVAS_NAME, &Texture::type);

Canvas::Canvas() {}

Canvas::~Canvas() {}

void Canvas::create(int width, int height)
{
    SDL_Surface* _sdl_surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_RGBA8888);
    setSdlSurface(_sdl_surface, SDL_TEXTUREACCESS_TARGET);
    SDL_FreeSurface(_sdl_surface);
}

bool Canvas::isInstanceOf(Type& other)
{
    return type.isInstanceOf(other);
}

const char* Canvas::name()
{
    return type.name();
}

} // namespace lraspi