/**
 * lfont.c - NEKERAFA - 6th decembre 2021
 * Implements font module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include "lua.h"
#include "lauxlib.h"
#include "lraspi.h"
#include "laux.h"
#include "lfont.h"

/****************************
 * Wrappers
 ****************************/

void lraspi_pushfont(lua_State* L, lraspi_Font* font) {
    lua_pushlightuserdata(L, (void*)font);
    luaL_getmetatable(L, LRASPI_TFONT);
    lua_setmetatable(L, -2);
}

lraspi_Font* lraspi_checkfont(lua_State* L, int arg) {
    return (lraspi_Font*)luaL_checkudata(L, arg, LRASPI_TFONT);
}

lraspi_Font* lraspi_optfont(lua_State* L, int arg, lraspi_Font* d) {
    if (lua_isnoneornil(L, arg)) {
        return d;
    }

    return (lraspi_Font*)luaL_checkudata(L, arg, LRASPI_TFONT);
}

static int lua_font_new(lua_State* L) {
    const char* font_file = luaL_checkstring(L, 1);
    lua_Number size = luaL_optnumber(L, 2, LRASPI_FONT_SIZE);

    lraspi_Font* font = lraspi_font_new(font_file, size);
    lraspi_pushfont(L, font);

    return 0;
}

static int lua_font_free(lua_State* L) {
    lraspi_Font* font = lraspi_checkfont(L, 1);
    lraspi_font_free(font);
    return 0;
}

static int lua_font_getdefault(lua_State* L) {
    lraspi_Font* font = lraspi_font_getdefault();
    lraspi_pushfont(L, font);
    return 1;
}

static int lua_font_setdefault(lua_State* L) {
    lraspi_Font* font = lraspi_optfont(L, 1, NULL);
    lraspi_font_setdefault(font);

    return 0;
}

/****************************
 * Lua module registry
 ****************************/

static const struct luaL_Reg lua_font[] = {
    {"new", lua_font_new},
    {"free", lua_font_free},
    {"getdefault", lua_font_getdefault},
    {"setdefault", lua_font_setdefault},
    {NULL, NULL}
};

/****************************
 * Lua metatable registry
 ****************************/
static const struct luaL_Reg lua_font_mt[] = {
    {"free", lua_font_free},
    {NULL, NULL}
};

/****************************
 * Initialize module function
 ****************************/
int luaopen_font(lua_State* L) {
    lraspi_newobject(L, LRASPI_TFONT, lua_font_mt);
    luaL_newlib(L, lua_font);
    return 1;
}

