/*
 * modules/font.c - NEKERAFA - 10th november 2021
 * Abstracts font functions manipulation
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <stdlib.h>

#include "raylib.h"
#include "../lraspi.h"

typedef struct lraspi_Font {
    Font data;
} lraspi_Font;

lraspi_Font* default_font;
lraspi_Font* current_default_font;

void* lraspi_font_getdata(lraspi_Font* font) {
    return (void*)&font->data;
}

void lraspi_font_init() {
    default_font = lraspi_font_new(LRASPI_FONT_FILE, LRASPI_FONT_SIZE * 2);
    current_default_font = default_font;
}

void lraspi_font_close() {
    UnloadFont(default_font->data);
    free(default_font);
}

lraspi_Font* lraspi_font_new(const char* font_file, int size) {
    lraspi_Font* font = (lraspi_Font*)malloc(sizeof(lraspi_Font));
    if (font != NULL) {
        font->data = LoadFontEx(font_file, size, 0, 0);
        GenTextureMipmaps(&(font->data.texture));
        SetTextureFilter(font->data.texture, TEXTURE_FILTER_BILINEAR);
    }
    return font;
}

void lraspi_font_free(lraspi_Font* font) {
    if (font != default_font) {
        UnloadFont(font->data);
        free(font);
    }
}

void lraspi_font_setdefault(lraspi_Font* font) {
    current_default_font = font == NULL ? default_font : font;
}

lraspi_Font* lraspi_font_getdefault() {
    return current_default_font;
}

