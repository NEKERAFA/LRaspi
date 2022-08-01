/*
 * limage.c - NEKERAFA - 16th june 2022
 * Implements image module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lua.h"
#include "lauxlib.h"
#include "lraspi.h"
#include "laux.h"
#include "limage.h"
#include "lcolour.h"

const char* const lraspi_filtermodes[] = {
    "nearest",
    "bilinear",
    "trilinear",
    NULL
};

// Wrappers

/**
 * Funtions to create, convert and modify images
 *
 * @module image
 */

void lraspi_pushimage(lua_State* L, lraspi_Image* image) {
    lua_Image limage = (lua_Image)lua_newuserdata(L, sizeof(lua_Image));
    *limage = image;
    luaL_getmetatable(L, LRASPI_TIMAGE);
    lua_setmetatable(L, -2);
}

lua_Image lraspi_checkimage(lua_State* L, int narg) {
    return (lua_Image)luaL_checkudata(L, narg, LRASPI_TIMAGE);
}

lua_Image lraspi_optimage(lua_State* L, int arg, lua_Image d) {
    return luaL_opt(L, lraspi_checkimage, arg, d);
}

/**
 * Loads an image file onto the GPU memory.
 *
 * @function new
 * @param image_file Path of the image file.
 * @return New image object.
 */
static int lua_image_new(lua_State* L) {
    const char* image_file = luaL_checkstring(L, 1);
    lraspi_Image* image = lraspi_image_new(image_file);
    lraspi_pushimage(L, image);
    return 1;
}

/**
 * Releases a image from memory.
 *
 * @function free
 * @param image The image which will be released.
 */
static int lua_image_free(lua_State* L) {
    lua_Image limage = lraspi_checkimage(L, 1);
    lraspi_image_free(*limage);
    *limage = NULL;
    return 0;
}

/**
 * Gets the current width (in pixels) of the image.
 *
 * If the image was modified, the returned value will be the value of the last modification. If you need the real one, you should use @{getinitialwidth}.
 *
 * @function getwidth
 * @param image An image object.
 * @return Current width value (in pixels).
 */
static int lua_image_getwidth(lua_State* L) {
    lua_Image limage = lraspi_checkimage(L, 1);
    lua_Integer width = lraspi_image_getwidth(*limage);
    lua_pushinteger(L, width);
    return 1;
}

/**
 * Gets the width (in pixels) of the image.
 *
 * @function getinitialwidth
 * @param image An image object.
 * @return Width value (in pixels).
 */
static int lua_image_getinitialwidth(lua_State* L) {
    lua_Image limage = lraspi_checkimage(L, 1);
    lua_Integer width = lraspi_image_getinitialwidth(*limage);
    lua_pushinteger(L, width);
    return 1;
}

/**
 * Gets the current height (in pixels) of the image.
 *
 * If the image was modified, the returned value will be the value of the last modification. If you need the real one, you should use @{getinitialheight}.
 *
 * @function getheight
 * @param image An image object.
 * @return Current height value (in pixels).
 */
static int lua_image_getheight(lua_State* L) {
    lua_Image limage = lraspi_checkimage(L, 1);
    lua_Integer height = lraspi_image_getheight(*limage);
    lua_pushinteger(L, height);
    return 1;
}

/**
 * Gets the height (in pixels) of the image.
 *
 * @function getinitialheight
 * @param image An image object.
 * @return Height value (in pixels).
 */
static int lua_image_getinitialheight(lua_State* L) {
    lua_Image limage = lraspi_checkimage(L, 1);
    lua_Integer height = lraspi_image_getinitialheight(*limage);
    lua_pushinteger(L, height);
    return 1;
}

/**
 * Resizes the image.
 *
 * @function resize
 * @param image An image object.
 * @param width The new width (in pixels).
 * @param height The new height (in pixels).
 */
static int lua_image_resize(lua_State* L) {
    lua_Image limage = lraspi_checkimage(L, 1);
    lua_Integer width = luaL_checkinteger(L, 2);
    lua_Integer height = luaL_checkinteger(L, 3);
    lraspi_image_resize(*limage, width, height);
    return 0;
}

/**
 * Gets the rotation angle (in radians) of the image.
 *
 * @function getrotation
 * @param image An image object.
 * @return Rotation angle value (in radians).
 */
static int lua_image_getrotation(lua_State* L) {
    lua_Image limage = lraspi_checkimage(L, 1);
    lua_Number angle = lraspi_image_getrotation(*limage);
    lua_pushnumber(L, angle);
    return 1;
}

/**
 * Rotates the image.
 *
 * @function rotate
 * @param image An image object.
 * @param angle The new value (in radians).
 */
static int lua_image_rotate(lua_State* L) {
    lua_Image limage = lraspi_checkimage(L, 1);
    lua_Number angle = luaL_checknumber(L, 2);
    lraspi_image_rotate(*limage, angle);
    return 1;
}

/**
 * Checks if the image is vertically flipped.
 *
 * @function isvflip
 * @param image An image object.
 * @return true if the image is vertically flipped, false otherwise.
 */
static int lua_image_isvflip(lua_State* L) {
    lua_Image limage = lraspi_checkimage(L, 1);
    bool vflip = lraspi_image_isvflip(*limage);
    lua_pushboolean(L, vflip);
    return 1;
}

/**
 * Flips the image vertically.
 *
 * @function vflip
 * @param image An image object.
 * @param vflip True to flip the image vertically, false otherwise.
 */
