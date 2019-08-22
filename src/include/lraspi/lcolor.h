/*
    include/lraspi/lcolor.h - NEKERAFA - 12th aug 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_COLOR_LUA_H
#define LRASPI_COLOR_LUA_H

#include <lua.hpp>

extern "C" {

/**
 * @brief Loads the color module
 * 
 * @param L A lua_State object
 */
int luaopen_color(lua_State* L);

}

#endif // LRASPI_COLOR_LUA_H