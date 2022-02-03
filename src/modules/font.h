/*
 * modules/font.h - NEKERAFA - 26th january 2022
 * Defines font object and utilities that will shared across the library
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#ifndef LRASPI_MODULES_FONT_H
#define LRASPI_MODULES_FONT_H

#include "raylib.h"
#include "../lraspi.h"

typedef struct lraspi_Font {
    Font data;
} lraspi_Font;

#endif // LRASPI_MODULES_FONT_H

