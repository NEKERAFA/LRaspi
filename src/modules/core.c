/*
 * modules/core.c - NEKERAFA - 1st november 2021
 * Implements common functions
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <stdbool.h>

#include "raylib.h"
#include "../lraspi.h"
#include "font.h"
#include "colour.h"

#ifndef NDEBUG
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#else
#define SCREEN_WIDTH GetMonitorWidth(0)
#define SCREEN_HEIGHT GetMonitorHeight(0)
#endif

void lraspi_init() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "LRaspi");
    lraspi_font_init();
    lraspi_colour_init();
}

bool lraspi_isclosing() {
    return WindowShouldClose();
}

void lraspi_close() {
    lraspi_font_close();
    lraspi_colour_init();
    CloseWindow();
}

