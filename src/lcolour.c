/*
 * lcolour.c - NEKERAFA - 7th january 2022
 * Implements colour module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <stdio.h>
#include <stdlib.h>
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
    lua_Colour lcolour = (lua_Colour)lua_newuserdata(L, sizeof(lua_Colour));
    *lcolour = colour;
    luaL_getmetatable(L, LRASPI_TCOLOUR);
    lua_setmetatable(L, -2);
}

lua_Colour lraspi_checkcolour(lua_State* L, int narg) {
    return (lua_Colour)luaL_checkudata(L, narg, LRASPI_TCOLOUR);
}

lua_Colour lraspi_optcolour(lua_State* L, int arg, lua_Colour d) {
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
    lua_Colour lcolour = lraspi_checkcolour(L, 1);
    lraspi_colour_free(*lcolour);
    *lcolour = NULL;
    return 0;
}

/**
 * Gets the red channel value.
 *
 * @function getredchannel
 * @param colour A colour object.
 */
static int lua_colour_getredchannel(lua_State* L) {
    lua_Colour lcolour = lraspi_checkcolour(L, 1);
    lua_Integer red = lraspi_colour_getredchannel(*lcolour);
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
    lua_Colour lcolour = lraspi_checkcolour(L, 1);
    lua_Integer red = lraspi_checkuint8(L, 2);
    lraspi_colour_setredchannel(*lcolour, red);
    return 0;
}

/**
 * Gets the green channel value.
 *
 * @function getgreenchannel
 * @param colour A colour object.
 */
static int lua_colour_getgreenchannel(lua_State* L) {
    lua_Colour lcolour = lraspi_checkcolour(L, 1);
    lua_Integer green = lraspi_colour_getgreenchannel(*lcolour);
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
    lua_Colour lcolour = lraspi_checkcolour(L, 1);
    lua_Integer green = lraspi_checkuint8(L, 2);
    lraspi_colour_setgreenchannel(*lcolour, green);
    return 0;
}

/**
 * Gets the blue channel value.
 *
 * @function getbluechannel
 * @param colour A colour object.
 */
static int lua_colour_getbluechannel(lua_State* L) {
    lua_Colour lcolour = lraspi_checkcolour(L, 1);
    lua_Integer blue = lraspi_colour_getbluechannel(*lcolour);
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
    lua_Colour lcolour = lraspi_checkcolour(L, 1);
    lua_Integer blue = lraspi_checkuint8(L, 2);
    lraspi_colour_setbluechannel(*lcolour, blue);
    return 0;
}

/**
 * Gets the alpha channel value.
 *
 * @function getalphachannel
 * @param colour A colour object.
 */
static int lua_colour_getalphachannel(lua_State* L) {
    lua_Colour lcolour = lraspi_checkcolour(L, 1);
    lua_Integer alpha = lraspi_colour_getalphachannel(*lcolour);
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
    lua_Colour lcolour = lraspi_checkcolour(L, 1);
    lua_Integer alpha = lraspi_checkuint8(L, 2);
    lraspi_colour_setalphachannel(*lcolour, alpha);
    return 0;
}

/**
 * Sets the default foreground colour.
 *
 * @function setforeground
 * @param[opt] colour The font object to set as default, nil to reset it.
*/
static int lua_colour_setforeground(lua_State* L) {
    lua_Colour lcolour = lraspi_optcolour(L, 1, NULL);
    lraspi_colour_setforeground(lcolour == NULL ? NULL : *lcolour);
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
    lua_Colour lcolour = lraspi_optcolour(L, 1, NULL);
    lraspi_colour_setbackground(lcolour == NULL ? NULL : *lcolour);
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

/**
 * Gets the string representation of the colour.
 *
 * @function tostring
 * @param colour A colour object.
 * @return String representation of the colour.
 */
static int lua_colour_tostring(lua_State* L) {
    lua_Colour lcolour = lraspi_checkcolour(L, 1);
    const char* colour_str = lraspi_colour_tostring(*lcolour);
    char* lcolour_str = malloc(sizeof(char) * 19);
    sprintf(lcolour_str, "colour: %s", colour_str);
    lua_pushstring(L, lcolour_str);
    free((char*)colour_str);
    free(lcolour_str);
    return 1;
}

// Lua module registry
static const struct luaL_Reg lua_colour_f[] = {
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
    {"tostring", lua_colour_tostring},
    {NULL, NULL}
};

// Lua metatable registry
static const struct luaL_Reg lua_colour_m[] = {
    {"free", lua_colour_free},
    {"setredchannel", lua_colour_setredchannel},
    {"getredchannel", lua_colour_getredchannel},
    {"setgreenchannel", lua_colour_setgreenchannel},
    {"getgreenchannel", lua_colour_getgreenchannel},
    {"setbluechannel", lua_colour_setbluechannel},
    {"getbluechannel", lua_colour_getbluechannel},
    {"setalphachannel", lua_colour_setalphachannel},
    {"getalphachannel", lua_colour_getalphachannel},
    {"__gc", lua_colour_free},
    {"__tostring", lua_colour_tostring},
    {NULL, NULL}
};

// Initialize module function

int luaopen_colour(lua_State* L) {
    lraspi_newobject(L, LRASPI_TCOLOUR, lua_colour_m);
    luaL_newlib(L, lua_colour_f);
    return 1;
}

