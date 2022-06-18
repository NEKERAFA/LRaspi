/*
 * modules/font.h - NEKERAFA - 26th january 2022
 * Defines font object and utilities that will shared across the library
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#ifndef LRASPI_MODULES_FONT_H
#define LRASPI_MODULES_FONT_H

#include <stdbool.h>

#include "raylib.h"
#include "../lraspi.h"

typedef struct lraspi_Font {
    Font data;
} lraspi_Font;

extern lraspi_Font* lraspi_font_default;

void lraspi_font_init();
void lraspi_font_close();

bool lraspi_font_isdefault(lraspi_Font* font);

#endif // LRASPI_MODULES_FONT_H

