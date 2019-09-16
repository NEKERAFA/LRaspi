/*
    include/lraspi/ltexture.h - NEKERAFA - 16th sep 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_TEXTURE_LUA_H
#define LRASPI_TEXTURE_LUA_H

#include <lua.hpp>

/***
 * This object represents a texture
 * @classmod texture
 */
extern "C" {

/***
 * Resets the internal values (rotation, flip, resize, ...) of the texture
 * @function texture.reset
 * @tparam texture texture A texture object
 */ 
int lraspi_texture_reset(lua_State* L);

/***
 * Changes the color modulation of the texture
 * @function texture.tint
 * @tparam texture texture A texture object
 * @tparam color color A color object
 */ 
int lraspi_texture_tint(lua_State* L);

/***
 * Gets the color modulation of the texture
 * @function texture.tintcolor
 * @tparam texture texture A texture object
 * @treturn color A color object
 */ 
int lraspi_texture_tint_color(lua_State* L);

/***
 * Changes the blend mode of the texture
 * @function texture.setblendmode
 * @tparam texture texture A texture object
 * @string mode The blend mode as the following values:
 * <ul>
 * <li><span class='parameter'>add</span> for additive blending</li>
 * <li><span class='parameter'>mod</span> for color modulation</li>
 * <li><span class='parameter'>blend</span> for alpha blending</li>
 * <li><span class='parameter'>none</span> for no blending</li>
 * </ul>
 */
int lraspi_texture_set_blend_mode(lua_State* L);

/***
 * Gets the current the blend mode of the texture
 * @function texture.getblendmode
 * @tparam texture texture A texture object
 * @ŧreturn string The blend mode as the following values:
 * <ul>
 * <li><span class='parameter'>add</span> for additive blending</li>
 * <li><span class='parameter'>mod</span> for color modulation</li>
 * <li><span class='parameter'>blend</span> for alpha blending</li>
 * <li><span class='parameter'>none</span> for no blending</li>
 * </ul>
 */
int lraspi_texture_get_blend_mode(lua_State* L);

/***
 * Changes the alpha value of the texture. <br>
 * The texture must have an blend mode established
 * @function texture.setalpha
 * @tparam texture texture A texture object
 * @int alpha The alpha value
 */
int lraspi_texture_set_alpha(lua_State* L);

/***
 * Gets the current alpha value of the texture. <br>
 * The texture must have an blend mode established
 * @function texture.getalpha
 * @tparam texture texture A texture object
 * @ŧreturn int The alpha value
 */
int lraspi_texture_get_alpha(lua_State* L);

/***
 * Gets the current width dimension of the texture
 * @function texture.getwidth
 * @tparam texture texture A texture object
 * @treturn int The current width dimension in pixels
 */
int lraspi_texture_get_width(lua_State* L);

/***
 * Gets the current height dimension of the texture
 * @function texture.getheight
 * @tparam texture texture A texture object
 * @treturn int The current height dimension in pixels
 */
int lraspi_texture_get_height(lua_State* L);

/***
 * Gets the real width dimension of the texture
 * @function texture.getrealwidth
 * @tparam texture texture A texture object
 * @treturn int The real width dimension in pixels
 */
int lraspi_texture_get_real_width(lua_State* L);

/***
 * Gets the real width dimension of the texture
 * @function texture.getrealheight
 * @tparam texture texture A texture object
 * @treturn int The real width dimension in pixels
 */
int lraspi_texture_get_real_height(lua_State* L);

/***
 * Resizes the texture
 * @function texture.resize
 * @tparam texture texture A texture object
 * @int width The new width dimension in pixels
 * @int height The new height dimension in pixels
 */
int lraspi_texture_resize(lua_State* L);

/***
 * Rotates the texture
 * @function texture.rotate
 * @tparam texture texture A texture object
 * @number angle The angle in degrees
 */
int lraspi_texture_rotate(lua_State* L);

/***
 * Sets the center of the texture
 * @function texture.setcenter
 * @tparam texture texture A texture object
 * @int x The x-axis position of the center
 * @int y The y-axis position of the center
 */
int lraspi_texture_set_center(lua_State* L);

/***
 * Gets the center of the texture
 * @function texture.getcenter
 * @tparam texture texture A texture object
 * @treturn int The x-axis position of the center
 * @treturn int The y-axis position of the center
 */
int lraspi_texture_get_center(lua_State* L);

/***
 * Flips a texture vertically
 * @tparam texture texture A texture object
 * @function texture.vflip
 */
int lraspi_texture_v_flip(lua_State* L);

/***
 * Flips a texture horizontally
 * @tparam texture texture A texture object
 * @function texture.hflip
 */
int lraspi_texture_h_flip(lua_State* L);

/***
 * Checks if the texture is flipped
 * @function texture.isflipped
 * @tparam texture texture A texture object
 * @treturn boolean true if the texture is flipped vertically
 * @treturn boolean true if the texture if flipped horizontally
 */
int lraspi_texture_is_flipped(lua_State* L);

/***
 * Changes the color of the pixel in the texture
 * @function texture.setpixel
 * @tparam texture texture A texture object
 * @int x The x-axis position of the pixel in the texture
 * @int y The y-axis position of the pixel in the texture
 * @tparam color color A color object
 */
int lraspi_texture_set_pixel(lua_State* L);

/***
 * Gets the color of the pixel in the texture
 * @function texture.getpixel
 * @tparam texture texture A texture object
 * @int x The x-axis position of the pixel in the texture
 * @int y The y-axis position of the pixel in the texture
 * @treturn color A color object
 */
int lraspi_texture_get_pixel(lua_State* L);

/***
 * Destroys a texture object
 * @function texture.free
 * @tparam texture texture A texture object
 */
int lraspi_texture_free(lua_State* L);

int luaopen_texture(lua_State* L);

}

#endif // LRASPI_TEXTURE_LUA_H