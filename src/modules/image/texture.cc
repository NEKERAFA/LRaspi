/*
    modules/image/texture.cc - NEKERAFA - 28th july 2019

    See Copyright Notice in lraspi.h 
 */

#include <stdexcept>

#include <SDL2/SDL.h>

#include "modules/image/texture.h"

namespace lraspi
{
namespace image
{

texture::texture() : _sdl_texture(nullptr),
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

SDL_Texture* texture::getSdlTexture()
{
    return _sdl_texture;
}

void texture::setSdlTexture(SDL_Texture* sdl_texture)
{
    _sdl_texture = sdl_texture;
}

void texture::setWidth(unsigned int width)
{
    _width = width;
}

void texture::setHeight(unsigned int height)
{
    _height = height;
}

void texture::setRealWidth(unsigned int real_width)
{
    _tex_width = real_width;
}

void texture::setRealHeight(unsigned int real_height)
{
    _tex_height = real_height;
}

unsigned int texture::getWidth()
{
    return _width;
}

unsigned int texture::getHeight()
{
    return _height;
}

unsigned int texture::getRealWidth() const
{
    return _tex_width;
}

unsigned int texture::getRealHeight() const
{
    return _tex_height;
}

} // namespace image
} // namespace lraspi