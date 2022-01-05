/*
 * lscreen.c - NEKERAFA - 1st novembre 2021
 * Exports screen module onto Lua
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include "lua.h"
#include "lauxlib.h"
#include "lraspi.h"
#include "lscreen.h"

// Wrappers

/**
 * Functions to manipulate screen
 *
 * @module screen
 */

/**
 * Clears the buffer using the default background colour and prepares the library to draw
 *
 * @function clear
 */
static int lua_screen_clear(lua_State* L) {
    lraspi_screen_clear();
    return 0;
}

/**
 * Draws a text in a position using the default font and the foreground colour.
 *
 * @function print
 * @param text Text to print
 * @param x x-axis screen position (in pixels) where the text will be printed
 * @param y y-axis screen position (in pixels) where the text will be printed
 */
static int lua_screen_print(lua_State* L) {
    const char* text = luaL_checkstring(L, 1);
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3);

    lraspi_screen_print(text, x, y);
    
    return 0;
}

/**
 * Sets the library to stop drawing and show the buffer onto the screen.
 *
 * @function flip
 */
static int lua_screen_flip(lua_State* L) {
    lraspi_screen_flip();
    return 0;
}

// Lua registry

static const struct luaL_Reg lua_screen[] = {
    {"clear", lua_screen_clear},
    {"print", lua_screen_print},
    {"flip", lua_screen_flip},
    {NULL, NULL}
};

// Initialize module function

int luaopen_screen(lua_State* L) {
    luaL_newlib(L, lua_screen);
    return 1;
}

