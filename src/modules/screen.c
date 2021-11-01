/**
 * modules/screen.c - NEKERAFA - 1st november 2021
 * Abstracts screen functions manipulation
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include "../external/raylib37/src/raylib.h"
#include "../lraspi.h"

void lraspi_screen_clear() {
    BeginDrawing();
    ClearBackground(BLACK);
}

void lraspi_screen_print(const char* text, int x, int y) {
    DrawText(text, x, y, 12, WHITE);
}

int lraspi_screen_flip() {
    if (WindowShouldClose()) {
        return 1;
    }

    EndDrawing();
    return 0;
}

