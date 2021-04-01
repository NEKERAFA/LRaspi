/**
 * laux.cpp - NEKERAFA - 6th March 2021
 * Implements auxiliary lua functions
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <iostream>
#include "lua.hpp"
#include "lfs.h"
#include "lraspi.h"
#include "lcolor.h"
#include "lfont.h"
#include "lscreen.h"
#include "laux.h"

static const luaL_Reg lraspi_libs[] = {
	{LRASPI_COLORLIBNAME, luaopen_color},
	{LRASPI_FONTLIBNAME, luaopen_font},
	{LRASPI_SCREENLIBNAME, luaopen_screen},
	{LRASPI_FILESLIBNAME, luaopen_lfs},
	{NULL, NULL}
};

/* Based on luaL_openlibs code */
void lraspi::open_libraries(lua_State* L) {
	for (const luaL_Reg* lib = lraspi_libs; lib->func; lib++) {
		luaL_requiref(L, lib->name, lib->func, 1); /* loads lraspi lib */
		lua_pop(L, 1); /* removes lib from stack */
	}
}

static int printtraceback(lua_State* L) {
    const char* msg = lua_tostring(L, 1);
    luaL_traceback(L, L, msg, 0);
    std::cerr << "error: " << lua_tostring(L, -1) << std::endl;
    exit(EXIT_FAILURE);
    return 0;
}

void call(lua_State* L, int narg, int nres) {
    int base = lua_gettop(L) - narg;
    lua_pushcfunction(L, printtraceback);
    lua_insert(L, base);
    lua_pcall(L, narg, nres, base);
}

void lraspi::dofile(lua_State* L, const char* path) {
    if (luaL_loadfile(L, path) == LUA_OK) {
        call(L, 0, LUA_MULTRET);
    } else {
        std::cerr << "error: " << lua_tostring(L, -1) << std::endl;
    }
}

void lraspi::new_object(lua_State* L, std::string obj_name, const luaL_Reg methods[]) {
	if (luaL_newmetatable(L, obj_name.c_str())) { /* checks if the metatable is created */
		lua_pushvalue(L, -1); /* stack = { mtbl, mtbl } */
		lua_setfield(L, -2, "__index"); /* stack = { mtbl = {__index = mtbl}} */
		luaL_setfuncs(L, methods, 0); /* stack = {mtbl = {__index = mtbl, ...methods}} */
	}
}

