/**
 * lscreen.cpp - NEKERAFA - 28th february 2021
 * Implements screen module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include "lua.hpp"
#include "lraspi.h"
#include "lauxlib.h"
#include "lscreen.h"

static lraspi::color black(0, 0, 0, 255);
static lraspi::color white(255, 255, 255, 255);

static int screen_clear(lua_State* L) {
	lraspi::color* bg = lraspi::optcolor(L, 1, &black);
	lraspi::screen::clear(bg);
	return 0;
}

static int screen_print(lua_State* L) {
	const char* text = luaL_checkstring(L, 1);
	lua_Integer x = luaL_checkinteger(L, 2);
	lua_Integer y = luaL_checkinteger(L, 3);
	lraspi::color* fg = lraspi::optcolor(L, 4, &white);
	lraspi::screen::print(std::string(text), x, y, fg);
	return 0;
}

static int screen_flip(lua_State* L) {
	lraspi::screen::flip();
	return 0;
}

static const luaL_Reg screen [] = {
	{"clear", screen_clear},
	{"print", screen_print},
	{"flip", screen_flip},
	{NULL, NULL}
};

int luaopen_screen(lua_State* L) {
	luaL_newlib(L, screen);
	return 1;
}
