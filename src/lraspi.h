/*
 * Lua Raspi 2022.1
 * 
 * A general-purpose Lua Player for Raspberry Pi single-board computer
 *
 * This software is under MIT License
 *
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * lraspi.h - NEKERAFA - 25th october 2021
 * API functions and types definition
 */

#ifndef LRASPI_LIBRARY_H
#define LRASPI_LIBRARY_H

#include <stdint.h>
#include <stdbool.h>

/** @file lraspi.h */

/** Gets the library version */
#define LRASPI_LIB_VERSION "1.0.0"

/** Gets the human-readable version */
#define LRASPI_VERSION "2022.1"

#define LRASPI_FONT_SIZE 12
#define LRASPI_FONT_FILE "OpenSans.ttf"

/**
 * @defgroup core Core functions
 * Common functionalities
 *
 * @{
 */

/**
 * @brief Initializes internal libraries and state.
 */
void lraspi_init();

/**
 * @brief Closes internal libraries and free internal state.
 */
void lraspi_close();

/**
 * @}
 *
 *
 * @defgroup colour Colour module
 * Funtions to create, convert and modify colours
 *
 * @{
 */

/** Represents a colour object. */
typedef struct lraspi_Colour lraspi_Colour;

/**
 * @brief Creates a new colour object.
 *
 * @param red The red channel value (0 - 255).
 * @param green The green channel value (0 - 255).
 * @param blue The blue channel value (0 - 255).
 * @param alpha The alpha channel value (0 - 255).
 */
