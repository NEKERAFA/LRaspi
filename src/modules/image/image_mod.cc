/*
    modules/image/graphics.h - NEKERAFA - 8th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "common/exception.h"
#include "modules/font/font.h"
#include "modules/image/texture.h"
#include "modules/image/image.h"
#include "modules/image/text.h"
#include "modules/image/image_mod.h"

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

Image* loadImage(const char* path)
{
    Image* image = new Image();
    image->load(path);
    return image;
}

Texture* createBlankTexture(int width, int height)
{
    Texture* texture = new Texture();
    texture->createBlank(width, height);
    return texture;
}

Text* createText(Font* font, const char* str)
{
    Text* text = new Text();
    text->render(font, str);
    return text;
}

void close()
{
    IMG_Quit();
}

} // namespace image
} // namespace lraspi