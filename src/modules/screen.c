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
    lraspi_Font* font = lraspi_font_getdefault();
    Font raylib_font = *(Font*)lraspi_font_getdata(font);
    DrawTextEx(raylib_font, text, (Vector2) {(float)x, (float)y}, raylib_font.baseSize, 0, WHITE);
}

int lraspi_screen_flip() {
    if (WindowShouldClose()) {
        return 1;
    }

    EndDrawing();
    return 0;
}

