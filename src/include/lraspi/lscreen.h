/*
    include/lraspi/lscreen.h - NEKERAFA - 27th july 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_LUA_SCREEN_H
#define LRASPI_LUA_SCREEN_H

#include <lua.hpp>

/***
 * Screen management and information
 * @module Screen
 */

/***
 * Initializes the screen subsystem. The interpreter calls this function internally, so should not be used explicitly.
 * @function screen.init
 */

/***
 * Clears the screen with an specified color
 * @function screen.clear
 * @tparam color color A color object
 */

/***
 * Updates the screen and returns if the program was running
 * @function screen.update
 * @treturn boolean true if the program was running, false otherwise
 * @usage local quit = false 
 * while not quit do
 *    -- updating screen
 *    quit = screen.update()
 * end
 */

/***
 * Gets the current canvas
 * @function screen.getcanvas
 */

/***
 * Sets the render target to a canvas
 * @function screen.setcanvas
 * @tparam canvas A canvas object
 */

/***
 * Resets the render target to the screen
 * @function screen.setcanvas
 */

/***
 * Blits an texture onto the screen
 * @function screen.blit
 * @tparam texture texture A texture object to blit
 * @int x The x-axis position to draw the texture
 * @int y The y-axis position to draw the texture
 */

/***
 * Prints a text onto the screen
 * @function screen.print
 * @int x The x-axis position to draw the texture
 * @int y The y-axis position to draw the texture
 * @string textstring The text to print
 * @tparam color A color object
 */

/***
 * Gets the current default font to print in the screen
 * @function screen.getdefaultfont
 * @treturn font A font object
 */

/***
 * Sets a font as the current default font to print in the screen
 * @function screen.defaultfont
 * @tparam font font A font object
 */

/***
 * Gets the screen width
 * @function screen.getwidth
 * @treturn int The screen width dimension in pixels
 */

/***
 * Gets the screen height
 * @function screen.getheight
 * @treturn int The screen height dimension in pixels
 */

/***
 * Closes the screen subsystem. The interpreter calls this function internally, so should not be used explicitly.
 * @function screen.close
 */

extern "C" {

int luaopen_screen(lua_State* L);

}

#endif // LRASPI_LUA_SCREEN_H