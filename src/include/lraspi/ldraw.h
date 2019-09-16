/*
    include/lraspi/ldraw.h - NEKERAFA - 16th sep 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_DRAW_LUA_H
#define LRASPI_DRAW_LUA_H

#include <lua.hpp>

/***
 * 2D simple drawing rendering
 * @module Draw
 */
extern "C" {

/***
 * Creates new canvas
 * @function draw.newcanvas
 * @int width The width of the new canvas
 * @int height The height of the new canvas
 * @treturn canvas A new canvas objext
 */
int lraspi_draw_new_canvas(lua_State* L);

/***
 * Creates new text
 * @function draw.newtext
 * @tparam font font A font object
 * @string text The text to render
 * @treturn text A new text objext
 */
int lraspi_draw_new_text(lua_State* L);

int luaopen_draw(lua_State* L);

}

#endif // LRASPI_DRAW_LUA_H