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
 * lraspi.h - NEKERAFA - 29th january 2020
 * API functions and types definition
*/

#ifndef LRASPI_LIBRARY_H
#define LRASPI_LIBRARY_H

#include <cstdint>

#define LRASPI_VERSION "2022.1 (0.1.0)"

namespace lraspi {

    typedef struct Color {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    } Color;

    /**
     * @brief Initializes internal libraries
     */
    void init();

    /**
     * @brief Closes internal libraries and free internal state
     */
    void close();

    /**
     * @brief Clears the buffer and prepares the library to draw
     *
     * @param bg The background color
     */
    void screen_clear(Color color);

    /**
     * @brief End all draw functions and show the buffer
     */
    void screen_flip();

}

#endif // LRASPI_LIBRARY_H

