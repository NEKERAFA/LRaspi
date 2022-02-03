/*
 * modules/core.c - NEKERAFA - 1st november 2021
 * Abstracts core functions
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <stdbool.h>

#include "raylib.h"
#include "../lraspi.h"

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
}

bool lraspi_isclosing() {
    return WindowShouldClose();
}

void lraspi_close() {
    lraspi_font_close();
    CloseWindow();
}

