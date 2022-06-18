/*
 * modules/image.c - NEKERAFA - 19th february 2022
 * Image loading and manipulation functions
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <stdlib.h>
#include <stdbool.h>

#include "raylib.h"
#include "../lraspi.h"
#include "image.h"

lraspi_Image* lraspi_image_new(const char* image_file) {
    lraspi_Image* image = (lraspi_Image*)malloc(sizeof(lraspi_Image));

    if (image != NULL) {
        image->data = LoadTexture(image_file);
        image->initial_width = image->data.width;
        image->width = image->initial_width;
        image->initial_height = image->data.height;
        image->height = image->initial_height;
        image->angle = 0.0;
        image->vertical_flip = false;
        image->horizontal_flip = false;
        GenTextureMipmaps(&(image->data));
        SetTextureFilter(image->data, TEXTURE_FILTER_BILINEAR);
        image->filter_mode = LRASPI_FILTER_BILINEAR;
    }

    return image;
}

void lraspi_image_free(lraspi_Image* image) {
    UnloadTexture(image->data);
    free(image);
}

int lraspi_image_getwidth(lraspi_Image* image) {
    return image->width;
}

int lraspi_image_getinitialwidth(lraspi_Image* image) {
    return image->initial_width;
}

int lraspi_image_getheight(lraspi_Image* image) {
    return image->height;
}

int lraspi_image_getinitialheight(lraspi_Image* image) {
    return image->initial_height;
}

void lraspi_image_resize(lraspi_Image* image, int height, int width) {
    image->height = height;
    image->width = width;
}

float lraspi_image_getrotation(lraspi_Image* image) {
    return image->angle;
}

void lraspi_image_rotate(lraspi_Image* image, float angle) {
    image->angle = angle;
}

bool lraspi_image_isvflip(lraspi_Image* image) {
    return image->vertical_flip;
}

void lraspi_image_vflip(lraspi_Image* image, bool vflip) {
    image->vertical_flip = vflip;
}

bool lraspi_image_ishflip(lraspi_Image* image) {
    return image->horizontal_flip;
}

void lraspi_image_hflip(lraspi_Image* image, bool hflip) {
    image->horizontal_flip = hflip;
}

lraspi_FilterMode lraspi_image_getfilter(lraspi_Image* image) {
    return image->filter_mode;
}

void lraspi_image_setfilter(lraspi_Image* image, lraspi_FilterMode filter) {
    SetTextureFilter(image->data, (TextureFilter)filter);
    image->filter_mode = filter;
}

