/*
 * lfont.c - NEKERAFA - 6th decembre 2021
 * Implements font module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <stdio.h>
#include <stdlib.h>

#include "lua.h"
#include "lauxlib.h"
#include "lraspi.h"
#include "laux.h"
#include "lfont.h"

// Wrappers

/**
 * Functions to loads font files and manipulate them
 *
 * @module font
 */

void lraspi_pushfont(lua_State* L, lraspi_Font* font) {
    lua_Font lfont = (lua_Font) lua_newuserdata(L, sizeof(lua_Font));
    *lfont = font;
    luaL_getmetatable(L, LRASPI_TFONT);
    lua_setmetatable(L, -2);
}

lua_Font lraspi_checkfont(lua_State* L, int narg) {
    return (lua_Font)luaL_checkudata(L, narg, LRASPI_TFONT);
}

lua_Font lraspi_optfont(lua_State* L, int arg, lua_Font d) {
    return luaL_opt(L, lraspi_checkfont, arg, d);
}

/**
 * Loads a font file.
 *
 * @function new
 * @param font_file Path of the font file.
 * @param[opt=12] size The size of glyphs.
 * @return New font object.
 */
static int lua_font_new(lua_State* L) {
    const char* font_file = luaL_checkstring(L, 1);
    lua_Number size = luaL_optnumber(L, 2, LRASPI_FONT_SIZE);
    lraspi_Font* font = lraspi_font_new(font_file, size);
    lraspi_pushfont(L, font);
    return 1;
}

/**
 * Releases a font from memory.
 *
 * @function free
 * @param font The font which wull be released.
 */
static int lua_font_free(lua_State* L) {
    lua_Font lfont = lraspi_checkfont(L, 1);
    lraspi_font_free(*lfont);
    *lfont = NULL;
    return 0;
}

/**
 * Sets the current default font.
 *
 * @function setdefault
 * @param[opt] font The font object to set as default, nil to reset it.
 */
static int lua_font_setdefault(lua_State* L) {
    lua_Font lfont = lraspi_optfont(L, 1, NULL);
    lraspi_font_setdefault(lfont == NULL ? NULL : *lfont);
    return 0;
}

/**
 * Gets the current default font.
 *
 * @function getdefault
 * @return A font object.
 */
static int lua_font_getdefault(lua_State* L) {
    lraspi_Font* font = lraspi_font_getdefault();
    lraspi_pushfont(L, font);
    return 1;
}

/**
 * Gets the string representation of the colour.
 *
 * @function tostring
 * @param colour A colour object.
 * @return String representation of the colour.
 */
static int lua_font_tostring(lua_State* L) {
    lua_Font lfont = lraspi_checkfont(L, 1);
    const char* font_str = lraspi_font_tostring(*lfont);
    char* lfont_str = malloc(sizeof(char) * 256);
    sprintf(lfont_str, "font: %s", font_str);
    lua_pushstring(L, lfont_str);
    free((char*)font_str);
    free(lfont_str);
    return 1;
}

// Lua module registry

static const struct luaL_Reg lua_font_f[] = {
    {"new", lua_font_new},
    {"free", lua_font_free},
    {"getdefault", lua_font_getdefault},
    {"setdefault", lua_font_setdefault},
    {"tostring", lua_font_tostring},
    {NULL, NULL}
};

// Lua metatable registry

static const struct luaL_Reg lua_font_m[] = {
    {"free", lua_font_free},
    {"__gc", lua_font_free},
    {"__tostring", lua_font_tostring},
    {NULL, NULL}
};

// Initialize module function

int luaopen_font(lua_State* L) {
    lraspi_newobject(L, LRASPI_TFONT, lua_font_m);
    luaL_newlib(L, lua_font_f);
    return 1;
}

