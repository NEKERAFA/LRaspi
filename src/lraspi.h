/**
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

#define LRASPI_LIB_VERSION "1.0.0"
#define LRASPI_VERSION "2022.1"

#define LRASPI_FONT_SIZE 12
#define LRASPI_FONT_FILE "OpenSans.ttf"

// --------------------------------
// Core module
// --------------------------------

/**
 * @brief Initializes internal libraries.
 */
void lraspi_init();

/**
 * @brief Closes internal libraries and free internal state.
 */
void lraspi_close();

/**
 * @brief Check if the window will be closed
 *
 * @return True of the window will be close, otherwise false.
 */
int lraspi_isclosing();

// --------------------------------
// Screen module
// --------------------------------

/**
 * @brief Clears the buffers and prepares the library to draw.
 */
void lraspi_screen_clear();

/**
 * @brief Draws a text with default font.
 *
 * @param text String to print
 * @param x x-axis screen position (in pixels) where the text will be printed
 * @param y y-axis screen position (in pixels) where the text will be printed
 */
void lraspi_screen_print(const char* text, int x, int y);

/**
 * @brief Sets the library to stop drawing and show the buffer onto the screen.
 *
 * @return True if the window will be closed, otherwise false.
 */
int lraspi_screen_flip();

// --------------------------------
// Font module
// --------------------------------

/**
 * @brief Represents a font object
 */
typedef struct lraspi_font lraspi_Font;

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
 * @brief Loads a font onte the memory.
 *
 * @param font_file Path of the font file
 * @param size Size of the glyphs
 **/
lraspi_Font* lraspi_font_new(const char* font_file, int size);

/**
 * @brief Releases the font.
 */
void lraspi_font_free(lraspi_Font* font);

/**
 * @brief Sets the current default font
 *
 * @param font The font to set as default, NULL to reset it.
 */
void lraspi_font_setdefault(lraspi_Font* font);

/**
 * @brief Gets the current default font.
 */
lraspi_Font* lraspi_font_getdefault();

#endif // LRASPI_LIBRARY_H

