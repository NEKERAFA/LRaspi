/*
    lraspi/lscreen.cc - NEKERAFA - 26th july 2019

    See Copyright Notice in lraspi.h 
 */

#include <lua.hpp>

#include "SDL2/SDL.h"

#include "common/exception.h"
#include "modules/color/color.h"
#include "modules/font/font.h"
#include "modules/image/texture.h"
#include "modules/screen/screen_mod.h"

#include "lraspi/lauxlib.h"
#include "lraspi/lscreen.h"

/***
 * Screen management and information
 * @module Screen
 */
extern "C" {

/***
 * Initializes the screen subsystem. The interpreter calls this function internally, so should not be used explicitly.
 * @function screen.init
 */
static int lraspi_screen_init(lua_State* L)
{
    try {
        lraspi::screen::init();
    }
    catch (lraspi::Exception& e)
    {
        return luaL_error(L, e.what());
    }

    return 1;
}

/***
 * Clears the screen with an specified color
 * @function screen.clear
 * @tparam color color A color object
 */
static int lraspi_screen_clear(lua_State* L)
{
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 1));
    lraspi::screen::clear(color);
    return 0;
}

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
static int lraspi_screen_update(lua_State* L)
{
    bool quit = lraspi::screen::update();
    lua_pushboolean(L, quit);
    return 1;
}

/***
 * Blits an texture onto the screen
 * @function screen.blit
 * @tparam texture texture A texture object to blit
 * @int x The x-axis position to draw the texture
 * @int y The y-axis position to draw the texture
 */
static int lraspi_screen_blit(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3);

    SDL_Point center = texture->getSdlCenterPoint();

    lraspi::screen::blit(texture, x-center.x, y-center.y);
    return 0;
}

/***
 * Prints a text onto the screen
 * @function screen.print
 * @int x The x-axis position to draw the texture
 * @int y The y-axis position to draw the texture
 * @string textstring The text to print
 * @tparam color A color object
 */
static int lraspi_screen_print(lua_State* L)
{
    int x = luaL_checkinteger(L, 1);
    int y = luaL_checkinteger(L, 2);
    const char* str = luaL_checkstring(L, 3);
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 1));

    lraspi::screen::print(x, y, str, color);
    return 0;
}

/*** Gets the current default font to print in the screen
 * @function screen.defaultfont
 * @treturn font A font object
 */

/*** Sets a font as the current default font to print in the screen
 * @function screen.defaultfont
 * @tparam font font A font object
 */

static int lraspi_screen_default_font(lua_State* L)
{
    int argc = lua_gettop(L);
    int ret = 0;

    if (argc == 1)
    {
        lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
        lraspi::screen::setFont(font);
    }
    else
    {
        lraspi::Font* font = lraspi::screen::getFont();
        lraspi::lua::push(L, font);
        ret = 1;
    }
    

    return ret;
}

/***
 * Gets the screen width
 * @function screen.width
 * @treturn int The screen width dimension in pixels
 */
static int lraspi_screen_width(lua_State* L)
{
    lua_pushinteger(L, lraspi::screen::getWidth());
    return 1;
}

/***
 * Gets the screen height
 * @function screen.height
 * @treturn int The screen height dimension in pixels
 */
static int lraspi_screen_height(lua_State* L)
{
    lua_pushinteger(L, lraspi::screen::getHeight());
    return 1;
}

/***
 * Closes the screen subsystem. The interpreter calls this function internally, so should not be used explicitly.
 * @function screen.close
 */
static int lraspi_screen_close(lua_State* L)
{
    try {
        lraspi::screen::close();
    }
    catch (lraspi::Exception& e)
    {
        return luaL_error(L, e.what());
    }

    return 0;
}

// Screen module functions
static const luaL_Reg lraspi_screen[] =
{
    {"init",   lraspi_screen_init},
    {"close",  lraspi_screen_close},
    {"clear",  lraspi_screen_clear},
    {"update", lraspi_screen_update},
    {"blit",   lraspi_screen_blit},
    {"width",  lraspi_screen_width},
    {"height", lraspi_screen_height},
    {0, 0}
};

int luaopen_screen(lua_State* L)
{
    luaL_newlib(L, lraspi_screen);
    return 1;
}

}
