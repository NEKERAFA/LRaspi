/*
 * modules/colour.h - NEKERAFA - 26th january 2022
 * Defines colour object and utilities that will shared across the library
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#ifndef LRASPI_MODULES_COLOUR_H
#define LRASPI_MODULES_COLOUR_H

#include <stdbool.h>

#include "raylib.h"
#include "../lraspi.h"

typedef struct lraspi_Colour {
    Color data;
} lraspi_Colour;

extern lraspi_Colour* lraspi_colour_foreground;
extern lraspi_Colour* lraspi_colour_background;

void lraspi_colour_init();
void lraspi_colour_close();

bool lraspi_colour_isdefault(lraspi_Colour* colour);

#endif // LRASPI_MODULES_COLOUR_H

