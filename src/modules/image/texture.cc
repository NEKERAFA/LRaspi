/*
    modules/image/texture.cc - NEKERAFA - 28th july 2019

    See Copyright Notice in lraspi.h 
 */

#include <stdexcept>

#include <SDL2/SDL.h>

#include "common/type.h"
#include "common/object.h"
#include "common/exception.h"
#include "modules/color/color_mod.h"
#include "modules/screen/screen_mod.h"
#include "modules/image/texture.h"

namespace lraspi
{

Type Texture::type(LRASPI_TEXTURE_NAME, &Object::type);

Texture::Texture() : _sdl_texture(nullptr),
                     _width(0), 
                     _height(0),
                     _target_access(false),
                     _tex_width(0), 
                     _tex_height(0),
                     _tex_angle(0.0),
                     _tex_center_x(0),
                     _tex_center_y(0),
                     _tex_flip_h(false),
                     _tex_flip_v(false)
{}

Texture::~Texture()
{
    if (_sdl_texture)
    {    
        SDL_DestroyTexture(_sdl_texture);
    }
}

void Texture::createBlank(int width, int height)
{
    _sdl_texture = SDL_CreateTexture(screen::getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);
    if (_sdl_texture == nullptr)
    {
        throw Exception("Unable to create blank texture (%s)", SDL_GetError());
    }
    else
    {
        setWidth(width);
        setHeight(height);
        setRealWidth(width);
        setRealHeight(height);
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
    setSdlBlendMode(SDL_BLENDMODE_NONE);
    setAlpha(0xFF);
}

void Texture::tint(Color* color)
{
    SDL_SetTextureColorMod(_sdl_texture, color->red(), color->green(), color->blue());
    SDL_SetTextureBlendMode(_sdl_texture, SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(_sdl_texture, color->alpha());
}

Color* Texture::getTintColor()
{
    uint8_t r, g, b, a;
    SDL_GetTextureColorMod(_sdl_texture, &r, &g, &b);
    SDL_GetTextureAlphaMod(_sdl_texture, &a);
    return new Color(r, g, b, a);
}

void Texture::setSdlBlendMode(SDL_BlendMode bleding)
{
    SDL_SetTextureBlendMode(_sdl_texture, bleding);
}

SDL_BlendMode Texture::getSdlBlendMode()
{
    SDL_BlendMode mode;
    SDL_GetTextureBlendMode(_sdl_texture, &mode);
    return mode;
}

void Texture::setAlpha(uint8_t alpha)
{
    SDL_SetTextureAlphaMod(_sdl_texture, alpha);
}

uint8_t Texture::getAlpha()
{
    uint8_t alpha;
    SDL_GetTextureAlphaMod(_sdl_texture, &alpha);
    return alpha;
}

SDL_Texture* Texture::getSdlTexture()
{
    return _sdl_texture;
}

void Texture::setSdlTexture(SDL_Texture* sdl_texture)
{
    _sdl_texture = sdl_texture;
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
    _tex_width = real_width;
}

void Texture::setRealHeight(int real_height)
{
    _tex_height = real_height;
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
    return _tex_width;
}

int Texture::getRealHeight() const
{
    return _tex_height;
}

void Texture::setAngle(double angle)
{
    _tex_angle = angle;
}

double Texture::getAngle()
{
    return _tex_angle;
}

void Texture::setCenter(int x, int y)
{
    _tex_center_x = x;
    _tex_center_y = y;
}

void Texture::setVFlip()
{
    _tex_flip_v = !_tex_flip_v;
}

void Texture::setHFlip()
{
    _tex_flip_h = !_tex_flip_h;
}

void Texture::setFlip(bool h, bool v)
{
    _tex_flip_h = h;
    _tex_flip_v = v;
}

SDL_Point Texture::getSdlCenterPoint()
{
    return {_tex_center_x, _tex_center_y};
}

SDL_RendererFlip Texture::getSdlFlipStatus()
{
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    if (_tex_flip_v)
        if (_tex_flip_h)
            flip = (SDL_RendererFlip) (SDL_FLIP_VERTICAL | SDL_FLIP_HORIZONTAL);
        else
            flip = SDL_FLIP_VERTICAL;
    else
        if (_tex_flip_h)
            flip = SDL_FLIP_HORIZONTAL;

    return flip;
}

void Texture::setTargetAccess()
{
    // Gets the original pixel format
    Uint32 format = SDL_PIXELFORMAT_UNKNOWN;
    if (SDL_QueryTexture(getSdlTexture(), &format, nullptr, nullptr, nullptr))
    {
        throw Exception("Cannot get pixel format of the texture (%s)", SDL_GetError());
    }

    // Creates a new texture with SDL_TEXTUREACCESS_TARGET
    SDL_Texture* target_texture = SDL_CreateTexture(screen::getRenderer(), format, SDL_TEXTUREACCESS_TARGET, getRealWidth(), getRealHeight());
    
    // Sets the new texture as target and clear as blank color
    screen::setTarget(target_texture);
    screen::clear(color::blank);

    // Gets the internal status of the texture and reset it
    int width = getWidth();
    int height = getHeight();
    double angle = getAngle();
    SDL_Point center = getSdlCenterPoint();
    SDL_RendererFlip flip = getSdlFlipStatus();
    uint8_t alpha = getAlpha();
    SDL_BlendMode mode = getSdlBlendMode();
    Color* color = getTintColor();
    reset();

    // Blits the old texture in the new texture
    screen::blit(this, 0, 0);
    screen::setTarget(nullptr);

    // Replaces the old texture as the new
    SDL_DestroyTexture(_sdl_texture);
    _sdl_texture = target_texture;
    _target_access = true;

    // Set the internal status of the texture
    setWidth(width);
    setHeight(height);
    setAngle(angle);
    setCenter(center.x, center.y);
    setFlip(flip & SDL_FLIP_VERTICAL, flip & SDL_FLIP_HORIZONTAL);
    tint(color);
    setAlpha(alpha);
    setSdlBlendMode(mode);
}

bool Texture::isTargetAccess()
{
    return _target_access;
}

void Texture::blit(Texture* texture, int x, int y)
{
    if(!isTargetAccess())
        setTargetAccess();

    screen::setTarget(_sdl_texture);
    screen::blit(texture, x, y);
    screen::setTarget(nullptr);
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