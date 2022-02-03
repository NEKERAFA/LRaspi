/*
 * modules/draw.c - NEKERAFA - 3rd february 2022
 * Functions to draw elements into images
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include "raylib.h"
#include "../lraspi.h"
#include "colour.h"
#include "font.h"
#include "image.h"

void lraspi_draw_print(const char* text, int x, int y) {
    lraspi_Font* font = lraspi_font_getdefault();
    lraspi_Colour* colour = lraspi_colour_getforeground();
    
    Vector2 raylib_pos = (Vector2) { (float) x, (float) y };

    DrawTextEx(font->data, text, raylib_pos, font->data.baseSize, 0, colour->data);
}

void lraspi_draw_blit(lraspi_Image* image, int x, int y) {
    lraspi_Colour* colour = lraspi_colour_getforeground();
    
    Rectangle source = (Rectangle) { 0.0, 0.0, (float) image->initialWidth, (float) image->initialHeight };
    
    Rectangle dest = (Rectangle) { (float) x, (float) y, (float) image->width, (float) image->height };
    if (image->hflip) {
        dest.x = dest.x + dest.width;
        dest.width = -dest.width;
    }
    if (image->vflip) {
        dest.y = dest.y + dest.height;
        dest.height = -dest.height;
    }

    Vector2 origin = (Vector2) { 0.0, 0.0 };

    DrawTexturePro(image->data, source, dest, origin, image->angle, colour->data);        
}

