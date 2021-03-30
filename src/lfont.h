/**
 * lfont.h - NEKERAFA - 20th march 2021
 * Defines font module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#ifndef LRASPI_FONT_MODULE_H
#define LRASPI_FONT_MODULE_H

#include <string>
#include "lua.hpp"

namespace lraspi {
	/**
	 * @brief Creates a font object
	 *
	 * @param L A Lua state
	 * @param path Path of the font file
	 * @param size Size of the glyphs
	 */
	font* newfont(lua_State* L, std::string path, int size);
}

int luaopen_font(lua_State* L);

#endif // LRASPI_FONT_MODULE_H
