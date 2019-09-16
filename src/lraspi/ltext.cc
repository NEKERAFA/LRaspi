/*
    lraspi/ltext.h - NEKERAFA - 16th sep 2019

    See Copyright Notice in lraspi.h 
 */

#include <cstring>

#include <lua.hpp>

#include "common/exception.h"
#include "modules/color/color.h"
#include "modules/draw/text.h"

#include "lraspi/lauxlib.h"
#include "lraspi/ltexture.h"
#include "lraspi/ltext.h"

extern "C" {
    
int lraspi_text_set_quality(lua_State* L)
{
    lraspi::Text* text = static_cast<lraspi::Text*>(lraspi::lua::check(L, lraspi::Text::type, 1));
    const char* quality = luaL_checkstring(L, 2);

    if (std::strcmp(quality, "fast") == 0)
    {
        text->setQuality(lraspi::TextQuality::FAST);
    }
    else if (std::strcmp(quality, "normal") == 0)
    {
        text->setQuality(lraspi::TextQuality::NORMAL);
    }
    else
    {
        const char* msg = lua_pushfstring(L, "must be `fast' or `normal'");
        return luaL_argerror(L, 2, msg);
    }

    return 0;
}

int lraspi_text_get_quality(lua_State* L)
{
    lraspi::Text* text = static_cast<lraspi::Text*>(lraspi::lua::check(L, lraspi::Text::type, 1));

    switch (text->getQuality())
    {
    case lraspi::TextQuality::FAST:
        lua_pushliteral(L, "fast");
        break;
    case lraspi::TextQuality::NORMAL:
        lua_pushliteral(L, "normal");
        break;
    }
    
    return 1;
}

int lraspi_text_set(lua_State* L)
{
    lraspi::Text* text = static_cast<lraspi::Text*>(lraspi::lua::check(L, lraspi::Text::type, 1));
    const char* str = luaL_checkstring(L, 2);
    text->setText(str);
    return 0;
}

int lraspi_text_add(lua_State* L)
{
    lraspi::Text* text = static_cast<lraspi::Text*>(lraspi::lua::check(L, lraspi::Text::type, 1));
    const char* str = luaL_checkstring(L, 2);
    text->addText(str);
    return 0;    
}

int lraspi_text_clear(lua_State* L)
{
    lraspi::Text* text = static_cast<lraspi::Text*>(lraspi::lua::check(L, lraspi::Text::type, 1));
    const char* str = luaL_checkstring(L, 2);
    text->clear();
    return 0;    
}

// Text methods
static const luaL_Reg lraspi_text_methods[] =
{
    {"setquality",    lraspi_text_set_quality},
    {"getquality",    lraspi_text_get_quality},
    {"set",           lraspi_text_set},
    {"add",           lraspi_text_add},
    {"clear",         lraspi_text_clear},
    {"reset",         lraspi_texture_reset},
    {"tint",          lraspi_texture_tint},
    {"tintcolor",     lraspi_texture_tint_color},
    {"getalpha",      lraspi_texture_get_alpha},
    {"setalpha",      lraspi_texture_set_alpha},
    {"rotate",        lraspi_texture_rotate},
    {"getcenter",     lraspi_texture_get_center},
    {"setcenter",     lraspi_texture_set_center},
    {"vflip",         lraspi_texture_v_flip},
    {"hflip",         lraspi_texture_h_flip},
    {"isflipped",     lraspi_texture_is_flipped},
    {"getwidth",      lraspi_texture_get_width},
    {"getheight",     lraspi_texture_get_height},
    {"getrealwidth",  lraspi_texture_get_real_width},
    {"getrealheight", lraspi_texture_get_real_height},
    {"resize",        lraspi_texture_resize},
    {"getblendmode",  lraspi_texture_get_blend_mode},
    {"setblendmode",  lraspi_texture_set_blend_mode},
    {"getpixel",      lraspi_texture_get_pixel},
    {"setpixel",      lraspi_texture_set_pixel},
    {"__gc",          lraspi_texture_free},
    {0, 0}
};

// Text modules functions
static const luaL_Reg lraspi_text_functions[] =
{
    {"setquality",    lraspi_text_set_quality},
    {"getquality",    lraspi_text_get_quality},
    {"set",           lraspi_text_set},
    {"add",           lraspi_text_add},
    {"clear",         lraspi_text_clear},
    {0, 0}
};

int luaopen_text(lua_State* L)
{
    lraspi::lua::registerobject(L, lraspi::Text::type, lraspi_text_methods);
    luaL_newlib(L, lraspi_text_functions);
    return 1;
}

}