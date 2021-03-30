/**
 * lcolor.h - NEKERAFA - 14th march 2021
 * Defines color module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#ifndef LRASPI_COLOR_MODULE_H
#define LRASPI_COLOR_MODULE_H

#include <cstdint>
#include "lua.hpp"

int luaopen_color(lua_State* L);

namespace lraspi {
	/**
	 * @brief Creates a color object in Lua
	 *
	 * @param L A Lua state
	 * @param red Red channel value
	 * @param green Green channel value
	 * @param blue Blue channel value
	 * @param alpha Alpha channel value
	 */
	color* newcolor(lua_State* L, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
}

#endif // LRASPI_COLOR_MODULE_H
