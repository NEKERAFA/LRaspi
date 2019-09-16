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
 * Initializes the image subsystem. <br>
 * The interpreter calls this function internally, so you should not call explicitly.
 * @function image.init
 */

/***
 * Loads an image from the disk onto the memory
 * @function image.new
 * @string path The path of the image file
 * @treturn image A new image object
 */

/***
 * Resets the internal values (rotation, flip, resize, ...) of the image
 * @function image.reset
 * @tparam image image A image object
 */

/***
 * Changes the color modulation of the image
 * @function image.tint
 * @tparam image image A image object
 * @tparam color color A color object
 */

/***
 * Gets the color modulation of the image
 * @function image.tintcolor
 * @tparam image image A image object
 * @treturn color A color object
 */

/***
 * Changes the blend mode of the image
 * @function image.setblendmode
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
 * @function image.getblendmode
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
 * @function image.setalpha
 * @tparam image image A image object
 * @int alpha The alpha value
 */

/***
 * Gets the current alpha value of the image. <br>
 * The image must have an blend mode established
 * @function image.getalpha
 * @tparam image image A image object
 * @ŧreturn int The alpha value
 */

/***
 * Gets the current width dimension of the image
 * @function image.getwidth
 * @tparam image image A image object
 * @treturn int The current width dimension in pixels
 */

/***
 * Gets the current height dimension of the image
 * @function image.getheight
 * @tparam image image A image object
 * @treturn int The current height dimension in pixels
 */

/***
 * Gets the real width dimension of the image
 * @function image.getrealwidth
 * @tparam image image A image object
 * @treturn int The real width dimension in pixels
 */

/***
 * Gets the real width dimension of the image
 * @function image.getrealheight
 * @tparam image image A image object
 * @treturn int The real width dimension in pixels
 */

/***
 * Resizes the image
 * @function image.resize
 * @tparam image image A image object
 * @int width The new width dimension in pixels
 * @int height The new height dimension in pixels
 */

/***
 * Rotates the image
 * @function image.rotate
 * @tparam image image A image object
 * @number angle The angle in degrees
 */

/***
 * Sets the center of the image
 * @function image.setcenter
 * @tparam image image A image object
 * @int x The x-axis position of the center
 * @int y The y-axis position of the center
 */

/***
 * Gets the center of the image
 * @function image.getcenter
 * @tparam image image A image object
 * @treturn int The x-axis position of the center
 * @treturn int The y-axis position of the center
 */

/***
 * Flips a image vertically
 * @tparam image image A image object
 * @function image.vflip
 */

/***
 * Flips a image horizontally
 * @tparam image image A image object
 * @function image.hflip
 */

/***
 * Checks if the image is flipped
 * @function image.isflipped
 * @tparam image image A image object
 * @treturn boolean true if the image is flipped vertically
 * @treturn boolean true if the image if flipped horizontally
 */

/***
 * Changes the color of the pixel in the image
 * @function image.setpixel
 * @tparam image image A image object
 * @int x The x-axis position of the pixel in the image
 * @int y The y-axis position of the pixel in the image
 * @tparam color color A color object
 */

/***
 * Gets the color of the pixel in the image
 * @function image.getpixel
 * @tparam image image A image object
 * @int x The x-axis position of the pixel in the image
 * @int y The y-axis position of the pixel in the image
 * @treturn color A color object
 */

/***
 * Destroys a image object
 * @function image.free
 * @tparam image image A image object
 */

/***
 * Closes the image subsystem. <br>
 * The interpreter calls this function internally, so you should not call explicitly.
 * @function image.close
 */

extern "C" {

int luaopen_image(lua_State* L);

}

#endif // LRASPI_IMAGE_LUA_H