/*
    modules/image/module.cc - NEKERAFA - 8th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "common/exception.h"
#include "modules/image/image.h"
#include "modules/image/module.h"

namespace lraspi
{
namespace image
{

static bool _loaded = false;

void init()
{
    if (_loaded)
    {
        throw Exception("Image submodule already loaded");
    }

    int _img_flags = IMG_INIT_JPG | IMG_INIT_PNG;
    if(!(IMG_Init(_img_flags) & _img_flags))
    {
        throw Exception("Could not initialize image subsytem (%s)", IMG_GetError());
    }
}

Image* newImage(const char* path)
{
    Image* image = new Image();
    image->load(path);
    return image;
}

void close()
{
    IMG_Quit();
}

} // namespace image
} // namespace lraspi