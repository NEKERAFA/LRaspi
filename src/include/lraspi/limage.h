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
 * @see Draw
 */

/***
 * Loads an image from the disk onto the memory
 * @function image.new
 * @string path The path of the image file
 * @treturn image A new image object
 */

/***
 * Creates new text
 * @function draw.newtext
 * @tparam font font A font object
 * @string text The text to render
 * @treturn text A new text objext
 */

extern "C" {

/***
 * Resets the internal values (rotation, flip, resize, ...) of the image
 * @function image.reset
 * @tparam image image A image object
 */
int lraspi_image_reset(lua_State* L);

/***
 * Changes the color modulation of the image
 * @function image.tint
 * @tparam image image A image object
 * @tparam color color A color object
 */
int lraspi_image_tint(lua_State* L);

/***
 * Gets the color modulation of the image
 * @function image.gettintcolor
 * @tparam image image A image object
 * @treturn color A color object
 */
int lraspi_image_tint_color(lua_State* L);

/***
 * Changes the alpha value of the image. <br>
 * The image must have an blend mode established
 * @function image.setalpha
 * @tparam image image A image object
 * @number alpha The alpha value
 */
int lraspi_image_set_alpha(lua_State* L);

/***
 * Gets the current alpha value of the image. <br>
 * The image must have an blend mode established
 * @function image.getalpha
 * @tparam image image A image object
 * @ŧreturn number The alpha value
 */
int lraspi_image_get_alpha(lua_State* L);

/***
 * Gets the current width dimension of the image
 * @function image.getwidth
 * @tparam image image A image object
 * @treturn number The current width dimension in pixels
 */
int lraspi_image_get_width(lua_State* L);

/***
 * Gets the current height dimension of the image
 * @function image.getheight
 * @tparam image image A image object
 * @treturn number The current height dimension in pixels
 */
int lraspi_image_get_height(lua_State* L);

/***
 * Gets the real width dimension of the image
 * @function image.getrealwidth
 * @tparam image image A image object
 * @treturn number The real width dimension in pixels
 */
int lraspi_image_get_real_width(lua_State* L);

/***
 * Gets the real width dimension of the image
 * @function image.getrealheight
 * @tparam image image A image object
 * @treturn number The real width dimension in pixels
 */
int lraspi_image_get_real_height(lua_State* L);

/***
 * Resizes the image
 * @function image.resize
 * @tparam image image A image object
 * @number width The new width dimension in pixels
 * @number height The new height dimension in pixels
 */
int lraspi_image_resize(lua_State* L);

/***
 * Rotates the image
 * @function image.rotate
 * @tparam image image A image object
 * @number angle The angle in degrees
 */
int lraspi_image_rotate(lua_State* L);

/***
 * Sets the center of the image
 * @function image.setcenter
 * @tparam image image A image object
 * @number x The x-axis position of the center
 * @number y The y-axis position of the center
 */
int lraspi_image_set_center(lua_State* L);

/***
 * Gets the center of the image
 * @function image.getcenter
 * @tparam image image A image object
 * @treturn number The x-axis position of the center
 * @treturn number The y-axis position of the center
 */
int lraspi_image_get_center(lua_State* L);

/***
 * Flips a image vertically
 * @tparam image image A image object
 * @function image.vflip
 */
int lraspi_image_v_flip(lua_State* L);

/***
 * Flips a image horizontally
 * @tparam image image A image object
 * @function image.hflip
 */
int lraspi_image_h_flip(lua_State* L);

/***
 * Checks if the image is flipped
 * @function image.isflipped
 * @tparam image image A image object
 * @treturn boolean true if the image is flipped vertically
 * @treturn boolean true if the image if flipped horizontally
 */
int lraspi_image_is_flipped(lua_State* L);

/***
 * Replaces the content of the text with a new value
 * @function image.settext
 * @tparam text text A text object
 * @string textstring The new content
 */
int lraspi_image_set_text(lua_State* L);

/***
 * Adds a new content to the rendered text
 * @function image.addtext
 * @tparam text text A text object
 * @string textstring The text to append
 */
int lraspi_image_add_text(lua_State* L);

/***
 * Clears the content of the rendered text
 * @function image.cleartext
 * @tparam text text A text object
 */
int lraspi_image_clear_text(lua_State* L);

/***
 * Destroys a image object
 * @function image.free
 * @tparam image image A image object
 */
int lraspi_image_free(lua_State* L);

int luaopen_image(lua_State* L);

}

#endif // LRASPI_IMAGE_LUA_H