/*
    modules/image/image.cc - NEKERAFA - 29th july 2019

    See Copyright Notice in lraspi.h 
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/glu.h>

#include "modules/common/exception.h"
#include "modules/common/type.h"
#include "modules/common/object.h"
#include "modules/screen/module.h"
#include "modules/image/texture.h"
#include "modules/image/image.h"

namespace lraspi
{

Type Image::type(LRASPI_IMAGE_NAME, &Texture::type);

Image::Image(const char* path)
{
    // Checks if a texture was loaded to remove it
    glDestroy();

    // Loads the surface
    SDL_Surface* _sdl_surface = IMG_Load(path);
    if (_sdl_surface == nullptr)
        throw Exception("Could not load image '%s' (%s)", path, IMG_GetError());
    
    setSdlSurface(_sdl_surface);
    SDL_FreeSurface(_sdl_surface);
}

Image::~Image() {}

bool Image::isInstanceOf(Type& other)
{
    return type.isInstanceOf(other);
}

const char* Image::name()
{
    return type.name();
}

} // namespace lraspi