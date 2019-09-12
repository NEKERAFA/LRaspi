/*
    lraspi/lcolor.cc - NEKERAFA - 14th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <iostream>

#include <lua.hpp>

#include "common/exception.h"
#include "modules/color/color.h"
#include "modules/color/color_mod.h"

#include "lraspi/lauxlib.h"
#include "lraspi/lcolor.h"

/***
 * Color creation and manipulation
 * @module Color
 */
extern "C"
{

/***
 * Create a new color
 * @function color.new
 * @int red The red channel value
 * @int blue The blue channel value
 * @int green The green channel value
 * @int[opt=0] alpha The alpha channel value
 * @treturn color A color object
 */
static int lraspi_color_new(lua_State* L)
{
    int argc = lua_gettop(L);
    lua_Integer r, g, b, a;
    lraspi::Color* color;

    r = luaL_checkinteger(L, 1);
    g = luaL_checkinteger(L, 2);
    b = luaL_checkinteger(L, 3);

    if (argc == 4)
    {
        lua_Integer a = luaL_checkinteger(L, 4);
        color = lraspi::color::create(r, g, b, a);
    }
    else
    {
        color = lraspi::color::create(r, g, b, 255);
    }
    
    lraspi::lua::push(L,  color);

    return 1;
}

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
static int lraspi_color_get_palette(lua_State* L)
{
    lua_newtable(L);

    lua_pushstring(L, "white");
    lraspi::lua::push(L,  lraspi::color::white);
    lua_settable(L, -3);

    lua_pushstring(L, "black");
    lraspi::lua::push(L,  lraspi::color::black);
    lua_settable(L, -3);

    lua_pushstring(L, "red");
    lraspi::lua::push(L,  lraspi::color::red);
    lua_settable(L, -3);

    lua_pushstring(L, "green");
    lraspi::lua::push(L,  lraspi::color::green);
    lua_settable(L, -3);

    lua_pushstring(L, "blue");
    lraspi::lua::push(L,  lraspi::color::blue);
    lua_settable(L, -3);

    lua_pushstring(L, "yellow");
    lraspi::lua::push(L,  lraspi::color::yellow);
    lua_settable(L, -3);

    lua_pushstring(L, "cyan");
    lraspi::lua::push(L,  lraspi::color::cyan);
    lua_settable(L, -3);

    lua_pushstring(L, "magenta");
    lraspi::lua::push(L,  lraspi::color::magenta);
    lua_settable(L, -3);

    lua_pushstring(L, "marron");
    lraspi::lua::push(L,  lraspi::color::marron);
    lua_settable(L, -3);

    lua_pushstring(L, "grass");
    lraspi::lua::push(L,  lraspi::color::grass);
    lua_settable(L, -3);

    lua_pushstring(L, "navy");
    lraspi::lua::push(L,  lraspi::color::navy);
    lua_settable(L, -3);

    lua_pushstring(L, "turquoise");
    lraspi::lua::push(L,  lraspi::color::turquoise);
    lua_settable(L, -3);

    lua_pushstring(L, "olive");
    lraspi::lua::push(L,  lraspi::color::olive);
    lua_settable(L, -3);

    lua_pushstring(L, "violet");
    lraspi::lua::push(L,  lraspi::color::violet);
    lua_settable(L, -3);

    lua_pushstring(L, "gray");
    lraspi::lua::push(L,  lraspi::color::gray);
    lua_settable(L, -3);

    return 1;
}

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
static int lraspi_color_red(lua_State* L)
{
    int ret = 0;
    int argc = lua_gettop(L);

    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 1));

    if (argc == 2)
    {
        lua_Integer r = luaL_checkinteger(L, 2);
        color->red(r);
    }
    else
    {
        lua_Integer r = color->red();
        lua_pushinteger(L, r);
        ret = 1;
    }

    return ret;
}

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
static int lraspi_color_green(lua_State* L)
{
    int ret, argc = 0;
    
    argc = lua_gettop(L);
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 1));
    
    if (argc == 2)
    {
        lua_Integer r = luaL_checkinteger(L, 2);
        color->green(r);
    }
    else
    {
        lua_Integer r = color->green();
        lua_pushinteger(L, r);
        ret = 1;
    }

    return ret;
}

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
static int lraspi_color_blue(lua_State* L)
{
    int ret, argc = 0;
    
    argc = lua_gettop(L);
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 1));
    
    if (argc == 2)
    {
        lua_Integer r = luaL_checkinteger(L, 2);
        color->blue(r);
    }
    else
    {
        lua_Integer r = color->blue();
        lua_pushinteger(L, r);
        ret = 1;
    }

    return ret;
}

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
static int lraspi_color_alpha(lua_State* L)
{
    int ret, argc = 0;
    
    argc = lua_gettop(L);
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 1));
    
    if (argc == 2)
    {
        lua_Integer r = luaL_checkinteger(L, 2);
        color->alpha(r);
    }
    else
    {
        lua_Integer r = color->alpha();
        lua_pushinteger(L, r);
        ret = 1;
    }

    return ret;
}

/***
 * Destroys a color object
 * @function color.free
 * @tparam color color A color object to free
 */
static int lraspi_color__gc(lua_State* L)
{
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 1));
    delete color;

    return 0;
}

/***
 * This object represents a color
 * @type color
 */

/***
 * Gets the red channel value of the color
 * @function color:red
 * @treturn int The red value
 */

/***
 * Sets the red channel value of the color
 * @function color:red
 * @int red The red value
 */

/***
 * Gets the green channel value of the color
 * @function color:green
 * @treturn int The green value
 */

/***
 * Sets the green channel value of the color
 * @function color:green
 * @int green The green value
 */

/***
 * Gets the blue channel value of the color
 * @function color:blue
 * @treturn int The blue value
 */

/***
 * Sets the blue channel value of the color
 * @function color:blue
 * @int blue The blue value
 */

/***
 * Gets the alpha channel value of the color
 * @function color:alpha
 * @treturn int The alpha value
 */

/***
 * Sets the alpha channel value of the color
 * @function color:alpha
 * @int alpha The alpha value
 */

// Color methods
static const luaL_Reg lraspi_color_object[] =
{
    {"red",   lraspi_color_red},
    {"green", lraspi_color_green},
    {"blue",  lraspi_color_blue},
    {"alpha", lraspi_color_alpha},
    {"__gc",  lraspi_color__gc},
    {0, 0}
};

// Color module functions
static const luaL_Reg lraspi_color[] =
{
    {"new",        lraspi_color_new},
    {"getpalette", lraspi_color_get_palette},
    {"red",        lraspi_color_red},
    {"green",      lraspi_color_green},
    {"blue",       lraspi_color_blue},
    {"alpha",      lraspi_color_alpha},
    {"free",       lraspi_color__gc},
    {0, 0}
};

int luaopen_color(lua_State* L)
{
    lraspi::lua::registerobject(L, lraspi::Color::type, lraspi_color_object);
    luaL_newlib(L, lraspi_color);
    return 1;
}

}