/**
 * lfont.cpp - NEKERAFA - 20th March 2021
 * Implements color module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <string>
#include "lua.hpp"
#include "lraspi.h"
#include "laux.h"
#include "lfont.h"

lraspi::font* lraspi::newfont(lua_State* L, std::string path, int size) {
	lraspi::font* font = (lraspi::font*)lua_newuserdata(L, sizeof(lraspi::font));
	new (font) lraspi::font(path, size);
	luaL_getmetatable(L, LRASPI_TFONT);
	lua_setmetatable(L, -2);
	return font;
}

static int font_new(lua_State* L) {
	const char* path = luaL_checkstring(L, 1);
	lua_Integer size = luaL_optinteger(L, 2, LRASPI_FONT_SIZE);
	lraspi::newfont(L, std::string(path), size);
	return 1;
}

static int font_free(lua_State* L) {
	lraspi::font* font = lraspi::check_object<lraspi::font>(L, 1);
	delete font;
	return 0;
}

static int font_set_default(lua_State* L) {
	lraspi::font* font = lraspi::check_object<lraspi::font>(L, 1);
	lraspi::fonts::default_font(font);
	return 0;
}

static int font_get_default(lua_State* L) {
	lraspi::font* font = lraspi::fonts::default_font();
	lraspi::push_object<lraspi::font>(L, font);
	return 1;
}

static const luaL_Reg font[] = {
	{"new", font_new},
	{"setdefault", font_set_default},
	{"getdefault", font_get_default},
	{"free", font_free},
	{NULL, NULL}
};

static const luaL_Reg font_methods[] = {
	{"__gc", font_free},
	{NULL, NULL}	
};

int luaopen_font(lua_State* L) {
	lraspi::new_object(L, LRASPI_TFONT, font_methods);
	luaL_newlib(L, font);
	return 1;
}

