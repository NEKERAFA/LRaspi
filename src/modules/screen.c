/*
 * modules/screen.c - NEKERAFA - 1st november 2021
 * Abstracts screen functions manipulation
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <stdbool.h>
#include <stdlib.h>

#include "raylib.h"
#include "../lraspi.h"
#include "screen.h"
#include "colour.h"
#include "image.h"

RenderTexture2D render;

void lraspi_screen_setdefault(lraspi_Image* image) {
    if (lraspi_screen_default != NULL) {
        EndTextureMode();
        UnloadTexture(lraspi_screen_default->data);
        lraspi_screen_default->data = render.texture;
        UnloadRenderTexture(render);
    }

    if (image == NULL) {
        lraspi_screen_default = NULL;
    } else {
        lraspi_screen_default = image;
        render = LoadRenderTexture(image->initialWidth, image->initialHeight);
        BeginTextureMode(render);
        DrawTexture(image->data, 0, 0, WHITE);
    }
}

lraspi_Image* lraspi_screen_getdefault() {
    if (lraspi_screen_default != NULL) {
        EndTextureMode();
        UnloadTexture(lraspi_screen_default->data);
        lraspi_screen_default->data = render.texture;
        BeginTextureMode(render);
    }

    return lraspi_screen_default;
}

void lraspi_screen_clear() {
    if (lraspi_screen_default == NULL) {
        BeginDrawing();
    }

    lraspi_Colour* colour = lraspi_colour_getbackground();
    ClearBackground(colour->data);
}

void lraspi_screen_flip() {
    if (lraspi_screen_default == NULL) {
        EndDrawing();
    }
}

