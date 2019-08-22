/*
    module/lraspi/lraspi.cc - NEKERAFA - 14th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <lua.hpp>

#include "lraspi.h"
#include "lraspi/lauxlib.h"
#include "lraspi/lcolor.h"
#include "lraspi/lscreen.h"
#include "lraspi/limage.h"

#define LRASPI_VERSION "0.0.1"

namespace lraspi
{

const char* version(lua_State* L)
{
    lua_pushliteral(L, LRASPI_VERSION);
    return LRASPI_VERSION;
}

static int lraspi_version(lua_State* L)
{
    version(L);
    return 1;
}

void openlibs(lua_State* L)
{
    // Loads screen library
    luaL_requiref(L, "screen", luaopen_screen, 1);
    lua_getglobal(L, "screen");
    lua_getfield(L, -1, "init");
    lua_remove(L, -2); 
    lua_call(L, 0, 0);
    
    // Loads image library
    luaL_requiref(L, "image", luaopen_image, 1);
    lua_getglobal(L, "image");
    lua_getfield(L, -1, "init");
    lua_remove(L, -2); 
    lua_call(L, 0, 0);
    
    // Loads color library
    luaL_requiref(L, "color", luaopen_color, 1);

    // Adds a function that returns the lraspi version
    lua_register(L, "version", lraspi_version);
}

} // namespace lraspi