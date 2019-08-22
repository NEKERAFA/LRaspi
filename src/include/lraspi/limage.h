/*
    include/lraspi/limage.h - NEKERAFA - 30th july 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_IMAGE_LUA_H
#define LRASPI_IMAGE_LUA_H

#include <lua.hpp>

extern "C" {

/**
 * @brief Loads the image module
 * 
 * @param L A lua_State object
 */
int luaopen_image(lua_State* L);

}

#endif // LRASPI_IMAGE_LUA_H