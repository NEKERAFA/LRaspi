/**
 * color.cpp - NEKERAFA - 1/2/2021
 * Implements color class
 *
 * See "lraspi.h" for license notice
 */

#include <cstdint>
#include "../external/raylib/src/raylib.h"
#include "../lraspi.h"

lraspi::color::color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) :
	_data((Color){ red, green, blue, alpha })
{ }

uint8_t lraspi::color::red() {
	return _data.r;
}

uint8_t lraspi::color::green() {
	return _data.g;
}

uint8_t lraspi::color::blue() {
	return _data.b;
}

uint8_t lraspi::color::alpha() {
	return _data.a;
}

Color& lraspi::color::data() {
	return _data;
}

