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
 * @see Draw
 */

/***
 * Resets the internal values (rotation, flip, resize, ...) of the canvas
 * @function reset
 * @tparam canvas canvas A canvas object
 */

/***
 * Changes the color modulation of the canvas
 * @function tint
 * @tparam canvas canvas A canvas object
 * @tparam color color A color object
 */

/***
 * Gets the color modulation of the canvas
 * @function tintcolor
 * @tparam canvas canvas A canvas object
 * @treturn color A color object
 */

/***
 * Changes the blend mode of the canvas
 * @function setblendmode
 * @tparam canvas canvas A canvas object
 * @string mode The blend mode as the following values:
 * <ul>
 * <li><span class='parameter'>add</span> for additive blending</li>
 * <li><span class='parameter'>mod</span> for color modulation</li>
 * <li><span class='parameter'>blend</span> for alpha blending</li>
 * <li><span class='parameter'>none</span> for no blending</li>
 * </ul>
 */

/***
 * Gets the current the blend mode of the canvas
 * @function getblendmode
 * @tparam canvas canvas A canvas object
 * @ŧreturn string The blend mode as the following values:
 * <ul>
 * <li><span class='parameter'>add</span> for additive blending</li>
 * <li><span class='parameter'>mod</span> for color modulation</li>
 * <li><span class='parameter'>blend</span> for alpha blending</li>
 * <li><span class='parameter'>none</span> for no blending</li>
 * </ul>
 */

/***
 * Changes the alpha value of the canvas. <br>
 * The canvas must have an blend mode established
 * @function setalpha
 * @tparam canvas canvas A canvas object
 * @int alpha The alpha value
 */

/***
 * Gets the current alpha value of the canvas. <br>
 * The canvas must have an blend mode established
 * @function getalpha
 * @tparam canvas canvas A canvas object
 * @ŧreturn int The alpha value
 */

/***
 * Gets the current width dimension of the canvas
 * @function getwidth
 * @tparam canvas canvas A canvas object
 * @treturn int The current width dimension in pixels
 */

/***
 * Gets the current height dimension of the canvas
 * @function getheight
 * @tparam canvas canvas A canvas object
 * @treturn int The current height dimension in pixels
 */

/***
 * Gets the real width dimension of the canvas
 * @function getrealwidth
 * @tparam canvas canvas A canvas object
 * @treturn int The real width dimension in pixels
 */

/***
 * Gets the real width dimension of the canvas
 * @function getrealheight
 * @tparam canvas canvas A canvas object
 * @treturn int The real width dimension in pixels
 */

/***
 * Resizes the canvas
 * @function resize
 * @tparam canvas canvas A canvas object
 * @int width The new width dimension in pixels
 * @int height The new height dimension in pixels
 */

/***
 * Rotates the canvas
 * @function rotate
 * @tparam canvas canvas A canvas object
 * @number angle The angle in degrees
 */

/***
 * Sets the center of the canvas
 * @function setcenter
 * @tparam canvas canvas A canvas object
 * @int x The x-axis position of the center
 * @int y The y-axis position of the center
 */

/***
 * Gets the center of the canvas
 * @function getcenter
 * @tparam canvas canvas A canvas object
 * @treturn int The x-axis position of the center
 * @treturn int The y-axis position of the center
 */

/***
 * Flips a canvas vertically
 * @tparam canvas canvas A canvas object
 * @function vflip
 */

/***
 * Flips a canvas horizontally
 * @tparam canvas canvas A canvas object
 * @function hflip
 */

/***
 * Checks if the canvas is flipped
 * @function isflipped
 * @tparam canvas canvas A canvas object
 * @treturn boolean true if the canvas is flipped vertically
 * @treturn boolean true if the canvas if flipped horizontally
 */

/***
 * Changes the color of the pixel in the canvas
 * @function setpixel
 * @tparam canvas canvas A canvas object
 * @int x The x-axis position of the pixel in the canvas
 * @int y The y-axis position of the pixel in the canvas
 * @tparam color color A color object
 */

/***
 * Gets the color of the pixel in the canvas
 * @function getpixel
 * @tparam canvas canvas A canvas object
 * @int x The x-axis position of the pixel in the canvas
 * @int y The y-axis position of the pixel in the canvas
 * @treturn color A color object
 */

/***
 * Destroys a canvas object
 * @function free
 * @tparam canvas canvas A canvas object
 */

extern "C" {

int luaopen_canvas(lua_State* L);

}

#endif // LRASPI_CANVAS_LUA_H