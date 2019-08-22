/*
    include/lraspi/lscreen.h - NEKERAFA - 27th july 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_LUA_SCREEN_H
#define LRASPI_LUA_SCREEN_H

#include <lua.hpp>

extern "C" {

/**
 * @brief Loads the screen module
 * 
 * @param L A lua_State object
 */
int luaopen_screen(lua_State* L);

}

#endif // LRASPI_LUA_SCREEN_H