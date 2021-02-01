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
#include "external/raylib/src/raylib.h"

#define LRASPI_VERSION "2022.1 (0.1.0)"

#define LRASPI_FONT_SIZE 32

namespace lraspi {

    // -------------------------------- 
    //  Types definition
    // -------------------------------- 

    /**
     * @brief Represents a color in RGBA 32 bits format 
     */
    class color32 {
    private:
        Color _data;

    public:
	/**
	 * @brief Creates a color object
	 *
	 * @param red Red channel value
	 * @param green Green channel value
	 * @param blue Blue channel value
	 * @param alpha Alpha channel value
	 */
        color32(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

	/**
	 * @brief gets data value
	 */
        Color data();
    };

    /**
     * @brief Represents a font object
     */
    class font {
    private:
        Font _data;

    public:
	/**
	 * @brief Loads a font onto memory
	 *
	 * @param path Path of the font file
	 */
        font(const char* font);

	/**
	 * @brief Releases the font
	 */
        ~font();

	/**
	 * @brief Gets internal data
	 */
	Font data();
    };

    // --------------------------------
    // Core funtion definitions
    // --------------------------------

    /**
     * @brief Initializes internal libraries
     */
    void init();

    /**
     * @brief Closes internal libraries and free internal state
     */
    void close();

    // --------------------------------
    // Screen function definitions
    // --------------------------------

    namespace screen {

        /**
         * @brief Clears the buffer and prepares the library to draw
         *
         * @param bg The background color
         */
        void clear(color32 color);

        /**
         * @brief End all draw functions and show the buffer
         */
        void flip();
    }

}

#endif // LRASPI_LIBRARY_H
