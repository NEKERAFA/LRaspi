/*
    modules/image/texture.cc - NEKERAFA - 28th july 2019

    See Copyright Notice in lraspi.h 
 */

#include <iostream>
#include <stdexcept>

#include <SDL2/SDL.h>

#include "common/type.h"
#include "common/object.h"
#include "common/exception.h"
#include "modules/color/module.h"
#include "modules/screen/module.h"
#include "modules/draw/texture.h"

namespace lraspi
{

Type Texture::type(LRASPI_TEXTURE_NAME, &Object::type);

Texture::Texture() : _sdl_texture(nullptr),
                     _sdl_bleding(SDL_BLENDMODE_NONE),
                     _tint(color::white),
                     _alpha(SDL_ALPHA_OPAQUE),
                     _width(0), 
                     _height(0),
                     _real_width(0), 
                     _real_height(0),
                     _angle(0.0),
                     _center_x(0),
                     _center_y(0),
                     _flip_h(false),
                     _flip_v(false),
                     _locked(false),
                     _pixel_format(SDL_PIXELFORMAT_UNKNOWN),
                     _pixels(nullptr),
                     _pitch(0)
{}

Texture::~Texture()
{
    if (_sdl_texture)
    {    
        SDL_DestroyTexture(_sdl_texture);
    }
}

void Texture::reset()
{
    setWidth(getRealWidth());
    setHeight(getRealHeight());
    setAngle(0.0);
    setCenter(0, 0);
    setFlip(false, false);
    tint(color::white);
}

void Texture::tint(Color* color)
{
    SDL_SetTextureColorMod(_sdl_texture, color->red(), color->green(), color->blue());
    setSdlBlendMode(SDL_BLENDMODE_BLEND);
    setAlpha(color->alpha());
    _tint = color;
}

Color* Texture::getTintColor()
{
    return _tint;
}

void Texture::setSdlBlendMode(SDL_BlendMode bleding)
{
    SDL_SetTextureBlendMode(_sdl_texture, bleding);
    _sdl_bleding = bleding;
}

SDL_BlendMode Texture::getSdlBlendMode()
{
    return _sdl_bleding;
}

void Texture::setAlpha(uint8_t alpha)
{
    SDL_SetTextureAlphaMod(_sdl_texture, alpha);
    _alpha = alpha;
}

uint8_t Texture::getAlpha()
{
    return _alpha;
}

SDL_Texture* Texture::getSdlTexture()
{
    return _sdl_texture;
}

void Texture::setSdlSurface(SDL_Surface* sdl_surface, SDL_TextureAccess access)
{
    SDL_Surface* new_surface = sdl_surface;
    
    if (sdl_surface->format->format != SDL_PIXELFORMAT_RGBA8888)
        new_surface = SDL_ConvertSurfaceFormat(sdl_surface, SDL_PIXELFORMAT_RGBA8888, 0);
    
    if (new_surface == nullptr)
    {
        throw Exception("Could not convert loaded surface to display format (%s)", SDL_GetError());
    }
    else
    {
        _sdl_texture = SDL_CreateTexture(screen::getRenderer(), SDL_PIXELFORMAT_RGBA8888, access, new_surface->w, new_surface->h);
        
        if (_sdl_texture == NULL)
        {
            throw Exception("Could not create texture (%s)", SDL_GetError());
        }
        else
        {
            setRealWidth(new_surface->w);
            setRealHeight(new_surface->h);
            setWidth(new_surface->w);
            setHeight(new_surface->h);
            _pixel_format = new_surface->format->format;
            setSdlBlendMode(SDL_BLENDMODE_BLEND);
            
            if (lockTexture())
            {
                copyPixels(new_surface->pixels);
                unlockTexture();
            }
        }

        if (new_surface != sdl_surface)
            SDL_FreeSurface(new_surface);
    }
}

void Texture::setWidth(int width)
{
    _width = width;
}

void Texture::setHeight(int height)
{
    _height = height;
}

void Texture::setRealWidth(int real_width)
{
    _real_width = real_width;
}

void Texture::setRealHeight(int real_height)
{
    _real_height = real_height;
}

int Texture::getWidth()
{
    return _width;
}

int Texture::getHeight()
{
    return _height;
}

int Texture::getRealWidth() const
{
    return _real_width;
}

int Texture::getRealHeight() const
{
    return _real_height;
}

void Texture::setAngle(double angle)
{
    _angle = angle;
}

double Texture::getAngle()
{
    return _angle;
}

void Texture::setCenter(int x, int y)
{
    _center_x = x;
    _center_y = y;
}

void Texture::setVFlip()
{
    _flip_v != _flip_v;
}

void Texture::setHFlip()
{
    _flip_h != _flip_h;
}

void Texture::setFlip(bool h, bool v)
{
    _flip_h = h;
    _flip_v = v;
}

SDL_Point Texture::getSdlCenterPoint()
{
    return {_center_x, _center_y};
}

SDL_RendererFlip Texture::getSdlFlipStatus()
{
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    if (_flip_v)
        if (_flip_h)
            flip = (SDL_RendererFlip) (SDL_FLIP_VERTICAL | SDL_FLIP_HORIZONTAL);
        else
            flip = SDL_FLIP_VERTICAL;
    else
        if (_flip_h)
            flip = SDL_FLIP_HORIZONTAL;

    return flip;
}

bool Texture::lockTexture()
{
    bool success = true;

    if (_locked)
    {
        std::cerr << "The texture is already locked" << std::endl;
        success = false;
    }
    else
    {
        if (SDL_LockTexture(_sdl_texture, nullptr, &_pixels, &_pitch) != 0)
        {
            std::cerr << "Could not lock texture (" << SDL_GetError() << ")" << std::endl;
            success = false;
        }

        _locked = true;
    }
    
    return success;
}

bool Texture::unlockTexture()
{
    bool success = true;

    if (!_locked)
    {
        std::cerr << "The texture is not locked" << std::endl;
        success = false;
    }
    else
    {
        SDL_UnlockTexture(_sdl_texture);
        _locked;
    }
    
    return success;
}

void* Texture::getPixels()
{
    if (_locked)
        return _pixels;
    
    return nullptr;
}

void Texture::copyPixels(void* pixels)
{
    if (_locked)
    {
        memcpy(_pixels, pixels, _pitch * _real_height);
    }
    else
    {
        throw Exception("The texture is not locked");
    }   
}

Color* Texture::getPixel(uint16_t x, uint16_t y)
{
    if ((x > _real_width) || (y > _real_height))
        throw Exception("Pixel index out of bounds");

    Uint32* pixels = (Uint32*) _pixels;
    Uint32 pixel = pixels[(y * (_pitch / 4)) + x];
    
    Uint8 r, g, b, a;
    SDL_PixelFormat* format = SDL_AllocFormat(_pixel_format);
    SDL_GetRGBA(pixel, format, &r, &g, &b, &a);
    SDL_FreeFormat(format);

    return new Color(r, g, b, a);
}

void Texture::setPixel(uint16_t x, uint16_t y, Color* col)
{
    if (_locked)
    {
        if ((x > _real_width) || (y > _real_height))
            throw Exception("Pixel index out of bounds");

        Uint32* pixels = (Uint32*) _pixels;
        SDL_PixelFormat* format = SDL_AllocFormat(_pixel_format);
        Uint32 color = SDL_MapRGBA(format, col->red(), col->green(), col->blue(), col->alpha());
        SDL_FreeFormat(format);
        pixels[(y * (_pitch / 4)) + x] = color;
    }
    else
    {
        throw Exception("The texture is not locked");
    }
}

bool Texture::isInstanceOf(Type& other)
{
    return type.isInstanceOf(other);
}

const char* Texture::name()
{
    return type.name();
}

} // namespace lraspi