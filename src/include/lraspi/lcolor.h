/*
    include/lraspi/lcolor.h - NEKERAFA - 12th aug 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_COLOR_LUA_H
#define LRASPI_COLOR_LUA_H

#include <lua.hpp>

/***
 * Color creation and manipulation
 * @module Color
 */
extern "C" {

/***
 * Create a new color
 * @function color.new
 * @int red The red channel value
 * @int blue The blue channel value
 * @int green The green channel value
 * @int[opt=0] alpha The alpha channel value
 * @treturn color A color object
 */
int lraspi_color_new(lua_State* L);


/***
 * Gets a list of 15 color to use.
 * @function color.getpalette
 * @treturn table A list with the following colors:
 * <ul>
 * <li>white (255, 255, 255)</li>
 * <li>black (0, 0, 0)</li>
 * <li>red (255, 0, 0)</li>
 * <li>green (0, 255, 0)</li>
 * <li>blue (0, 0, 255)</li>
 * <li>yellow (255, 255, 0)</li>
 * <li>cyan (0, 255, 255)</li>
 * <li>magenta (255, 0, 255)</li>
 * <li>marron (128, 0, 0)</li>
 * <li>grass (0, 128, 0)</li>
 * <li>navy (0, 0, 128)</li>
 * <li>olive (128, 128, 0)</li>
 * <li>turquoise (0, 128, 128)</li>
 * <li>violet (128, 0, 128)</li>
 * <li>gray (128, 128, 128)</li>
 * </ul>
 */
int lraspi_color_get_palette(lua_State* L);

/***
 * Gets the red channel value of the color
 * @function color.red
 * @tparam color color A color object
 * @treturn int The red value
 */

/***
 * Sets the red channel value of the color
 * @function color.red
 * @tparam color color A color object
 * @int red The red value
 */
int lraspi_color_red(lua_State* L);

/***
 * Gets the green channel value of the color
 * @function color.green
 * @tparam color color A color object
 * @treturn int The green value
 */

/***
 * Sets the green channel value of the color
 * @function color.green
 * @tparam color color A color object
 * @int green The green value
 */
int lraspi_color_green(lua_State* L);

/***
 * Gets the blue channel value of the color
 * @function color.blue
 * @tparam color color A color object
 * @treturn int The blue value
 */

/***
 * Sets the blue channel value of the color
 * @function color.blue
 * @tparam color color A color object
 * @int blue The blue value
 */
int lraspi_color_blue(lua_State* L);

/***
 * Gets the alpha channel value of the color
 * @function color.alpha
 * @tparam color color A color object
 * @treturn int The alpha value
 */

/***
 * Sets the alpha channel value of the color
 * @function color.alpha
 * @tparam color color A color object
 * @int alpha The alpha value
 */
int lraspi_color_alpha(lua_State* L);

int luaopen_color(lua_State* L);

/***
 * Destroys a color object
 * @function color.free
 * @tparam color color A color object to free
 */
int lraspi_color_free(lua_State* L);

}

#endif // LRASPI_COLOR_LUA_H