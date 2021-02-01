/**
 * screen.cpp - NEKERAFA - 30th january 2020
 * Screen manipulation implementation
 *
 * See "lraspi.h" for license information
 */

#include "../external/raylib/src/raylib.h"
#include "../lraspi.h"

bool screen_initialized = false;

void lraspi::screen::clear(lraspi::color32 color) {
    BeginDrawing();
    ClearBackground(color.data());
}

void lraspi::screen::flip() {
    EndDrawing();
}

