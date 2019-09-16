/*
    include/lraspi/limage.h - NEKERAFA - 30th july 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_IMAGE_LUA_H
#define LRASPI_IMAGE_LUA_H

#include <lua.hpp>

/***
 * Image reading and manipulation and 2D accelerated rendering
 * @module Image
 */
extern "C" {

/***
 * Initializes the image subsystem.<br>
 * The interpreter calls this function internally, so you should not call explicitly.
 * @function image.init
 */
int lraspi_image_init(lua_State* L);

/***
 * Loads an image from the disk onto the memory
 * @function image.new
 * @string path The path of the image file
 * @treturn image A new image object
 */
int lraspi_image_new(lua_State* L);

/***
 * Closes the image subsystem.<br>
 * The interpreter calls this function internally, so you should not call explicitly.
 * @function image.close
 */
int lraspi_image_close(lua_State* L);

int luaopen_image(lua_State* L);

}

#endif // LRASPI_IMAGE_LUA_H