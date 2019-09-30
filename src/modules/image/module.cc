/*
    modules/image/module.cc - NEKERAFA - 8th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "modules/common/exception.h"
#include "modules/image/image.h"
#include "modules/image/module.h"

namespace lraspi
{

static bool _loaded = false;

void image::init()
{
    if (_loaded)
        throw Exception("Image submodule already loaded");

    int _img_flags = IMG_INIT_JPG | IMG_INIT_PNG;
    if(!(IMG_Init(_img_flags) & _img_flags))
        throw Exception("Could not initialize image subsytem (%s)", IMG_GetError());

    _loaded = true;
}

Image* image::newImage(const char* path)
{
    return new Image(path);
}

Text* image::newText(Font* font, const char* str)
{
    return new Text(font, str);
}

void image::close()
{
    IMG_Quit();
}

} // namespace lraspi