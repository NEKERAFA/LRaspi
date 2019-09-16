/*
    lraspi/lscreen.cc - NEKERAFA - 26th july 2019

    See Copyright Notice in lraspi.h 
 */

#include <lua.hpp>

#include "SDL2/SDL.h"

#include "common/exception.h"
#include "modules/color/color.h"
#include "modules/font/font.h"
#include "modules/draw/texture.h"
#include "modules/draw/canvas.h"
#include "modules/screen/module.h"

#include "lraspi/lauxlib.h"
#include "lraspi/lscreen.h"

extern "C" {

int lraspi_screen_init(lua_State* L)
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

int lraspi_screen_get_canvas(lua_State* L)
{
    lraspi::Canvas* canvas = lraspi::screen::getCanvas();
    lraspi::lua::push(L, canvas);
    return 1;
}

int lraspi_screen_set_canvas(lua_State* L)
{
    int argc = lua_gettop(L);

    if (argc == 0)
    {
        lraspi::screen::setCanvas(nullptr);
    }
    else
    {
        lraspi::Canvas* canvas = static_cast<lraspi::Canvas*>(lraspi::lua::check(L, lraspi::Canvas::type, 1));
        lraspi::screen::setCanvas(canvas);
    }

    return 0;
}

int lraspi_screen_blit(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    int x = luaL_checkinteger(L, 2);
    int y = luaL_checkinteger(L, 3);

    SDL_Point center = texture->getSdlCenterPoint();

    lraspi::screen::blit(texture, x-center.x, y-center.y);
    return 0;
}

int lraspi_screen_print(lua_State* L)
{
    int x = luaL_checkinteger(L, 1);
    int y = luaL_checkinteger(L, 2);
    const char* str = luaL_checkstring(L, 3);
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 1));

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

int lraspi_screen_close(lua_State* L)
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
    {"init",           lraspi_screen_init},
    {"close",          lraspi_screen_close},
    {"clear",          lraspi_screen_clear},
    {"update",         lraspi_screen_update},
    {"getcanvas",      lraspi_screen_get_canvas},
    {"setcanvas",      lraspi_screen_set_canvas},
    {"getdefaultfont", lraspi_screen_get_default_font},
    {"setdefaultfont", lraspi_screen_set_default_font},
    {"blit",           lraspi_screen_blit},
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
