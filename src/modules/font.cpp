/**
 * font.cpp - NEKERAFA - 30th January 2021
 * Implements font class
 *
 * See "lraspi.h" for license notice
 */

#include "../external/raylib/src/raylib.h"
#include "../lraspi.h"

lraspi::font::font(const char* path) :
    _data(LoadFontEx(path, LRASPI_FONT_SIZE, 0, 0))
{ }

lraspi::font::~font() {
    UnloadFont(_data);
}

Font lraspi::font::data() {
    return _data;
}
