/*
    include/lraspi/ltext.h - NEKERAFA - 16th sep 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_TEXT_LUA_H
#define LRASPI_TEXT_LUA_H

#include <lua.hpp>

/***
 * This object represents a rendered text
 * @classmod text
 * @see Draw
 */

/***
 * Sets the quality to render text
 * @function setquality
 * @tparam text text A text object
 * @string quality A string as the following values:
 * <ul>
 * <li><span class='parameter'>fast</span> for fast and not smooth text</li>
 * <li><span class='parameter'>normal</span> for slow and smooth text</li>
 * </ul>
 */

/***
 * Gets the quality to render text
 * @function getquality
 * @tparam text text A text object
 * @treturn string A string as the following values:
 * <ul>
 * <li><span class='parameter'>fast</span> for fast and not smooth text</li>
 * <li><span class='parameter'>normal</span> for slow and smooth text</li>
 * </ul>
 */

/***
 * Replaces the content of the text with a new value
 * @function set
 * @tparam text text A text object
 * @string textstring The new content
 */

/***
 * Adds a new content to the rendered text
 * @function add
 * @tparam text text A text object
 * @string textstring The text to append
 */

/***
 * Clears the content of the rendered text
 * @function clear
 * @tparam text text A text object
 */

/***
 * Resets the internal values (rotation, flip, resize, ...) of the image
 * @function reset
 * @tparam image image A image object
 */

/***
 * Changes the color modulation of the image
 * @function tint
 * @tparam image image A image object
 * @tparam color color A color object
 */

/***
 * Gets the color modulation of the image
 * @function tintcolor
 * @tparam image image A image object
 * @treturn color A color object
 */

/***
 * Changes the blend mode of the image
 * @function setblendmode
 * @tparam image image A image object
 * @string mode The blend mode as the following values:
 * <ul>
 * <li><span class='parameter'>add</span> for additive blending</li>
 * <li><span class='parameter'>mod</span> for color modulation</li>
 * <li><span class='parameter'>blend</span> for alpha blending</li>
 * <li><span class='parameter'>none</span> for no blending</li>
 * </ul>
 */

/***
 * Gets the current the blend mode of the image
 * @function getblendmode
 * @tparam image image A image object
 * @ŧreturn string The blend mode as the following values:
 * <ul>
 * <li><span class='parameter'>add</span> for additive blending</li>
 * <li><span class='parameter'>mod</span> for color modulation</li>
 * <li><span class='parameter'>blend</span> for alpha blending</li>
 * <li><span class='parameter'>none</span> for no blending</li>
 * </ul>
 */

/***
 * Changes the alpha value of the image. <br>
 * The image must have an blend mode established
 * @function setalpha
 * @tparam image image A image object
 * @int alpha The alpha value
 */

/***
 * Gets the current alpha value of the image. <br>
 * The image must have an blend mode established
 * @function getalpha
 * @tparam image image A image object
 * @ŧreturn int The alpha value
 */

/***
 * Gets the current width dimension of the image
 * @function getwidth
 * @tparam image image A image object
 * @treturn int The current width dimension in pixels
 */

/***
 * Gets the current height dimension of the image
 * @function getheight
 * @tparam image image A image object
 * @treturn int The current height dimension in pixels
 */

/***
 * Gets the real width dimension of the image
 * @function getrealwidth
 * @tparam image image A image object
 * @treturn int The real width dimension in pixels
 */

/***
 * Gets the real width dimension of the image
 * @function getrealheight
 * @tparam image image A image object
 * @treturn int The real width dimension in pixels
 */

/***
 * Resizes the image
 * @function resize
 * @tparam image image A image object
 * @int width The new width dimension in pixels
 * @int height The new height dimension in pixels
 */

/***
 * Rotates the image
 * @function rotate
 * @tparam image image A image object
 * @number angle The angle in degrees
 */

/***
 * Sets the center of the image
 * @function setcenter
 * @tparam image image A image object
 * @int x The x-axis position of the center
 * @int y The y-axis position of the center
 */

/***
 * Gets the center of the image
 * @function getcenter
 * @tparam image image A image object
 * @treturn int The x-axis position of the center
 * @treturn int The y-axis position of the center
 */

/***
 * Flips a image vertically
 * @tparam image image A image object
 * @function vflip
 */

/***
 * Flips a image horizontally
 * @tparam image image A image object
 * @function hflip
 */

/***
 * Checks if the image is flipped
 * @function isflipped
 * @tparam image image A image object
 * @treturn boolean true if the image is flipped vertically
 * @treturn boolean true if the image if flipped horizontally
 */

/***
 * Changes the color of the pixel in the image
 * @function setpixel
 * @tparam image image A image object
 * @int x The x-axis position of the pixel in the image
 * @int y The y-axis position of the pixel in the image
 * @tparam color color A color object
 */

/***
 * Gets the color of the pixel in the image
 * @function getpixel
 * @tparam image image A image object
 * @int x The x-axis position of the pixel in the image
 * @int y The y-axis position of the pixel in the image
 * @treturn color A color object
 */

/***
 * Destroys a image object
 * @function free
 * @tparam image image A image object
 */

extern "C" {

int luaopen_text(lua_State* L);

}

#endif // LRASPI_TEXT_LUA_H