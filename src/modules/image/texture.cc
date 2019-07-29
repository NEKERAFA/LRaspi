/**
 * modules/image/texture.cc - NEKERAFA - 28th july 2019
 * 
 * See Copyright Notice in lraspi.h 
 */

#include <string>
#include <sstream>
#include <stdexcept>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "modules/image/texture.h"
#include "common/exceptionf.h"

namespace lraspi
{
namespace image
{

texture::texture(SDL_Renderer* context) : _sdl_texture(nullptr), 
                                          _sdl_context(context), 
                                          _width(0), 
                                          _height(0), 
                                          _tex_width(0), 
                                          _tex_height(0),
                                          _tex_angle(0.0),
                                          _tex_center({0,0}),
                                          _tex_flip(SDL_FLIP_NONE)
{}

texture::~texture()
{
    if (_sdl_texture)
        SDL_DestroyTexture(_sdl_texture);
}

bool texture::load(std::string path)
{
    SDL_Surface* _sdl_surface;

    if (!_sdl_texture)
        SDL_DestroyTexture(_sdl_texture);
    
    _sdl_surface = IMG_Load(path.c_str());
    if (!_sdl_surface)
    {
        throw common::exceptionf("could not load image '%s' (%s)", path.c_str(), IMG_GetError());
    }
    else
    {
        if (!(_sdl_texture = SDL_CreateTextureFromSurface(_sdl_context, _sdl_surface)))
        {
            throw common::exceptionf("could not create texture from '%s' (%s)", path.c_str(), SDL_GetError());
        }
        else
        {
            _tex_width  = _sdl_surface->w; _width  = _tex_width;
            _tex_height = _sdl_surface->h; _height = _tex_height;
        }
    }

    SDL_FreeSurface(_sdl_surface);
    
    return _sdl_texture != nullptr;
}

int texture::getWidth()
{
    return _width;
}

int texture::getHeight()
{
    return _height;
}

int texture::getRealWidth() const
{
    return _tex_width;
}

int texture::getRealHeight() const
{
    return _tex_height;
}

void texture::blit(int x, int y)
{
    SDL_Rect render_rect = {x, y, _width, _height};
    SDL_RenderCopy(_sdl_context, _sdl_texture, NULL, &render_rect);
}

} // namespace image
} // namespace lraspi