/*
    lraspi/lscreen.cc - NEKERAFA - 26th july 2019

    See Copyright Notice in lraspi.h 
 */

#include <lua.hpp>

#include "common/exception.h"
#include "modules/color/color.h"
#include "modules/image/texture.h"
#include "modules/screen/screen_mod.h"

#include "lraspi/lauxlib.h"
#include "lraspi/lscreen.h"

extern "C" {

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

static int lraspi_screen_clear(lua_State* L)
{
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 1));
    lraspi::screen::clear(color);
    return 0;
}

static int lraspi_screen_update(lua_State* L)
{
    bool quit = lraspi::screen::update();
    lua_pushboolean(L, quit);
    return 1;
}

static int lraspi_screen_blit(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3);

    lraspi::screen::blit(texture, x, y);
}

static int lraspi_screen_get_width(lua_State* L)
{
    lua_pushinteger(L, lraspi::screen::getWidth());
    return 1;
}

static int lraspi_screen_get_height(lua_State* L)
{
    lua_pushinteger(L, lraspi::screen::getHeight());
    return 1;
}

static const luaL_Reg lraspi_screen[] =
{
    {"init",      lraspi_screen_init},
    {"close",     lraspi_screen_close},
    {"clear",     lraspi_screen_clear},
    {"update",    lraspi_screen_update},
    {"blit",      lraspi_screen_blit},
    {"getWidth",  lraspi_screen_get_width},
    {"getHeight", lraspi_screen_get_height},
    {0, 0}
};

int luaopen_screen(lua_State* L)
{
    luaL_newlib(L, lraspi_screen);
    return 1;
}

}