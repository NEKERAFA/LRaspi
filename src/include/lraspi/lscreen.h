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
 * Blits an texture onto the screen
 * @function screen.blit
 * @number x The x-axis position to draw the texture
 * @number y The y-axis position to draw the texture
 * @tparam texture texture A texture object to blit
 */

/***
 * Prints a text onto the screen
 * @function screen.print
 * @number x The x-axis position to draw the texture
 * @number y The y-axis position to draw the texture
 * @string textstring The text to print
 * @tparam color color A color object
 */

/***
 * Gets the current default font to print in the screen
 * @function screen.getdefaultfont
 * @treturn font A font object
 */

/***
 * Sets a font as the current default font to print in the screen
 * @function screen.setdefaultfont
 * @tparam font font A font object
 */

/***
 * Gets the screen width
 * @function screen.getwidth
 * @treturn number The screen width dimension in pixels
 */

/***
 * Gets the screen height
 * @function screen.getheight
 * @treturn number The screen height dimension in pixels
 */

extern "C" {

int luaopen_screen(lua_State* L);

}

#endif // LRASPI_LUA_SCREEN_H