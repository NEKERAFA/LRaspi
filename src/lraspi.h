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

#include <string>
#include <vector>
#include <cstdint>
#include <sys/stat.h>
#include "raylib.h"

#define LRASPI_VERSION "2022.1 (0.1.0)"

#define LRASPI_FONT_SIZE 24

#define LRASPI_TCOLOR "color"
#define LRASPI_TFONT "font"

namespace lraspi {
	// -------------------------------- 
	//  Types definition
	// -------------------------------- 

	/**
	 * @brief Represents a generic object
	 */
	template <class T>
	class object {
	public:
		object() {}
		virtual ~object() {}
		
		/**
		 * Gets the type of the object
		 */
		static std::string type() { return T::get_str_type(); }
	};

	/**
	 * @brief Represents a color in RGBA 32-bit format 
	 */
	class color: public object<color> {
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
		color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

		~color() {}

		/**
		 * @brief Gets red channel value
		 */
		uint8_t red();

		/**
		 * @brief Gets green channel value
		 */
		uint8_t green();

		/**
		 * @brief Gets blue channel value
		 */
		uint8_t blue();

		/**
		 * @brief Gets alpha channel value
		 */
		uint8_t alpha();

		/**
		 * @brief Gets internal data
		 */
		Color& data();

		static std::string get_str_type() { return LRASPI_TCOLOR; }
	};

	/**
	 * @brief Represents a font object
	 */
	class font: public object<font> {
	private:
		Font _data;

	public:
		/**
		 * @brief Loads a font onto memory
		 *
		 * @param path Path of the font file
		 * @param size Size of the glyphs
		 */
		font(std::string path, int size);

		/**
		 * @brief Releases the font
		 */
		~font();

		/**
		 * @brief Gets internal data
		 */
		Font& data();

		static std::string get_str_type() { return LRASPI_TFONT; }
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
	// Color function definitions
	// --------------------------------

	namespace colors {

	}

	// --------------------------------
	// Screen function definitions
	// --------------------------------

	namespace screen {
		/**
		 * @brief Clears the buffer and prepares the library to draw
		 *
		 * @param bg Color that will fill image buffer
		 */
		void clear(color* bg);

		/**
		 * @brief Draws a text with default font
		 *
		 * @param text String to print
		 * @param x x-axis screen position where the text will be printed
		 * @param y y-axis screen position where the text will be printed
		 * @param color Color that the text will be printed
		 */
		void print(std::string text, int x, int y, color* fg);

		/**
		 * @brief End all draw functions and show the buffer
		 */
		void flip();
	}

	// --------------------------------
	// Fonts function definitions
	// --------------------------------

	namespace fonts {
		/**
                 * @brief Loads default font
                 */
                void init();

                /**
                 * @brief Release def ault font
                 */
                void close();

                /**
                 * @brief Gets default font
                 */
                font* default_font();

                /**
                 * @brief Sets default font
                 */
                void default_font(font* font_obj);
	}

	// --------------------------------
	// USB devices function definitions
	// --------------------------------
	
	namespace usb {
		/**
		 * @brief Initializes device function
		 */
		void init();

		/**
		 * @brief List mount point devices
		 */
		std::vector<std::string> list();

		/**
		 * @brief Closes device function
		 */
		void close();
	}
}

#endif // LRASPI_LIBRARY_H

