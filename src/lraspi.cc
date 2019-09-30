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
#include "lraspi/ldraw.h"
#include "lraspi/lfont.h"
#include "lraspi/limage.h"
#include "lraspi/lscreen.h"

#include "modules/image/module.h"
#include "modules/font/module.h"
#include "modules/screen/module.h"

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

    // Loads font library
    luaL_requiref(L, "font", luaopen_font, 1);

    // Loads color library
    luaL_requiref(L, "color", luaopen_color, 1);

    // Loads draw library
    luaL_requiref(L, "draw", luaopen_draw, 1);

    // Loads screen library
    luaL_requiref(L, "screen", luaopen_screen, 1);

    // Adds a function that returns the lraspi version
    lua_newtable(L);                            // stack = {{}}
    lua_pushcfunction(L, lraspi_version);       // stack = {{}, version}
    lua_setfield(L, -2, "version");             // stack = {{version}}
    lua_setglobal(L, "lraspi");                 // global = {lraspi = {version}}; stack = {}

    // Starts modules
    lraspi::font::init();
    lraspi::screen::init();
    lraspi::image::init();

    return 0;
}

void closelibs(lua_State* L)
{
    lraspi::image::close();
    lraspi::screen::close();
    lraspi::font::close();

    SDL_Quit();
}

} // namespace lraspi