/*
 * modules/colour.c - NEKERAFA - 4th january 2022
 * Abstracts colour manipulation
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <stdbool.h>
#include <stdlib.h>

#include "raylib.h"
#include "../lraspi.h"
#include "colour.h"

lraspi_Colour* current_foreground = NULL;
lraspi_Colour* current_background = NULL;

void lraspi_colour_init() {
    lraspi_colour_foreground = lraspi_colour_new(0, 0, 0, 255);
    current_foreground = lraspi_colour_foreground;
    lraspi_colour_background = lraspi_colour_new(255, 255, 255, 255);
    current_background = lraspi_colour_background;
}

void lraspi_colour_close() {
    lraspi_colour_free(lraspi_colour_foreground);
    lraspi_colour_free(lraspi_colour_background);
}

bool lraspi_colour_isdefault(lraspi_Colour* colour) {
    colour == lraspi_colour_foreground || colour == lraspi_colour_background;
}

lraspi_Colour* lraspi_colour_new(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
    lraspi_Colour* colour = (lraspi_Colour*)malloc(sizeof(lraspi_Colour));
    if (colour != NULL) {
        colour->data = (Color){ red, green, blue, alpha };
    }
    return colour;
}

void lraspi_colour_free(lraspi_Colour* colour) {
    if (!lraspi_colour_isdefault(colour))
    {
        free(colour);
    }
}

uint8_t lraspi_colour_getredchannel(lraspi_Colour* colour) {
    return colour->data.r;
}

void lraspi_colour_setredchannel(lraspi_Colour* colour, uint8_t red) {
    if (!lraspi_colour_isdefault(colour)) {
        colour->data.r = red;
    }
}

uint8_t lraspi_colour_getgreenchannel(lraspi_Colour* colour) {
    return colour->data.g;
}

void lraspi_colour_setgreenchannel(lraspi_Colour* colour, uint8_t green) {
    if (!lraspi_colour_isdefault(colour)) {
        colour->data.g = green;
    }
}

uint8_t lraspi_colour_getbluechannel(lraspi_Colour* colour) {
    return colour->data.b;
}

void lraspi_colour_setbluechannel(lraspi_Colour* colour, uint8_t blue) {
    if (!lraspi_colour_isdefault(colour)) {
        colour->data.b = blue;
    }
}

uint8_t lraspi_colour_getalphachannel(lraspi_Colour* colour) {
    return colour->data.a;
}

void lraspi_colour_setalphachannel(lraspi_Colour* colour, uint8_t alpha) {
    if (!lraspi_colour_isdefault(colour)) {
        colour->data.a = alpha;
    }
}

void lraspi_colour_setforeground(lraspi_Colour* colour) {
    current_foreground = colour == NULL ? lraspi_colour_foreground : colour;
}

lraspi_Colour* lraspi_colour_getforeground() {
    return current_foreground;
}

void lraspi_colour_setbackground(lraspi_Colour* colour) {
    current_background = colour == NULL ? lraspi_colour_background : colour;
}

lraspi_Colour* lraspi_colour_getbackground() {
    return current_background;
}

