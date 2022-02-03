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
    int initialWidth;
    int width;
    int initialHeight;
    int height;
    float angle;
    bool vflip;
    bool hflip;
    lraspi_FilterMode filterMode;
} lraspi_Image;

#endif // LRASPI_MODULE_IMAGE_H

