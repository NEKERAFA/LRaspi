/*
 * modules/image.h - NEKERAFA - 26th january 2022
 * Defines image objects and utilities that will shared across the library
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#ifndef LRASPI_MODULES_IMAGE_H
#define LRASPI_MODULES_IMAGE_H

#include <stdbool.h>

#include "raylib.h"
#include "../lraspi.h"

typedef struct lraspi_Image {
    Texture2D data;
    int initial_width;
    int width;
    int initial_height;
    int height;
    float angle;
    bool vertical_flip;
    bool horizontal_flip;
    lraspi_FilterMode filter_mode;
} lraspi_Image;

#endif // LRASPI_MODULE_IMAGE_H

