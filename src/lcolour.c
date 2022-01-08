/*
 * lcolour.c - NEKERAFA - 7th january 2022
 * Implements colour module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <stdio.h>
#include <stdint.h>

#include "lua.h"
#include "lauxlib.h"
#include "lraspi.h"
#include "laux.h"
#include "lcolour.h"

// Wrappers

/**
 * Functions to create, convert and modify colours
 *
 * @module colour
 */

void lraspi_pushcolour(lua_State* L, lraspi_Colour* colour) {
    lua_pushlightuserdata(L, (void*)colour);
    luaL_getmetatable(L, LRASPI_TCOLOUR);
    lua_setmetatable(L, -2);
}

lraspi_Colour* lraspi_checkcolour(lua_State* L, int narg) {
    return (lraspi_Colour*)luaL_checkudata(L, narg, LRASPI_TCOLOUR);
}

lraspi_Colour* lraspi_optcolour(lua_State* L, int arg, lraspi_Colour* d) {
    return luaL_opt(L, lraspi_checkcolour, arg, d);
}

lua_Integer lraspi_checkuint8(lua_State* L, int arg) {
    lua_Integer num = luaL_checkinteger(L, arg);
    if (num < 0 || num > 255) {
        luaL_typeerror(L, arg, "uint8");
    }

    return num;
}

lua_Integer lraspi_optuint8(lua_State* L, int arg, uint8_t d) {
    return luaL_opt(L, lraspi_checkuint8, arg, d);
}

/**
 * Creates a new colour object.
 *
 * @function new
 * @param red The red channel value (0 - 255).
 * @param green The green channel value (0 - 255).
 * @param blue The blue channel value (0 - 255).
 * @param[opt=255] alpha The alpha channel value (0 - 255).
 */
static int lua_colour_new(lua_State* L) {
    lua_Integer red = lraspi_checkuint8(L, 1);
    lua_Integer green = lraspi_checkuint8(L, 2);
    lua_Integer blue = lraspi_checkuint8(L, 3);
    lua_Integer alpha = lraspi_optuint8(L, 4, 255);

    lraspi_Colour* colour = lraspi_colour_new(red, green, blue, alpha);
    lraspi_pushcolour(L, colour);

    return 1;
}

/**
 * Releases the colour.
 *
 * @function free
 * @param colour A colour object.
 */
static int lua_colour_free(lua_State* L) {
    lraspi_Colour* colour = lraspi_checkcolour(L, 1);
    lraspi_colour_free(colour);
    return 0;
}

/**
 * Gets the red channel value.
 *
 * @function getredchannel
 * @param colour A colour object.
 */
static int lua_colour_getredchannel(lua_State* L) {
    lraspi_Colour* colour = lraspi_checkcolour(L, 1);
    lua_Integer red = lraspi_colour_getredchannel(colour);
    lua_pushinteger(L, red);
    return 1;
}

/**
 * Sets the red channel value.
 *
 * @function setredchannel
 * @param colour A colour object.
 * @param red The new value.
 */
static int lua_colour_setredchannel(lua_State* L) {
    lraspi_Colour* colour = lraspi_checkcolour(L, 1);
    lua_Integer red = lraspi_checkuint8(L, 2);
    lraspi_colour_setredchannel(colour, red);
    return 0;
}

/**
 * Gets the green channel value.
 *
 * @function getgreenchannel
 * @param colour A colour object.
 */
static int lua_colour_getgreenchannel(lua_State* L) {
    lraspi_Colour* colour = lraspi_checkcolour(L, 1);
    lua_Integer green = lraspi_colour_getgreenchannel(colour);
    lua_pushinteger(L, green);
    return 1;
}

/**
 * Sets the green channel value.
 *
 * @function setgreenchannel
 * @param colour A colour object.
 * @param green The new value.
 */
static int lua_colour_setgreenchannel(lua_State* L) {
    lraspi_Colour* colour = lraspi_checkcolour(L, 1);
    lua_Integer green = lraspi_checkuint8(L, 2);
    lraspi_colour_setgreenchannel(colour, green);
    return 0;
}

/**
 * Gets the blue channel value.
 *
 * @function getbluechannel
 * @param colour A colour object.
 */
static int lua_colour_getbluechannel(lua_State* L) {
    lraspi_Colour* colour = lraspi_checkcolour(L, 1);
    lua_Integer blue = lraspi_colour_getbluechannel(colour);
    lua_pushinteger(L, blue);
    return 1;
}

