/*
    modules/image/image.cc - NEKERAFA - 29th july 2019

    See Copyright Notice in lraspi.h 
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>

#include "common/exception.h"
#include "common/type.h"
#include "common/object.h"
#include "modules/screen/screen_mod.h"
#include "modules/image/texture.h"
#include "modules/image/image.h"

namespace lraspi
{

Type Image::type(LRASPI_IMAGE_NAME, &Texture::type);

Image::Image() {}

Image::~Image() {}

void Image::load(const char* path)
{
    SDL_Surface* _sdl_surface;
    SDL_Texture* _sdl_texture = getSdlTexture();

    // Checks if a texture was loaded to remove it
    if (!_sdl_texture)
        SDL_DestroyTexture(_sdl_texture);

    // Loads the surface
    _sdl_surface = IMG_Load(path);
    if (!_sdl_surface)
    {
        throw Exception("Could not load image '%s' (%s)", path, IMG_GetError());
    }
    else
    {
        // Checks to convert the surface in a 2d acelerate texture
        if (!(_sdl_texture = SDL_CreateTextureFromSurface(screen::getRenderer(), _sdl_surface)))
        {
            throw Exception("Could not create texture from '%s' (%s)", path, SDL_GetError());
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

bool Image::isInstanceOf(Type& other)
{
    return type.isInstanceOf(other);
}

const char* Image::name()
{
    return type.name();
}

} // namespace lraspi