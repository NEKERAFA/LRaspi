/*
    include/lraspi/lcanvas.h - NEKERAFA - 16th sep 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_CANVAS_LUA_H
#define LRASPI_CANVAS_LUA_H

#include <lua.hpp>

/***
 * This object represents a texture where you can draw but that will not be visible in the screen 
 * @classmod canvas
 * @see texture
 */
extern "C" {

int luaopen_canvas(lua_State* L);

}

#endif // LRASPI_CANVAS_LUA_H