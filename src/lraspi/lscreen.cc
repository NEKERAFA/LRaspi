/*
    lraspi/lscreen.cc - NEKERAFA - 26th july 2019

    See Copyright Notice in lraspi.h 
 */

#include <lua.hpp>

#include "SDL2/SDL.h"

#include "modules/common/exception.h"
#include "modules/color/color.h"
#include "modules/font/font.h"
#include "modules/image/texture.h"
#include "modules/screen/module.h"

#include "lraspi/lauxlib.h"
#include "lraspi/lscreen.h"

extern "C" {

int lraspi_screen_clear(lua_State* L)
{
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 1));
    lraspi::screen::clear(color);
    return 0;
}

int lraspi_screen_update(lua_State* L)
{
    bool quit = lraspi::screen::update();
    lua_pushboolean(L, quit);
    return 1;
}

int lraspi_screen_blit(lua_State* L)
{
    int x = luaL_checknumber(L, 1);
    int y = luaL_checknumber(L, 2);
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 3));

    lraspi::screen::blit(x, y, texture);
    
    return 0;
}

int lraspi_screen_print(lua_State* L)
{
    int x = luaL_checknumber(L, 1);
    int y = luaL_checknumber(L, 2);
    const char* str = luaL_checkstring(L, 3);
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 4));

    lraspi::screen::print(x, y, str, color);
    
    return 0;
}

int lraspi_screen_get_default_font(lua_State* L)
{
    lraspi::Font* font = lraspi::screen::getFont();
    lraspi::lua::push(L, font);
    return 1;
}

int lraspi_screen_set_default_font(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    lraspi::screen::setFont(font);
    return 0;
}

int lraspi_screen_get_width(lua_State* L)
{
    lua_pushinteger(L, lraspi::screen::getWidth());
    return 1;
}

int lraspi_screen_get_height(lua_State* L)
{
    lua_pushinteger(L, lraspi::screen::getHeight());
    return 1;
}

// Screen module functions
static const luaL_Reg lraspi_screen[] =
{
    {"clear",          lraspi_screen_clear},
    {"update",         lraspi_screen_update},
    {"getdefaultfont", lraspi_screen_get_default_font},
    {"setdefaultfont", lraspi_screen_set_default_font},
    {"blit",           lraspi_screen_blit},
    {"print",          lraspi_screen_print},
    {"getwidth",       lraspi_screen_get_width},
    {"getheight",      lraspi_screen_get_height},
    {0, 0}
};

int luaopen_screen(lua_State* L)
{
    luaL_newlib(L, lraspi_screen);
    return 1;
}

}
