/*
    module/lraspi/lraspi.cc - NEKERAFA - 14th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <iostream>

#include <SDL2/SDL.h>
#include <lua.hpp>

#include "lraspi.h"
#include "lraspi/lauxlib.h"
#include "lraspi/lcolor.h"
#include "lraspi/lscreen.h"
#include "lraspi/limage.h"
#include "lraspi/lfont.h"

/***
 * Non specified functions
 * @module LRaspi
 */

namespace lraspi
{

/***
 * Gets the version number of Lua Raspi
 * @function _LRASPI_VERSION
 * 
 * @treturn string The version
 */
static int lraspi_version(lua_State* L)
{
    lua_pushliteral(L, LRASPI_VERSION);
    return 1;
}

int openlibs(lua_State* L)
{   
    // Loads image library
    luaL_requiref(L, "image", luaopen_image, 1);
    lua_getglobal(L, "image");
    lua_getfield(L, -1, "init");
    lua_remove(L, -2); 
    lua::call(L, 0, 0);

    // Loads font library
    luaL_requiref(L, "font", luaopen_font, 1);
    lua_getglobal(L, "font");
    lua_getfield(L, -1, "init");
    lua_remove(L, -2);
    lua::call(L, 0, 0);

    // Loads color library
    luaL_requiref(L, "color", luaopen_color, 1);

    // Loads screen library
    luaL_requiref(L, "screen", luaopen_screen, 1);
    lua_getglobal(L, "screen");
    lua_getfield(L, -1, "init");
    lua_remove(L, -2);
    lua::call(L, 0, 0);

    // Adds a function that returns the lraspi version
    lua_register(L, "lraspiversion", lraspi_version);

    return 0;
}

void closelibs(lua_State* L)
{
    lua_getglobal(L, "screen");
    lua_getfield(L, -1, "close");
    lua_remove(L, -2);
    lua::call(L, 0, 0);

    lua_getglobal(L, "font");
    lua_getfield(L, -1, "close");
    lua_remove(L, -2);
    lua::call(L, 0, 0);
    
    lua_getglobal(L, "image");
    lua_getfield(L, -1, "close");
    lua_remove(L, -2);
    lua::call(L, 0, 0);

    SDL_Quit();
}

} // namespace lraspi