/**
 * lauxlib.cpp - NEKERAFA - 6th March 2021
 * Implements auxiliary lua functions
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include "lua.hpp"
#include "lraspi.h"
#include "lscreen.h"
#include "lauxlib.h"

static const luaL_Reg lraspi_libs[] = {
	{LRASPI_SCREENLIBNAME, luaopen_screen},
	{NULL, NULL}
};

/* Based on luaL_openlibs code */
void lraspi::openlibs(lua_State* L) {
	for (const luaL_Reg* lib = lraspi_libs; lib->func; lib++) {
		luaL_requiref(L, lib->name, lib->func, 1); /* loads lraspi lib */
		lua_pop(L, 1); /* removes lib from stack */
	}
}

bool lraspi::iscolor(lua_State* L, int index) {
	void* ud = luaL_testudata(L, index, LRASPI_TCOLOR);
	return ud != NULL;
}

lraspi::color* lraspi::tocolor(lua_State* L, int index) {
	color* ud = (color*) luaL_testudata(L, index, LRASPI_TCOLOR);
	return ud;
}

lraspi::color* lraspi::optcolor(lua_State* L, int index, color* def) {
	color* ud = (color*) luaL_testudata(L, index, LRASPI_TCOLOR);
	return ud != NULL ? ud : def;
}
