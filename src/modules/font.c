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
#include "font.h"

lraspi_Font* current_font = NULL;

void lraspi_font_init() {
    lraspi_font_default = lraspi_font_new(LRASPI_FONT_FILE, LRASPI_FONT_SIZE * 2);
    current_font = lraspi_font_default;
}

void lraspi_font_close() {
    lraspi_font_free(lraspi_font_default);
}

bool lraspi_font_isdefault(lraspi_Font* font) {
    return font == lraspi_font_default;
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
    if (!lraspi_font_isdefault(font)) {
        UnloadFont(font->data);
        free(font);
    }
}

void lraspi_font_setdefault(lraspi_Font* font) {
    current_font = font == NULL ? lraspi_font_default : font;
}

lraspi_Font* lraspi_font_getdefault() {
    return current_font;
}

