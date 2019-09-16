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

/***
 * Creates new canvas
 * @function draw.newcanvas
 * @int width The width of the new canvas
 * @int height The height of the new canvas
 * @treturn canvas A new canvas objext
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
 * Resets the internal values (rotation, flip, resize, ...) of the texture
 * @function draw.reset
 * @tparam texture texture A texture object
 */
int lraspi_draw_reset(lua_State* L);

/***
 * Changes the color modulation of the texture
 * @function draw.tint
 * @tparam texture texture A texture object
 * @tparam color color A color object
 */
int lraspi_draw_tint(lua_State* L);

/***
 * Gets the color modulation of the texture
 * @function draw.tintcolor
 * @tparam texture texture A texture object
 * @treturn color A color object
 */
int lraspi_draw_tint_color(lua_State* L);

/***
 * Changes the blend mode of the texture
 * @function draw.setblendmode
 * @tparam texture texture A texture object
 * @string mode The blend mode as the following values:
 * <ul>
 * <li><span class='parameter'>add</span> for additive blending</li>
 * <li><span class='parameter'>mod</span> for color modulation</li>
 * <li><span class='parameter'>blend</span> for alpha blending</li>
 * <li><span class='parameter'>none</span> for no blending</li>
 * </ul>
 */
int lraspi_draw_set_blend_mode(lua_State* L);

/***
 * Gets the current the blend mode of the texture
 * @function draw.getblendmode
 * @tparam texture texture A texture object
 * @ŧreturn string The blend mode as the following values:
 * <ul>
 * <li><span class='parameter'>add</span> for additive blending</li>
 * <li><span class='parameter'>mod</span> for color modulation</li>
 * <li><span class='parameter'>blend</span> for alpha blending</li>
 * <li><span class='parameter'>none</span> for no blending</li>
 * </ul>
 */
int lraspi_draw_get_blend_mode(lua_State* L);

/***
 * Changes the alpha value of the texture. <br>
 * The texture must have an blend mode established
 * @function draw.setalpha
 * @tparam texture texture A texture object
 * @int alpha The alpha value
 */
int lraspi_draw_set_alpha(lua_State* L);

/***
 * Gets the current alpha value of the texture. <br>
 * The texture must have an blend mode established
 * @function draw.getalpha
 * @tparam texture texture A texture object
 * @ŧreturn int The alpha value
 */
int lraspi_draw_get_alpha(lua_State* L);

/***
 * Gets the current width dimension of the texture
 * @function draw.getwidth
 * @tparam texture texture A texture object
 * @treturn int The current width dimension in pixels
 */
int lraspi_draw_get_width(lua_State* L);

/***
 * Gets the current height dimension of the texture
 * @function draw.getheight
 * @tparam texture texture A texture object
 * @treturn int The current height dimension in pixels
 */
int lraspi_draw_get_height(lua_State* L);

/***
 * Gets the real width dimension of the texture
 * @function draw.getrealwidth
 * @tparam texture texture A texture object
 * @treturn int The real width dimension in pixels
 */
int lraspi_draw_get_real_width(lua_State* L);

/***
 * Gets the real width dimension of the texture
 * @function draw.getrealheight
 * @tparam texture texture A texture object
 * @treturn int The real width dimension in pixels
 */
int lraspi_draw_get_real_height(lua_State* L);

/***
 * Resizes the texture
 * @function draw.resize
 * @tparam texture texture A texture object
 * @int width The new width dimension in pixels
 * @int height The new height dimension in pixels
 */
int lraspi_draw_resize(lua_State* L);

/***
 * Rotates the texture
 * @function draw.rotate
 * @tparam texture texture A texture object
 * @number angle The angle in degrees
 */
int lraspi_draw_rotate(lua_State* L);

/***
 * Sets the center of the texture
 * @function draw.setcenter
 * @tparam texture texture A texture object
 * @int x The x-axis position of the center
 * @int y The y-axis position of the center
 */
int lraspi_draw_set_center(lua_State* L);

/***
 * Gets the center of the texture
 * @function draw.getcenter
 * @tparam texture texture A texture object
 * @treturn int The x-axis position of the center
 * @treturn int The y-axis position of the center
 */
int lraspi_draw_get_center(lua_State* L);

/***
 * Flips a texture vertically
 * @tparam texture texture A texture object
 * @function draw.vflip
 */
int lraspi_draw_v_flip(lua_State* L);

/***
 * Flips a texture horizontally
 * @tparam texture texture A texture object
 * @function draw.hflip
 */
int lraspi_draw_h_flip(lua_State* L);

/***
 * Checks if the texture is flipped
 * @function draw.isflipped
 * @tparam texture texture A texture object
 * @treturn boolean true if the texture is flipped vertically
 * @treturn boolean true if the texture if flipped horizontally
 */
int lraspi_draw_is_flipped(lua_State* L);

/***
 * Changes the color of the pixel in the texture
 * @function draw.setpixel
 * @tparam texture texture A texture object
 * @int x The x-axis position of the pixel in the texture
 * @int y The y-axis position of the pixel in the texture
 * @tparam color color A color object
 */
int lraspi_draw_set_pixel(lua_State* L);

/***
 * Gets the color of the pixel in the texture
 * @function draw.getpixel
 * @tparam texture texture A texture object
 * @int x The x-axis position of the pixel in the texture
 * @int y The y-axis position of the pixel in the texture
 * @treturn color A color object
 */
int lraspi_draw_get_pixel(lua_State* L);

/***
 * Sets the quality to render text
 * @function draw.setquality
 * @tparam text text A text object
 * @string quality A string as the following values:
 * <ul>
 * <li><span class='parameter'>fast</span> for fast and not smooth text</li>
 * <li><span class='parameter'>normal</span> for slow and smooth text</li>
 * </ul>
 */
int lraspi_draw_set_quality(lua_State* L);

/***
 * Gets the quality to render text
 * @function draw.getquality
 * @tparam text text A text object
 * @treturn string A string as the following values:
 * <ul>
 * <li><span class='parameter'>fast</span> for fast and not smooth text</li>
 * <li><span class='parameter'>normal</span> for slow and smooth text</li>
 * </ul>
 */
int lraspi_draw_get_quality(lua_State* L);

/***
 * Replaces the content of the text with a new value
 * @function draw.set
 * @tparam text text A text object
 * @string textstring The new content
 */
int lraspi_draw_set(lua_State* L);

/***
 * Adds a new content to the rendered text
 * @function draw.add
 * @tparam text text A text object
 * @string textstring The text to append
 */

int lraspi_draw_add(lua_State* L);

/***
 * Clears the content of the rendered text
 * @function draw.clear
 * @tparam text text A text object
 */
int lraspi_draw_clear(lua_State* L);

/***
 * Destroys a texture object
 * @function draw.free
 * @tparam texture texture A texture object
 */
int lraspi_draw_free(lua_State* L);

int luaopen_draw(lua_State* L);

}

#endif // LRASPI_DRAW_LUA_H