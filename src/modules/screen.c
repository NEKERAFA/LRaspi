/*
 * modules/screen.c - NEKERAFA - 1st november 2021
 * Abstracts screen functions manipulation
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include "raylib.h"
#include "../lraspi.h"

void lraspi_screen_clear() {
    lraspi_Colour* colour = lraspi_colour_getbackground();
    Color raylib_color = *(Color*)lraspi_colour_getdata(colour);

    BeginDrawing();
    ClearBackground(raylib_color);
}

void lraspi_screen_print(const char* text, int x, int y) {
    lraspi_Font* font = lraspi_font_getdefault();
    Font raylib_font = *(Font*)lraspi_font_getdata(font);

    lraspi_Colour* colour = lraspi_colour_getforeground();
    Color raylib_color = *(Color*)lraspi_colour_getdata(colour);
    
    Vector2 raylib_pos = (Vector2) { (float) x, (float) y };

    DrawTextEx(raylib_font, text, raylib_pos, raylib_font.baseSize, 0, raylib_color);
}

void lraspi_screen_flip() {
    EndDrawing();
}

