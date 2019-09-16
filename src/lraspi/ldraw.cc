/*
    lraspi/ldraw.h - NEKERAFA - 16th sep 2019

    See Copyright Notice in lraspi.h 
 */

#include <lua.hpp>

#include "common/exception.h"
#include "modules/draw/canvas.h"
#include "modules/draw/text.h"
#include "modules/draw/module.h"

#include "lraspi/lauxlib.h"
#include "lraspi/ldraw.h"

extern "C" {

int lraspi_draw_new_canvas(lua_State* L)
{
    lua_Integer width = luaL_checkinteger(L, 1);
    lua_Integer height = luaL_checkinteger(L, 2);

    try
    {
        lraspi::Canvas* canvas = lraspi::draw::newCanvas(width, height);
        lraspi::lua::push(L, canvas);
    }
    catch (lraspi::Exception& e)
    {
        return luaL_error(L, e.what());
    }

    return 1;
}

int lraspi_draw_new_text(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    const char* str = luaL_checkstring(L, 2);

    try
    {
        lraspi::Text* text = lraspi::draw::newText(font, str);
        lraspi::lua::push(L, text);
    }
    catch (lraspi::Exception e)
    {
        return luaL_error(L, e.what());
    }

    return 1;
}

// Draw module functions
static const luaL_Reg lraspi_draw_functions[] =
{
    {"newcanvas", lraspi_draw_new_canvas},
    {"newtext",   lraspi_draw_new_text},
    {0, 0}
};

int luaopen_draw(lua_State* L)
{
    luaL_newlib(L, lraspi_draw_functions);
    return 1;
}

}