/**
 * color.cpp - NEKERAFA - 1/2/2021
 * Implements color class
 *
 * See "lraspi.h" for license notice
 */

#include <cstdint>
#include "../external/raylib/src/raylib.h"
#include "../lraspi.h"

lraspi::color32::color32(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) :
    _data((Color){ red, green, blue, alpha })
{ }

Color& lraspi::color32::data() {
    return _data;
}

