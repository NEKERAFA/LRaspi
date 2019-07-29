/**
 * include/lraspi/lscreen.h - NEKERAFA - 27th july 2019
 * 
 * See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_SCREEN_LUA_H
#define LRASPI_SCREEN_LUA_H

#include <lua.hpp>

extern "C"{
    int luaopen_screen(lua_State* L);
}

#endif // LRASPI_SCREEN_LUA_H