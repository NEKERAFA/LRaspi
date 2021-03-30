/**
 * lcolor.cpp - NEKERAFA - 14th March 2021
 * Implements color module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <cstdint>
#include "lua.hpp"
#include "lraspi.h"
#include "laux.h"
#include "lcolor.h"

lraspi::color* lraspi::newcolor(lua_State* L, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
	lraspi::color* color = (lraspi::color*)lua_newuserdata(L, sizeof(lraspi::color));
	new (color) lraspi::color(red, green, blue, alpha);
	luaL_getmetatable(L, LRASPI_TCOLOR);
	lua_setmetatable(L, -2);
	return color;
}

static int color_new(lua_State* L) {
	lua_Integer r = luaL_checkinteger(L, 1);
	lua_Integer g = luaL_checkinteger(L, 2);
	lua_Integer b = luaL_checkinteger(L, 3);
	lua_Integer a = luaL_optinteger(L, 4, 255);
	lraspi::newcolor(L, r, g, b, a);
	return 1;
}

static int color_red(lua_State* L) {
	lraspi::color* color = lraspi::check_object<lraspi::color>(L, 1);
	lua_pushinteger(L, color->red());
	return 1;
}

static int color_green(lua_State* L) {
	lraspi::color* color = lraspi::check_object<lraspi::color>(L, 1);
	lua_pushinteger(L, color->green());
	return 1;
}

static int color_blue(lua_State* L) {
	lraspi::color* color = lraspi::check_object<lraspi::color>(L, 1);
	lua_pushinteger(L, color->blue());
	return 1;
}

static int color_alpha(lua_State* L) {
	lraspi::color* color = lraspi::check_object<lraspi::color>(L, 1);
	lua_pushinteger(L, color->alpha());
	return 1;
}

static const luaL_Reg color[] = {
	{"new", color_new},
	{"red", color_red},
	{"green", color_green},
	{"blue", color_blue},
	{"alpha", color_alpha},
	{NULL, NULL}
};

static const luaL_Reg color_methods[] = {
	{"red", color_red},
	{"green", color_green},
	{"blue", color_blue},
	{"alpha", color_alpha},
	{NULL, NULL}
};

int luaopen_color(lua_State* L) {
	lraspi::new_object(L, LRASPI_TCOLOR, color_methods);
	luaL_newlib(L, color);
	return 1;
}
