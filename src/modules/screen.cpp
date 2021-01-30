/**
 * screen.cpp - NEKERAFA - 30th january 2020
 * Screen manipulation implementation
 *
 * See "lraspi.h" for license information
 */

#include "../external/raylib/src/raylib.h"
#include "../include/lraspi.h"

bool screen_initialized = false;

void lraspi::screen_clear(lraspi::Color color) {
    ::Color rlib_color = { color.r, color.g, color.b, color.a };
    BeginDrawing();
    ClearBackground(rlib_color);
}

void lraspi::screen_flip() {
    EndDrawing();
}

