/*
 * modules/screen.c - NEKERAFA - 1st november 2021
 * Abstracts screen functions manipulation
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <stdlib.h>

#include "raylib.h"
#include "../lraspi.h"
#include "colour.h"
#include "image.h"

lraspi_Image* default_image = NULL;
RenderTexture2D render;

void lraspi_screen_setdefault(lraspi_Image* image) {
    if (default_image != NULL) {
        EndTextureMode();
        UnloadTexture(default_image->data);
        default_image->data = render.texture;
        UnloadRenderTexture(render);
    }

    if (image == NULL) {
        default_image = NULL;
    } else {
        default_image = image;
        render = LoadRenderTexture(image->initialWidth, image->initialHeight);
        BeginTextureMode(render);
        DrawTexture(image->data, 0, 0, WHITE);
    }
}

lraspi_Image* lraspi_screen_getdefault() {
    if (default_image != NULL) {
        EndTextureMode();
        UnloadTexture(default_image->data);
        default_image->data = render.texture;
        BeginTextureMode(render);
    }

    return default_image;
}

void lraspi_screen_clear() {
    if (default_image == NULL) {
        BeginDrawing();
    }

    lraspi_Colour* colour = lraspi_colour_getbackground();
    ClearBackground(colour->data);
}

void lraspi_screen_flip() {
    if (default_image == NULL) {
        EndDrawing();
    }
}