static int lua_image_vflip(lua_State* L) {
    lua_Image limage = lraspi_checkimage(L, 1);
    luaL_checktype(L, 2, LUA_TBOOLEAN);
    bool vflip = lua_toboolean(L, 2);
    lraspi_image_vflip(*limage, vflip);
    return 0;
}

/**
 * Checks if the image is horizontally flipped.
 *
 * @function ishflip
 * @param image An image object.
 * @return true if the image is horizontally flipped, false otherwise.
 */
static int lua_image_ishflip(lua_State* L) {
    lua_Image limage = lraspi_checkimage(L, 1);
    bool hflip = lraspi_image_ishflip(*limage);
    lua_pushboolean(L, hflip);
    return 1;
}

/**
 * Flips the image vertically.
 *
 * @function hflip
 * @param image An image object.
 * @param hflip True to flip the image horizontally, false otherwise.
 */
static int lua_image_hflip(lua_State* L) { 
    lua_Image limage = lraspi_checkimage(L, 1);
    luaL_checktype(L, 2, LUA_TBOOLEAN);
    bool hflip = lua_toboolean(L, 2);
    lraspi_image_hflip(*limage, hflip);
    return 0;
}

/**
 * Gets the image filter.
 *
 * @function getfilter
 * @param image An image object.
 * @return Current filter of the image.
 */
static int lua_image_getfilter(lua_State* L) {
    lua_Image limage = lraspi_checkimage(L, 1);
    lraspi_FilterMode filter = lraspi_image_getfilter(*limage);
    lua_pushstring(L, lraspi_filtermodes[filter]);
    return 1;
}

/**
 * Sets the image filter.
 *
 * @function setfilter
 * @param image An image object.
 * @param filter The filter to apply to the image.
 */
static int lua_image_setfilter(lua_State* L) {
    lua_Image limage = lraspi_checkimage(L, 1);
    lraspi_FilterMode filter = (lraspi_FilterMode)luaL_checkoption(L, 2, NULL, lraspi_filtermodes);
    lraspi_image_setfilter(*limage, filter);
    return 0;
}

/**
 * Gets the colour pixel of the image.
 * 
 * @function getpixel
 * @param image An image object.
 * @param x x-axis image position (in pixels).
 * @param y y-axis image position (in pixels).
 */
static int lua_image_getpixel(lua_State* L) {
    lua_Image limage = lraspi_checkimage(L, 1);
    lua_Integer x = luaL_checkinteger(L, 2);
    lua_Integer y = luaL_checkinteger(L, 3);
    lraspi_Colour* colour = lraspi_image_getpixel(*limage, x, y);
    lraspi_pushcolour(L, colour);
    return 1;
}

/**
 * Sets the colour pixel of the image.
 * 
 * @function setpixel
 * @param image An image object.
 * @param colour An colour object.
 * @param x x-axis image position (in pixels).
 * @param y y-axis image position (in pixels).
 */
static int lua_image_setpixel(lua_State* L) {
    lua_Image limage = lraspi_checkimage(L, 1);
    lua_Colour lcolour = lraspi_checkcolour(L, 2);
    lua_Integer x = luaL_checkinteger(L, 3);
    lua_Integer y = luaL_checkinteger(L, 4);
    lraspi_image_setpixel(*limage, *lcolour, x, y);
    return 0;
}

/**
 * Gets the string representation of the image.
 * 
 * @function tostring
 * @param image A image object.
 * @return String representation of the image.
 */
static int lua_image_tostring(lua_State* L) {
    lua_Image limage = lraspi_checkimage(L, 1);
    const char* image_str = lraspi_image_tostring(*limage);
    char* limage_str = malloc(sizeof(char) * 256);
    sprintf(limage_str, "image: %s", image_str);
    lua_pushstring(L, limage_str);
    free((char*)image_str);
    free(limage_str);
    return 1;
}

// Lua module registry

static const struct luaL_Reg lua_image[] = {
    {"new", lua_image_new},
    {"free", lua_image_free},
    {"getwidth", lua_image_getwidth},
    {"getinitialwidth", lua_image_getinitialwidth},
    {"getheight", lua_image_getheight},
    {"getinitialheight", lua_image_getinitialheight},
    {"resize", lua_image_resize},
    {"getrotation", lua_image_getrotation},
    {"rotate", lua_image_rotate},
    {"isvflip", lua_image_isvflip},
    {"vflip", lua_image_vflip},
    {"ishflip", lua_image_ishflip},
    {"hflip", lua_image_hflip},
    {"getfilter", lua_image_getfilter},
    {"setfilter", lua_image_setfilter},
    {"tostring", lua_image_tostring},
    {NULL, NULL}
};

// Lua metatable registry

static const struct luaL_Reg lua_image_mt[] = {
    {"free", lua_image_free},
    {"getwidth", lua_image_getwidth},
    {"getinitialwidth", lua_image_getinitialwidth},
    {"getheight", lua_image_getheight},
    {"getinitialheight", lua_image_getinitialheight},
    {"resize", lua_image_resize},
    {"getrotation", lua_image_getrotation},
    {"rotate", lua_image_rotate},
    {"isvflip", lua_image_isvflip},
    {"vflip", lua_image_vflip},
    {"ishflip", lua_image_ishflip},
    {"hflip", lua_image_hflip},
    {"getfilter", lua_image_getfilter},
    {"setfilter", lua_image_setfilter},
    {"__gc", lua_image_free},
    {"__tostring", lua_image_tostring},
    {NULL, NULL}
};

// Initialize module function
int luaopen_image(lua_State* L) {
    lraspi_newobject(L, LRASPI_TIMAGE, lua_image_mt);
    luaL_newlib(L, lua_image);
    return 1;
}

