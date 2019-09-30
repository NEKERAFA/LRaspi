/**
 * Lua Raspi 2019.0 (0.0.4)
 * Copyright (c) 2019 Rafael Alcalde Azpiazu
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
 * lraspi.h - NEKERAFA - 26th july 2019
 */

#ifndef LRASPI_H
#define LRASPI_H

#define LRASPI_VERSION "0.0.4"

#ifdef NDEBUG
#define LRASPI_RES_FOLDER "/usr/local/share/lraspi"
#else
#define LRASPI_RES_FOLDER "res"
#endif

#include <lua.hpp>

namespace lraspi
{

/**
 * @brief Loads all libraries
 * 
 * @param L An lua_State object
 * @return 0 if the libraries are loaded correctly
 */
int openlibs(lua_State* L);

/**
 * @brief Close all libraries
 * 
 * @param L An lua_State object
 */
void closelibs(lua_State* L);

} // namespace lraspi

#endif // LRASPI_H
