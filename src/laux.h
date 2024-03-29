/*
 * laux.h - NEKERAFA - 1st november 2021
 * Auxiliary functions
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#ifndef LRASPI_AUX_H
#define LRASPI_AUX_H

#include "lua.h"
#include "lauxlib.h"

#define LRASPI_SCREENMODULE "screen"
#define LRASPI_FONTMODULE "font"
#define LRASPI_COLOURMODULE "colour"
#define LRASPI_DRAWMODULE "draw"
#define LRASPI_IMAGEMODULE "image"

#define LRASPI_TFONT "font"
#define LRASPI_TCOLOUR "colour"
#define LRASPI_TIMAGE "image"

/**
 * @file laux.h
 *
 * @defgroup lua_aux Lua functions
 * Functions to extends Lua.
 *
 * @{
 */

/**
 * @brief Opens default LRaspi libraries.
 *
 * @param L A Lua state.
 */
void lraspi_openlibs(lua_State* L);

/**
 * @brief Opens a lua file.
 *
 * @param L A Lua state.
 * @param path The path of the lua file.
 */
void lraspi_dofile(lua_State* L, const char* path);

/**
 * @brief Creates a new metatable that represents an object.
 *
 * @param L A Lua state.
 * @param objname The name of the object.
 * @param methods The methods that contains the object.
 */
void lraspi_newobject(lua_State* L, const char* objname, const luaL_Reg methods[]);

/**
 * @}
 */

#endif // LRASPI_AUX_H

