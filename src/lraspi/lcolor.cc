/*
    lraspi/lcolor.cc - NEKERAFA - 14th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <iostream>

#include <lua.hpp>

#include "common/exception.h"
#include "modules/color/color.h"
#include "modules/color/module.h"

#include "lraspi/lauxlib.h"
#include "lraspi/lcolor.h"

extern "C"
{

int lraspi_color_new(lua_State* L)
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

int lraspi_color_get_palette(lua_State* L)
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

int lraspi_color_red(lua_State* L)
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

int lraspi_color_green(lua_State* L)
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

int lraspi_color_blue(lua_State* L)
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

int lraspi_color_alpha(lua_State* L)
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

int lraspi_color_free(lua_State* L)
{
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 1));
    delete color;

    return 0;
}

// Color methods
static const luaL_Reg lraspi_color_object[] =
{
    {"red",   lraspi_color_red},
    {"green", lraspi_color_green},
    {"blue",  lraspi_color_blue},
    {"alpha", lraspi_color_alpha},
    {"__gc",  lraspi_color_free},
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
    {"free",       lraspi_color_free},
    {0, 0}
};

int luaopen_color(lua_State* L)
{
    lraspi::lua::registerobject(L, lraspi::Color::type, lraspi_color_object);
    luaL_newlib(L, lraspi_color);
    return 1;
}

}