/**
 * Sets the blue channel value.
 *
 * @function setbluechannel
 * @param colour A colour object.
 * @param blue The new value.
 */
static int lua_colour_setbluechannel(lua_State* L) {
    lraspi_Colour* colour = lraspi_checkcolour(L, 1);
    lua_Integer blue = lraspi_checkuint8(L, 2);
    lraspi_colour_setbluechannel(colour, blue);
    return 0;
}

/**
 * Gets the alpha channel value.
 *
 * @function getalphachannel
 * @param colour A colour object.
 */
static int lua_colour_getalphachannel(lua_State* L) {
    lraspi_Colour* colour = lraspi_checkcolour(L, 1);
    lua_Integer alpha = lraspi_colour_getalphachannel(colour);
    lua_pushinteger(L, alpha);
    return 1;
}

/**
 * Sets the alpha channel value.
 *
 * @function setalphachannel
 * @param colour A colour object.
 * @param alpha The new value.
 */
static int lua_colour_setalphachannel(lua_State* L) {
    lraspi_Colour* colour = lraspi_checkcolour(L, 1);
    lua_Integer alpha = lraspi_checkuint8(L, 2);
    lraspi_colour_setalphachannel(colour, alpha);
    return 0;
}

/**
 * Sets the default foreground colour.
 *
 * @function setforeground
 * @param[opt] colour The font object to set as default, nil to reset it.
*/
static int lua_colour_setforeground(lua_State* L) {
    lraspi_Colour* colour = lraspi_optcolour(L, 1, NULL);
    lraspi_colour_setforeground(colour);
    return 0;
}

/**
 * Gets the default foreground colour.
 *
 * @function getforeground
 * @return Current foreground colour.
 */
static int lua_colour_getforeground(lua_State* L) {
    lraspi_Colour* colour = lraspi_colour_getforeground();
    lraspi_pushcolour(L, colour);
    return 1;
}

/**
 * Sets the default foreground colour.
 *
 * @function setbackground
 * @param[opt] colour The font object to set as default, nil to reset it.
 */
static int lua_colour_setbackground(lua_State* L) {
    lraspi_Colour* colour = lraspi_optcolour(L, 1, NULL);
    lraspi_colour_setbackground(colour);
    return 0;
}

/**
 * Gets the default background colour.
 *
 * @function getbackground
 * @return Current background colour.
 */
static int lua_colour_getbackground(lua_State* L) {
    lraspi_Colour* colour = lraspi_colour_getbackground();
    lraspi_pushcolour(L, colour);
    return 1;
}


// Lua module registry
static const struct luaL_Reg lua_colour[] = {
    {"new", lua_colour_new},
    {"free", lua_colour_free},
    {"setredchannel", lua_colour_setredchannel},
    {"getredchannel", lua_colour_getredchannel},
    {"setgreenchannel", lua_colour_setgreenchannel},
    {"getgreenchannel", lua_colour_getgreenchannel},
    {"setbluechannel", lua_colour_setbluechannel},
    {"getbluechannel", lua_colour_getbluechannel},
    {"setalphachannel", lua_colour_setalphachannel},
    {"getalphachannel", lua_colour_getalphachannel},
    {"setforeground", lua_colour_setforeground},
    {"getforeground", lua_colour_getforeground},
    {"setbackground", lua_colour_setbackground},
    {"getbackground", lua_colour_getbackground},
    {NULL, NULL}
};

// Lua metatable registry
static const struct luaL_Reg lua_colour_mt[] = {
    {"free", lua_colour_free},
    {"setredchannel", lua_colour_setredchannel},
    {"getredchannel", lua_colour_getredchannel},
    {"setgreenchannel", lua_colour_setgreenchannel},
    {"getgreenchannel", lua_colour_getgreenchannel},
    {"setbluechannel", lua_colour_setbluechannel},
    {"getbluechannel", lua_colour_getbluechannel},
    {"setalphachannel", lua_colour_setalphachannel},
    {"getalphachannel", lua_colour_getalphachannel},
    {NULL, NULL}
};

// Initialize module function

int luaopen_colour(lua_State* L) {
    lraspi_newobject(L, LRASPI_TCOLOUR, lua_colour_mt);
    luaL_newlib(L, lua_colour);
    return 1;
}

