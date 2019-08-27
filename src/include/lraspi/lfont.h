/*
    include/lraspi/lfont.h - NEKERAFA - 23th aug 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_FONT_LUA_H
#define LRASPI_FONT_LUA_H

#include <lua.hpp>

extern "C" {

/**
 * @brief Loads the font module
 * 
 * @param L A lua_State object
 */
int luaopen_font(lua_State* L);

}

#endif // LRASPI_FONT_LUA_H