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
 * Checks if the program will be closed.
 *
 * @function isclosing
 * @return true if the program will be close, false otherwise.
 */
static int lua_screen_isclosing(lua_State* L) {
    int is_closing = lraspi_screen_isclosing();
    lua_pushboolean(L, is_closing);
    return 1;
}

/**
 * Gets the width of the screen
 * 
 * @function getwidth
 * @return int current screen width
 */
static int lua_screen_getwidth(lua_State* L) {
    lua_Integer width = lraspi_screen_getwidth();
    lua_pushinteger(L, width);
    return 1;
}

/**
 * Gets the height of the screen
 * 
 * @function getheight
 * @return int current screen height
 */
static int lua_screen_getheight(lua_State* L) {
    lua_Integer height = lraspi_screen_getheight();
    lua_pushinteger(L, height);
    return 1;
}

/**
 * Gets the frames per second
 * 
 * @function getfps
 */
static int lua_screen_getfps(lua_State* L) {
    lua_Integer fps = lraspi_screen_getfps();
    lua_pushinteger(L, fps);
    return 1;
}

/**
 * Sets the frames per second
 *
 * @function setfps
 */
static int lua_screen_setfps(lua_State* L) {
    lua_Integer fps = luaL_checkinteger(L, 1);
    lraspi_screen_setfps(fps);
    return 0;
}

/**
 * Gets the time in seconds since the last screen update
 * 
 * @function getdeltatime
 */
static int lua_screen_getdeltatime(lua_State* L) {
    lua_Number delta_time = lraspi_screen_getdeltatime();
    lua_pushnumber(L, delta_time);
    return 0;
}

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
    {"isclosing", lua_screen_isclosing},
    {"getfps", lua_screen_getfps},
    {"setfps", lua_screen_setfps},
    {"getdeltatime", lua_screen_getdeltatime},
    {"getwidth", lua_screen_getwidth},
    {"getheight", lua_screen_getheight},
    {"clear", lua_screen_clear},
    {"flip", lua_screen_flip},
    {NULL, NULL}
};

// Initialize module function

int luaopen_screen(lua_State* L) {
    luaL_newlib(L, lua_screen);
    return 1;
}