lraspi_Colour* lraspi_colour_new(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

/**
 * @brief Releases the colour.
 *
 * @param colour The colour object which will be released.
 */
void lraspi_colour_free(lraspi_Colour* colour);

/**
 * @brief Gets the red channel value.
 *
 * @param colour A colour object.
 */
uint8_t lraspi_colour_getredchannel(lraspi_Colour* colour);

/**
 * @brief Sets the red channel value.
 *
 * @param colour A colour object.
 * @param red The new value.
 */
void lraspi_colour_setredchannel(lraspi_Colour* colour, uint8_t red);

/**
 * @brief Gets the green channel value.
 *
 * @param colour A colour object.
 */
uint8_t lraspi_colour_getgreenchannel(lraspi_Colour* colour);

/**
 * @brief Sets the green channel value.
 *
 * @param colour A colour object.
 * @param green The new value.
 */
void lraspi_colour_setgreenchannel(lraspi_Colour* colour, uint8_t green);

/**
 * @brief Gets the blue channel value.
 *
 * @param colour A colour object.
 */
uint8_t lraspi_colour_getbluechannel(lraspi_Colour* colour);

/**
 * @brief Sets the blue channel value.
 *
 * @param colour A colour object.
 * @param blue The new value.
 */
void lraspi_colour_setbluechannel(lraspi_Colour* colour, uint8_t blue);

/**
 * @brief Gets the alpha channel value.
 *
 * @param colour A colour object.
 */
uint8_t lraspi_colour_getalphachannel(lraspi_Colour* colour);

/**
 * @brief Sets the alpha channel value.
 *
 * @param colour A colour object.
 * @param alpha The new value.
 */
void lraspi_colour_setalphachannel(lraspi_Colour* colour, uint8_t alpha);

/**
 * @brief Sets the default foreground colour.
 *
 * @param colour A colour object. NULL to set the default foreground.
 */
void lraspi_colour_setforeground(lraspi_Colour* colour);

/**
 * @brief Gets the default foreground colour.
 *
 * @return Current foreground colour.
 */
lraspi_Colour* lraspi_colour_getforeground();

/**
 * @brief Sets the default foreground colour.
 *
 * @param colour A colour object. NULL to set the default foreground.
 */
void lraspi_colour_setbackground(lraspi_Colour* colour);

/**
 * @brief Gets the default background colour.
 *
 * @return Current background colour.
 */
lraspi_Colour* lraspi_colour_getbackground();

/**
 * @brief Gets the string representation of the colour.
 */
const char* lraspi_colour_tostring(lraspi_Colour* colour);

/**
 * @}
 * 
 * @defgroup image Image functions
 * Image loading and manipulation
 *
 * @{
 */

/** Represents a image object */
typedef struct lraspi_Image lraspi_Image;

/** Represents how the image will be scaled */
typedef enum {
    LRASPI_FILTER_NEAREST = 0, /** Scales without filter */
    LRASPI_FILTER_BILINEAR, /** Scales using a bilinear filtering */
    LRASPI_FILTER_TRILINEAR /** Scales using a trilinear filtering */
} lraspi_FilterMode;

/**
 * @brief Loads an image file onto the memory.
 *
 * @param image_file Path of the image file.
 * @return An image object.
 */
lraspi_Image* lraspi_image_new(const char* image_file);

/**
 * @brief Releases an image from memory.
 *
 * @param image The image which will be released.
 */
void lraspi_image_free(lraspi_Image* image);

/**
 * @brief Gets the current width (in pixels) of the image.
 *
 * @note If the image was modified, the returned value will be the value of the last modification. If you need the real one, you should use lraspi_image_getinitialwidth(lraspi_Image*).
 *
 * @param image An image object.
 */
int lraspi_image_getwidth(lraspi_Image* image);

/**
 * @brief Gets the width (in pixels) of the image.
 *
 * @param image An image object.
 */
int lraspi_image_getinitialwidth(lraspi_Image* image);

/**
 * @brief Gets the current height (in pixels) of the image.
 *
 * @param image An image object.
 */
int lraspi_image_getheight(lraspi_Image* image);

/**
 * @brief Gets the height (in pixels) of the image.
 *
 * @note If the image was modified, the returned value may change. If you need the real one, you should use lraspi_image_getinitialheight(lraspi_Image*).
 *
 * @param image An image object.
 */
int lraspi_image_getinitialheight(lraspi_Image* image);

/**
 * @brief Resizes the image.
 *
 * @param image An image object.
 * @param width The new width (in pixels).
 * @param height The new height (in pixels).
 */
void lraspi_image_resize(lraspi_Image* image, int height, int width);

/**
 * @brief Gets the rotation angle (in radians) of the image.
 *
 * @param image An image object.
 */
float lraspi_image_getrotation(lraspi_Image* image);

/**
 * @brief Rotates the image.
 *
 * @param image An image object.
 * @param angle The new value (in radians).
 */
void lraspi_image_rotate(lraspi_Image* image, float angle);

/**
 * @brief Checks if the image is vertically flipped.
 *
 * @param image An image object.
 * @return true if the image is vertically flipped, false otherwise.
 */
bool lraspi_image_isvflip(lraspi_Image* image);

/**
 * @brief Flips the image vertically.
 *
 * @param image An image object.
 * @param vflip True to flip the image vertically, false otherwise.
 */
void lraspi_image_vflip(lraspi_Image* image, bool vflip);

/**
 * @brief Checks if the image is horizontally flipped.
 *
 * @param image An image object.
 * @return true if the image is horizontally flipped, false otherwise.
 */
bool lraspi_image_ishflip(lraspi_Image* image);

/**
 * @brief Flips the image vertically.
 *
 * @param image An image object.
 * @param hflip True to flip the image horizontally, false otherwise.
 */
void lraspi_image_hflip(lraspi_Image* image, bool hflip);

/**
 * @brief Gets the image filter.
 *
 * @param image An image object.
 * @return The current filter of the image.
 */
lraspi_FilterMode lraspi_image_getfilter(lraspi_Image* image);

/**
 * @brief Sets the image filter.
 *
 * @param image An image object.
 * @param filter The filter to apply to the image.
 */
void lraspi_image_setfilter(lraspi_Image* image, lraspi_FilterMode filter);

/**
 * @brief Gets the colour pixel of the image.
 * 
 * @param image An image object.
 * @param x x-axis image position (in pixels).
 * @param y y-axis image position (in pixels).
 */
lraspi_Colour* lraspi_image_getpixel(lraspi_Image* image, int x, int y);

/**
 * @brief Sets the colour pixel of the image.
 * 
 * @param image An image object.
 * @param colour An colour object.
 * @param x x-axis image position (in pixels).
 * @param y y-axis image position (in pixels).
 */
void lraspi_image_setpixel(lraspi_Image* image, lraspi_Colour* colour, int x, int y);

/**
 * @brief Gets the string representation of the image.
 */
const char* lraspi_image_tostring(lraspi_Image* image);

/**
 * @}
 *
 *
 * @defgroup screen Screen module
 * Functions to manipulate screen.
 *
 * @{
 */

/**
 * @brief Checks if the program will be closed.
 *
 * @return true if the program will be close, false otherwise.
 */
bool lraspi_screen_isclosing();

/**
 * @brief Gets the width of the screen
 * 
 * @return int current screen width
 */
int lraspi_screen_getwidth();

/**
 * @brief Gets the height of the screen
 * 
 * @return int current screen height
 */
int lraspi_screen_getheight();

/**
 * @brief Gets the frames per second
 */
int lraspi_screen_getfps();

/**
 * @brief Sets the frames per second
 */
void lraspi_screen_setfps(int frame_per_seconds);

/**
 * @brief Gets the time in seconds since the last screen update
 */
float lraspi_screen_getdeltatime();

/**
 * @brief Clears the buffer using the default background colour and prepares the library to draw.
 */
void lraspi_screen_clear();

/**
 * @brief Sets the library to stop drawing and show the buffer onto the screen.
 */
void lraspi_screen_flip();

/**
 * @brief Sets the render target to a image object.
 * 
 * @note All draws will be rendered in the image object and not be shown on the screen.
 *
 * @param image An image object. Set NULL to restart drawing on screen.
 */
void lraspi_screen_setdefault(lraspi_Image* image);

/**
 * @brief Gets the current render image.
 *
 * @return image An image object.
 */
lraspi_Image* lraspi_screen_getdefault();

/**
 * @}
 *
 *
 * @defgroup draw Draw module
 * Functions to draw elements into images
 *
 * @{
 */

/**
 * @brief Draws a text with default font.
 *
 * @param text String to print.
 * @param x x-axis screen position (in pixels) where the text will be printed.
 * @param y y-axis screen position (in pixels) where the text will be printed.
 */
void lraspi_draw_print(const char* text, int x, int y);

/**
 * @brief Draws an image with default foreground colour.
 *
 * @param image The image object to draw.
 * @param x x-axis screen position (in pixels) where the image will be blited.
 * @param y y-axis screen position (in pixels) where the image will be blited.
 */
void lraspi_draw_blit(lraspi_Image* image, int x, int y);

/**
 * @}
 *
 *
 * @defgroup font Font module
 * Functions to loads font files and manipulate them.
 *
 * @{
 */

/** Represents a font object. */
typedef struct lraspi_Font lraspi_Font;

/**
 * @brief Loads a font file onto the memory.
 *
 * @param font_file Path of the font file.
 * @param size Size of the glyphs.
 * @return A font object.
 **/
lraspi_Font* lraspi_font_new(const char* font_file, int size);

/**
 * @brief Releases a font from memory.
 *
 * @param font The font which will be released.
 */
void lraspi_font_free(lraspi_Font* font);

/**
 * @brief Sets the current default font.
 *
 * @param font The font to set as default, NULL to reset it.
 */
void lraspi_font_setdefault(lraspi_Font* font);

/**
 * @brief Gets the current default font.
 *
 * @return A font object.
 */
lraspi_Font* lraspi_font_getdefault();

/**
 * @brief Gets the string representation of the image.
 */
const char* lraspi_font_tostring(lraspi_Font* font);

/**
 * @}
 */

#endif // LRASPI_LIBRARY_H

