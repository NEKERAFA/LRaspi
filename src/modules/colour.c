/*
 * modules/colour.c - NEKERAFA - 4th january 2022
 * Abstracts colour manipulation
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <stdlib.h>
#include <string.h>

#include "raylib.h"
#include "../lraspi.h"
#include "colour.h"

lraspi_Colour foreground_colour = { WHITE };
lraspi_Colour background_colour = { BLACK };
lraspi_Colour* current_foreground_colour = &foreground_colour;
lraspi_Colour* current_background_colour = &background_colour;

void* lraspi_colour_getdata(lraspi_Colour* colour) {
    return (void*)&colour->data;
}

lraspi_Colour* lraspi_colour_new(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
    lraspi_Colour* colour = (lraspi_Colour*)malloc(sizeof(lraspi_Colour));
    if (colour != NULL) {
        colour->data = (Color){ red, green, blue, alpha };
    }
    return colour;
}

void lraspi_colour_free(lraspi_Colour* colour) {
    free(colour);
}

uint8_t lraspi_colour_getredchannel(lraspi_Colour* colour) {
    return colour->data.r;
}

void lraspi_colour_setredchannel(lraspi_Colour* colour, uint8_t red) {
    colour->data.r = red;
}

uint8_t lraspi_colour_getgreenchannel(lraspi_Colour* colour) {
    return colour->data.g;
}

void lraspi_colour_setgreenchannel(lraspi_Colour* colour, uint8_t green) {
    colour->data.g = green;
}

uint8_t lraspi_colour_getbluechannel(lraspi_Colour* colour) {
    return colour->data.b;
}

void lraspi_colour_setbluechannel(lraspi_Colour* colour, uint8_t blue) {
    colour->data.b = blue;
}

uint8_t lraspi_colour_getalphachannel(lraspi_Colour* colour) {
    return colour->data.a;
}

void lraspi_colour_setalphachannel(lraspi_Colour* colour, uint8_t alpha) {
    colour->data.a = alpha;
}

void lraspi_colour_setforeground(lraspi_Colour* colour) {
    current_foreground_colour = colour == NULL ? &foreground_colour : colour;
}

lraspi_Colour* lraspi_colour_getforeground() {
    return current_foreground_colour;
}

void lraspi_colour_setbackground(lraspi_Colour* colour) {
    current_background_colour = colour == NULL ? &background_colour : colour;
}

lraspi_Colour* lraspi_colour_getbackground() {
    return current_background_colour;
}

