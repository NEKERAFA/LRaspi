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
extern "C" {

/***
 * Initializes the screen subsystem. The interpreter calls this function internally, so should not be used explicitly.
 * @function screen.init
 */
int lraspi_screen_init(lua_State* L);

/***
 * Clears the screen with an specified color
 * @function screen.clear
 * @tparam color color A color object
 */
int lraspi_screen_clear(lua_State* L);

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
int lraspi_screen_update(lua_State* L);

/***
 * Gets the current canvas
 * @function screen.getcanvas
 */
int lraspi_screen_get_canvas(lua_State* L);

/***
 * Sets the render target to a canvas
 * @function screen.setcanvas
 * @tparam canvas A canvas object
 */

/***
 * Resets the render target to the screen
 * @function screen.setcanvas
 */
int lraspi_screen_set_canvas(lua_State* L);

/***
 * Blits an texture onto the screen
 * @function screen.blit
 * @tparam texture texture A texture object to blit
 * @int x The x-axis position to draw the texture
 * @int y The y-axis position to draw the texture
 */
int lraspi_screen_blit(lua_State* L);

/***
 * Prints a text onto the screen
 * @function screen.print
 * @int x The x-axis position to draw the texture
 * @int y The y-axis position to draw the texture
 * @string textstring The text to print
 * @tparam color A color object
 */
int lraspi_screen_print(lua_State* L);

/***
 * Gets the current default font to print in the screen
 * @function screen.getdefaultfont
 * @treturn font A font object
 */
int lraspi_screen_get_default_font(lua_State* L);

/***
 * Sets a font as the current default font to print in the screen
 * @function screen.defaultfont
 * @tparam font font A font object
 */
int lraspi_screen_set_default_font(lua_State* L);

/***
 * Gets the screen width
 * @function screen.getwidth
 * @treturn int The screen width dimension in pixels
 */
int lraspi_screen_get_width(lua_State* L);

/***
 * Gets the screen height
 * @function screen.getheight
 * @treturn int The screen height dimension in pixels
 */
int lraspi_screen_get_height(lua_State* L);

/***
 * Closes the screen subsystem. The interpreter calls this function internally, so should not be used explicitly.
 * @function screen.close
 */
int lraspi_screen_close(lua_State* L);

int luaopen_screen(lua_State* L);

}

#endif // LRASPI_LUA_SCREEN_H