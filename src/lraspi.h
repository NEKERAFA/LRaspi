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

#include <stdint.h>

#ifndef LRASPI_LIBRARY_H
#define LRASPI_LIBRARY_H

/** @file lraspi.h */

/** Gets the library version */
#define LRASPI_LIB_VERSION "1.0.0"

/** Gets the human-readable version */
#define LRASPI_VERSION "2022.1"

#define LRASPI_FONT_SIZE 12
#define LRASPI_FONT_FILE "OpenSans.ttf"

/**
 * @defgroup core Core functions
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
 * @brief Check if the window will be closed.
 *
 * @return True of the window will be close, otherwise false.
 */
int lraspi_isclosing();

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
 * @brief Clears the buffer using the default background colour and prepares the library to draw.
 */
void lraspi_screen_clear();

/**
 * @brief Draws a text with default font.
 *
 * @param text String to print.
 * @param x x-axis screen position (in pixels) where the text will be printed.
 * @param y y-axis screen position (in pixels) where the text will be printed.
 */
void lraspi_screen_print(const char* text, int x, int y);

/**
 * @brief Sets the library to stop drawing and show the buffer onto the screen.
 */
void lraspi_screen_flip();

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
 * @brief Gets the internal data of the font.
 *
 * @param font A font object.
 * @return A pointer to the internal data of the font.
 */
void* lraspi_font_getdata(lraspi_Font* font);

/**
 * @brief Loads the default font.
 */
void lraspi_font_init();

/**
 * @brief Releases default font.
 */
void lraspi_font_close();

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
 * @brief Gets the internal data of the colour.
 *
 * @param colour A colour object.
 * @return A pointer to the internal data of the colour.
 */
void* lraspi_colour_getdata(lraspi_Colour* colour);

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
 * @param colour A colour object.
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
 * @param colour A colour object.
 */
void lraspi_colour_setbackground(lraspi_Colour* colour);

/**
 * @brief Gets the default background colour.
 *
 * @return Current background colour.
 */
lraspi_Colour* lraspi_colour_getbackground();

/**
 * @}
 */

#endif // LRASPI_LIBRARY_H

