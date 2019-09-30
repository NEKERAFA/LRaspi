/*
    lraspi/lfont.cc - NEKERAFA - 23th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <iostream>
#include <cstring>

#include <SDL2/SDL_ttf.h>
#include <lua.hpp>

#include "modules/common/exception.h"
#include "modules/font/font.h"
#include "modules/font/module.h"

#include "lraspi/lauxlib.h"
#include "lraspi/lfont.h"

extern "C"
{

int lraspi_font_init(lua_State* L)
{
    try
    {
        lraspi::font::init();
    }
    catch(lraspi::Exception &e)
    {
        return luaL_error(L, e.what());
    }
    
    return 0;
}

int lraspi_font_new(lua_State* L)
{
    int argc = lua_gettop(L);
    
    const char* path = luaL_checkstring(L, 1);
    int size = LRASPI_FONT_SIZE;

    if (argc == 2)
        size = luaL_checknumber(L, 2);

    try
    {
        lraspi::Font* font = lraspi::font::loadFont(path, size);
        lraspi::lua::push(L, font);
    }
    catch(lraspi::Exception e)
    {
        return luaL_error(L, e.what());
    }
    
    return 1;
}

int lraspi_font_new_default(lua_State* L)
{
    int argc = lua_gettop(L);
    int size = LRASPI_FONT_SIZE;

    if (argc == 1)
        size = luaL_checknumber(L, 1);

    try
    {
        lraspi::Font* font = lraspi::font::createDefault(size);
        lraspi::lua::push(L, font);
    }
    catch(lraspi::Exception e)
    {
        return luaL_error(L, e.what());
    }
    
    return 1;
}

int lraspi_font_get_height(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    int height = font->getHeight();
    lua_pushinteger(L, height);
    
    return 1;
}

int lraspi_font_get_width(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    const char* text = luaL_checkstring(L, 2);

    try
    {
        int width = font->getWidth(text);
        lua_pushinteger(L, width);
    }
    catch(lraspi::Exception e)
    {
        return luaL_error(L, e.what());
    }
    
    return 1;
}

int lraspi_font_wrap(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    const char* text = luaL_checkstring(L, 2);
    int width = luaL_checknumber(L, 3);

    try
    {
        const char* text_wrapped = font->getWrap(text, width);
        lua_pushstring(L, text_wrapped);
    }
    catch(lraspi::Exception e)
    {
        return luaL_error(L, e.what());
    }
    
    return 1;
}


int lraspi_font_set_style(lua_State* L)
{
    int argc = lua_gettop(L);

    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));

    // font.style(fnt, "normal")
    if ((argc == 0) || (lua_isstring(L, 2)))
    {
        const char* style = lua_tostring(L, 2);
        if (std::strcmp(style, "normal") != 0)
        {
            const char* msg = lua_pushfstring(L, "must be `normal' or a table with the values `italic', `bold', `underline' or `strikethrough'");
            return luaL_argerror(L, 2, msg);
        }

        font->setStyle(TTF_STYLE_NORMAL);
    }
    // font.style(fnt, {...})
    else if (lua_istable(L, 2))
    {
        lua_pushvalue(L, 2); // stack = {tbl, ...}
        lua_pushnil(L);      // stack = {nil, tbl, ...}

        int style = 0;

        while (lua_next(L, -2))
        {
            lua_pushvalue(L, -2); // stack = {key, value, key, tbl, ...}

            if (lua_isstring(L, -2))
            {
                const char* style_mod = lua_tostring(L, -2);
                if (std::strcmp(style_mod, "italic") == 0)
                {
                    style |= TTF_STYLE_ITALIC;
                }
                else if (std::strcmp(style_mod, "bold") == 0)
                {
                    style |= TTF_STYLE_BOLD;
                }
                else if (std::strcmp(style_mod, "underline") == 0)
                {
                    style |= TTF_STYLE_UNDERLINE;
                }
                else if (std::strcmp(style_mod, "strikethrough") == 0)
                {
                    style |= TTF_STYLE_STRIKETHROUGH;
                }
                else
                {
                    const char* msg = lua_pushfstring(L, "must be `normal' or a table with the values `italic', `bold', `underline' or `strikethrough'");
                    return luaL_argerror(L, 2, msg);
                }
                
            }
            else
            {
                const char* msg = lua_pushfstring(L, "the table must contains the following values: `italic', `bold', `underline' or `strikethrough'");
                return luaL_argerror(L, 2, msg);
            }
            
            lua_pop(L, 2); // stack = {key, tbl, ...}
        }

        lua_pop(L, 1); // stack = {tbl, ...}

        font->setStyle(style);
    }
    else
    {
        const char* msg = lua_pushfstring(L, "expected string or table, got %s", luaL_typename(L, 2));
        return luaL_argerror(L, 2, msg);
    }

    return 0;
}

int lraspi_font_get_style(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));

    lua_newtable(L);
    int pos = 0;
    int style = font->getStyle();
    
    if (style == TTF_STYLE_NORMAL)
    {
        lua_pushliteral(L, "normal");
        lua_rawseti(L, -1, ++pos);
    }

    if (style & TTF_STYLE_BOLD)
    {
        lua_pushliteral(L, "bold");
        lua_rawseti(L, -1, ++pos);
    }
    
    if (style & TTF_STYLE_ITALIC)
    {
        lua_pushliteral(L, "italic");
        lua_rawseti(L, -1, ++pos);
    }

    if (style & TTF_STYLE_UNDERLINE)
    {
        lua_pushliteral(L, "underline");
        lua_rawseti(L, -1, ++pos);
    }

    if (style & TTF_STYLE_STRIKETHROUGH)
    {
        lua_pushliteral(L, "strikethrough");
        lua_rawseti(L, -1, ++pos);
    }

    return 1;
}

int lraspi_font_get_outline(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    int outline = font->getOutline();
    lua_pushinteger(L, outline);

    return 1;
}

int lraspi_font_set_outline(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    int outline = luaL_checknumber(L, 2);
    font->setOutline(outline);

    return 0;
}

int lraspi_font_set_hinting_mode(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    const char* mode = luaL_checkstring(L, 2);

    if (std::strcmp(mode, "normal"))
    {
        font->setHintingMode(TTF_HINTING_NORMAL);
    }
    else if (std::strcmp(mode, "light"))
    {
        font->setHintingMode(TTF_HINTING_LIGHT);
    }
    else if (std::strcmp(mode, "mono"))
    {
        font->setHintingMode(TTF_HINTING_MONO);
    }
    else if (std::strcmp(mode, "none"))
    {
        font->setHintingMode(TTF_HINTING_NONE);
    }

    return 0;
}

int lraspi_font_get_ascent(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    lua_pushinteger(L, font->getAscent());

    return 1;
}

int lraspi_font_get_descent(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    lua_pushinteger(L, font->getDescent());

    return 1;
}

int lraspi_font_get_line_skip(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    lua_pushinteger(L, font->getLineSkip());

    return 1;
}

int lraspi_font_set_line_height(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    lua_Number height = luaL_checknumber(L, 2);
    font->setLineHeight(height);
    
    return 0;
}

int lraspi_font_get_line_height(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    lua_Number height = font->getLineHeight();
    lua_pushnumber(L, height);
    
    return 1;
}

int lraspi_font_get_family_name(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    const char* family_name = font->getFamilyName();

    if (family_name != nullptr)
    {
        lua_pushstring(L, family_name);
    }
    else
    {
        lua_pushnil(L);
    }

    return 1;
}

int lraspi_font_free(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    delete font;

    return 0;
}

int lraspi_font_close(lua_State* L)
{
    try
    {
        lraspi::font::close();
    }
    catch(lraspi::Exception e)
    {
        return luaL_error(L, e.what());
    }
    
    return 0;
}

// Font methods
static const luaL_Reg lraspi_font_methods[] =
{
    {"getheight",      lraspi_font_get_height},
    {"getwidth",       lraspi_font_get_width},
    {"wrap",           lraspi_font_wrap},
    {"getstyle",       lraspi_font_get_style},
    {"setstyle",       lraspi_font_set_style},
    {"getoutline",     lraspi_font_get_outline},
    {"sethintingmode", lraspi_font_set_hinting_mode},
    {"getascent",      lraspi_font_get_ascent},
    {"getdescent",     lraspi_font_get_descent},
    {"getlineskip",    lraspi_font_get_line_skip},
    {"getlineheight",  lraspi_font_get_line_height},
    {"getfamilyname",  lraspi_font_get_family_name},
    {"__gc",           lraspi_font_free},
    {0, 0}
};

// Font module functions
static const luaL_Reg lraspi_font_functions[] =
{
    {"init",           lraspi_font_init},
    {"new",            lraspi_font_new},
    {"newdefault",     lraspi_font_new_default},
    {"getheight",      lraspi_font_get_height},
    {"getwidth",       lraspi_font_get_width},
    {"wrap",           lraspi_font_wrap},
    {"getstyle",       lraspi_font_get_style},
    {"setstyle",       lraspi_font_set_style},
    {"getoutline",     lraspi_font_get_outline},
    {"sethintingmode", lraspi_font_set_hinting_mode},
    {"getascent",      lraspi_font_get_ascent},
    {"getdescent",     lraspi_font_get_descent},
    {"getlineskip",    lraspi_font_get_line_skip},
    {"getlineheight",  lraspi_font_get_line_height},
    {"getfamilyname",  lraspi_font_get_family_name},
    {"free",           lraspi_font_free},
    {"close",          lraspi_font_close},
    {0, 0}
};

int luaopen_font(lua_State* L)
{
    lraspi::lua::registerobject(L, lraspi::Font::type, lraspi_font_methods);
    luaL_newlib(L, lraspi_font_functions);
    return 1;
}

}
