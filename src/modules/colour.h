/*
 * modules/colour.h - NEKERAFA - 26th january 2022
 * Defines colour object and utilities that will shared across the library
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#ifndef LRASPI_MODULES_COLOUR_H
#define LRASPI_MODULES_COLOUR_H

#include "raylib.h"
#include "../lraspi.h"

typedef struct lraspi_Colour {
    Color data;
} lraspi_Colour;

#endif // LRASPI_MODULES_COLOUR_H

