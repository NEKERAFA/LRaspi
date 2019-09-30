/*
    modules/image/texture.cc - NEKERAFA - 28th july 2019

    See Copyright Notice in lraspi.h 
 */

#include <iostream>
#include <stdexcept>

#include <SDL2/SDL.h>
#include <GL/glu.h>

#include "modules/common/type.h"
#include "modules/common/object.h"
#include "modules/common/exception.h"
#include "modules/color/module.h"
#include "modules/screen/module.h"
#include "modules/image/texture.h"

namespace lraspi
{

Type Texture::type(LRASPI_TEXTURE_NAME, &Object::type);

Texture::Texture() : _gl_id_texture(0),
                     _tint(new Color(255, 255, 255)),
                     _width(0), 
                     _height(0),
                     _real_width(0), 
                     _real_height(0),
                     _angle(0.0),
                     _center_x(0),
                     _center_y(0),
                     _flip_h(false),
                     _flip_v(false),
                     _loaded(false)
{}

Texture::~Texture()
{
    glDestroy();
}

void Texture::glDestroy()
{
    if (_loaded)
        glDeleteTextures(1, &_gl_id_texture);
}

void Texture::setSdlSurface(SDL_Surface* sdl_surface)
{
    Uint8 bytesPerPixel = sdl_surface->format->BytesPerPixel;
    GLenum textureFormat;

    if (bytesPerPixel == 4)
    {
        textureFormat = GL_RGBA;
    }
    else
    {
        textureFormat = GL_RGB;
    
        if (bytesPerPixel != 3)
            std::cout << "Warning: could not get proper pixel format";
    }

    glGenTextures(1, &_gl_id_texture);
    glBindTexture(GL_TEXTURE_2D, _gl_id_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, textureFormat, sdl_surface->w, sdl_surface->h, 0, textureFormat, GL_UNSIGNED_BYTE, sdl_surface->pixels);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
        throw Exception("Could not create texture (%s)", gluErrorString(error));

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    error = glGetError();
    if (error != GL_NO_ERROR)
        throw Exception("Could not set texture filter (%s)", gluErrorString(error));

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    error = glGetError();
    if (error != GL_NO_ERROR)
        throw Exception("Could not set texture filter (%s)", gluErrorString(error));

    setRealWidth(sdl_surface->w);
    setRealHeight(sdl_surface->h);
    setWidth(sdl_surface->w);
    setHeight(sdl_surface->h);
}

GLuint Texture::glIdTexture()
{
    return _gl_id_texture;
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
    _tint = color;
}

Color* Texture::getTintColor()
{
    return _tint;
}


void Texture::setAlpha(uint8_t alpha)
{
    _tint->alpha(alpha);
}

uint8_t Texture::getAlpha()
{
    return _tint->alpha();
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

void Texture::setCenter()
{
    _center_x = _width/2;
    _center_y = _height/2;
}

void Texture::getCenter(int* x, int* y)
{
    *x = _center_x;
    *y = _center_y;
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

void Texture::getFlip(bool* h, bool* v)
{
    *h = _flip_h;
    *v = _flip_v;
}

Color* Texture::getPixel(uint16_t x, uint16_t y)
{

}

void Texture::setPixel(uint16_t x, uint16_t y, Color* col)
{

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