/*
    modules/image/image.cc - NEKERAFA - 29th july 2019

    See Copyright Notice in lraspi.h 
 */

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "modules/image/image.h"
#include "modules/image/texture.h"
#include "common/exceptionf.h"

namespace lraspi
{
namespace image
{

image::image(SDL_Renderer* sdl_renderer) : texture::texture(), _sdl_renderer(sdl_renderer)
{}

image::~image()
{}

bool image::load(std::string path)
{
    SDL_Surface* _sdl_surface;
    SDL_Texture* _sdl_texture = getSdlTexture();

    // Checks if a texture was loaded to remove it
    if (!_sdl_texture)
        SDL_DestroyTexture(_sdl_texture);
    
    // Loads the surface
    _sdl_surface = IMG_Load(path.c_str());
    if (!_sdl_surface)
    {
        throw common::exceptionf("could not load image '%s' (%s)", path.c_str(), IMG_GetError());
    }
    else
    {
        // Checks to convert the surface in a 2d acelerate texture
        if (!(_sdl_texture = SDL_CreateTextureFromSurface(_sdl_renderer, _sdl_surface)))
        {
            throw common::exceptionf("could not create texture from '%s' (%s)", path.c_str(), SDL_GetError());
        }
        else
        {
            setSdlTexture(_sdl_texture);
            setRealWidth(_sdl_surface->w);
            setRealHeight(_sdl_surface->h);
            setWidth(_sdl_surface->w);
            setHeight(_sdl_surface->h);
            _path = path;
        }
    }

    SDL_FreeSurface(_sdl_surface);
    
    return _sdl_texture != nullptr;
}

std::string image::getPath()
{
    return _path;
}

} // namespace image
} // namespace lraspi