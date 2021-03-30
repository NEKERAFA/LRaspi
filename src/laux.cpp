/**
 * laux.cpp - NEKERAFA - 6th March 2021
 * Implements auxiliary lua functions
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include "lua.hpp"
#include "lraspi.h"
#include "lcolor.h"
#include "lfont.h"
#include "lscreen.h"
#include "laux.h"

static const luaL_Reg lraspi_libs[] = {
	{LRASPI_COLORLIBNAME, luaopen_color},
	{LRASPI_FONTLIBNAME, luaopen_font},
	{LRASPI_SCREENLIBNAME, luaopen_screen},
	{NULL, NULL}
};

/* Based on luaL_openlibs code */
void lraspi::open_libraries(lua_State* L) {
	for (const luaL_Reg* lib = lraspi_libs; lib->func; lib++) {
		luaL_requiref(L, lib->name, lib->func, 1); /* loads lraspi lib */
		lua_pop(L, 1); /* removes lib from stack */
	}
}

void lraspi::new_object(lua_State* L, std::string obj_name, const luaL_Reg methods[]) {
	if (luaL_newmetatable(L, obj_name.c_str())) { /* checks if the metatable is created */
		lua_pushvalue(L, -1); /* stack = { mtbl, mtbl } */
		lua_setfield(L, -2, "__index"); /* stack = { mtbl = {__index = mtbl}} */
		luaL_setfuncs(L, methods, 0); /* stack = {mtbl = {__index = mtbl, ...methods}} */
	}
}

