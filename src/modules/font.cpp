/**
 * font.cpp - NEKERAFA - 30th January 2021
 * Implements font class
 *
 * See "lraspi.h" for license notice
 */

#include "../external/raylib/src/raylib.h"
#include "../lraspi.h"

lraspi::font* _default_font;
lraspi::font* _current_font;

lraspi::font::font(const char* path, int size) :
    _data(LoadFontEx(path, size, 0, 0))
{ }

lraspi::font::~font() {
    UnloadFont(_data);
}

Font& lraspi::font::data() {
    return _data;
}

void lraspi::font::init() {
    _default_font = new lraspi::font("OpenSans.ttf", LRASPI_FONT_SIZE);
    _current_font = _default_font;
}

void lraspi::font::close() {
    delete _default_font;
}

lraspi::font* lraspi::font::default_font() {
    return _current_font;
}

void lraspi::font::default_font(font* font_obj) {
    _current_font = font_obj;
}
