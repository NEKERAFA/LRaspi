/**
 * screen.cpp - NEKERAFA - 30th january 2020
 * Screen manipulation implementation
 *
 * See "lraspi.h" for license information
 */

#include <exception>
#include "../external/raylib/src/raylib.h"
#include "../lraspi.h"

void lraspi::screen::clear(lraspi::color* col) {
    BeginDrawing();
    ClearBackground(col->data());
}

void lraspi::screen::print(const char* text, lraspi::vector2* pos, lraspi::color* col) {
    DrawTextEx(lraspi::font::default_font()->data(), text, pos->data(), lraspi::font::default_font()->data().baseSize, 0, col->data());
}

void lraspi::screen::flip() {
    EndDrawing();
}

lraspi::vec2* lraspi::screen::get_dpi_scale() {
    Vector2 raylib_dpi = GetWindowSacleDPI();
    lraspi::vec2 dpi = new lraspi::vec2(raylib_dpi.x, raylib_dpi.y);
    return dpi;
}
