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

/***
 * Create a new color
 * @function color.new
 * @number red The red channel value
 * @number blue The blue channel value
 * @number green The green channel value
 * @number[opt=0] alpha The alpha channel value
 * @treturn color A color object
 */

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

/***
 * Gets the red channel value of the color
 * @function color.red
 * @tparam color color A color object
 * @treturn number The red value
 */

/***
 * Sets the red channel value of the color
 * @function color.red
 * @tparam color color A color object
 * @number red The red value
 */

/***
 * Gets the green channel value of the color
 * @function color.green
 * @tparam color color A color object
 * @treturn number The green value
 */

/***
 * Sets the green channel value of the color
 * @function color.green
 * @tparam color color A color object
 * @number green The green value
 */

/***
 * Gets the blue channel value of the color
 * @function color.blue
 * @tparam color color A color object
 * @treturn number The blue value
 */

/***
 * Sets the blue channel value of the color
 * @function color.blue
 * @tparam color color A color object
 * @number blue The blue value
 */

/***
 * Gets the alpha channel value of the color
 * @function color.alpha
 * @tparam color color A color object
 * @treturn number The alpha value
 */

/***
 * Sets the alpha channel value of the color
 * @function color.alpha
 * @tparam color color A color object
 * @number alpha The alpha value
 */

/***
 * Destroys a color object
 * @function color.free
 * @tparam color color A color object to free
 */

extern "C" {

int luaopen_color(lua_State* L);

}

#endif // LRASPI_COLOR_LUA_H