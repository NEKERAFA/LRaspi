/*
    include/modules/color/color.h - NEKERAFA - 10th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <cstdint>

#include <SDL2/SDL_pixels.h>

#include "modules/common/type.h"
#include "modules/common/object.h"
#include "modules/color/color.h"

namespace lraspi
{

Type Color::type(LRASPI_COLOR_NAME, &Object::type);

Color::Color(uint8_t red, uint8_t green, uint8_t blue) : Color(red, green, blue, 255)
{}

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) : _red(red),
                                                                        _green(green),
                                                                        _blue(blue),
                                                                        _alpha(alpha)
{}

Color::~Color()
{}

uint8_t Color::red()
{
    return _red;
}

void Color::red(uint8_t red)
{
    _red = red;
}

float Color::rf()
{
    return ((float) _red) / 255.0f;
}

uint8_t Color::green()
{
    return _green;
}

void Color::green(uint8_t green)
{
    _green = green; 
}

float Color::gf()
{
    return ((float) _green) / 255.0f;
}

uint8_t Color::blue()
{
    return _blue;
}

void Color::blue(uint8_t blue)
{
    _blue = blue;
}

float Color::bf()
{
    return ((float) _blue) / 255.0f;
}

uint8_t Color::alpha()
{
    return _alpha;
}

void Color::alpha(uint8_t alpha)
{
    _alpha = alpha; 
}

float Color::af()
{
    return ((float) _alpha) / 255.0f;
}

SDL_Color Color::getSdlColor()
{
    return {_red, _green, _blue, _alpha};
}

bool Color::isInstanceOf(Type& other)
{
    return type.isInstanceOf(other);
}

const char* Color::name()
{
    return type.name();
}

} // namespace lraspi