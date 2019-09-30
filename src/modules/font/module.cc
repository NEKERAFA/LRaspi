/*
    modules/font/font_mod.h - NEKERAFA - 23th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <SDL2/SDL_ttf.h>

#include <iostream>

#include "modules/common/exception.h"
#include "modules/font/font.h"
#include "modules/font/module.h"

namespace lraspi
{

namespace font
{

bool _loaded = false;

void init()
{
    if (_loaded)
        throw Exception("Font submodule already loaded");

    if(TTF_Init() == -1)
        throw Exception("Could not initialize font subsytem (%s)", TTF_GetError());

    _loaded = true;
}

Font* loadFont(const char* path, int size)
{
    return new Font(path, size);
}

Font* createDefault(int size)
{
    return new Font(size);
}

void close()
{
    TTF_Quit();
}

} // namespace font

} // namespace lraspi