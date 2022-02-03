/*
 * ldraw.c - NEKERAFA - 3rd february 2022
 * Implements draw module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include "lua.h"
#include "lauxlib.h"
#include "lraspi.h"

/**
 * Draws a text in a position using the default font and the foreground colour.
 *
 * @function print
 * @param text Text to print
 * @param x x-axis screen position (in pixels) where the text will be printed
 * @param y y-axis screen position (in pixels) where the text will be printed
 */
static int lua_draw_print(lua_State* L) {
    const char* text = luaL_checkstring(L, 1);
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3);

    lraspi_draw_print(text, x, y);
    
    return 0;
}

static const struct luaL_Reg lua_draw[] = {
    {"print", lua_draw_print},
    {NULL, NULL}
};

int luaopen_draw(lua_State* L) {
    luaL_newlib(L, lua_draw);
    return 1;
}
