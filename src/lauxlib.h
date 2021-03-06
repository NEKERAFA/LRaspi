/**
 * lauxlib.h - NEKERAFA - 28th february 2021
 * Defines auxiliary functions
 * 
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#ifndef LRASPI_AUX_LIBRARY_H
#define LRASPI_AUX_LIBRARY_H

#include <string>
#include <cstdint>
#include "lua.hpp"
#include "lraspi.h"

#define LRASPI_SCREENLIBNAME "screen"

#define LRASPI_TCOLOR "color"
#define LRASPI_TFONT "font"

namespace lraspi {
	void openlibs(lua_State* L);

	bool iscolor(lua_State* L, int index);
	
	void newcolor(lua_State* L, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	void pushcolor(lua_State* L, color* col);

	color* tocolor(lua_State* L, int index);

	color* optcolor(lua_State* L, int index, color* def);

	color* checkcolor(lua_State* L, int narg);

	bool isfont(lua_State* L, int index);

	void newfont(lua_State* L, std::string path, int size);

	void pushfont(lua_State* L, font* font);

	font* tofont(lua_State* L, int index);

	font* checkfont(lua_State* L, int narg);
}

#endif // LRASPI_AUX_LIBRARY_H
