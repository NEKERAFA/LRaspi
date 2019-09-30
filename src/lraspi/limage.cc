/*
    lraspi/limage.cc - NEKERAFA - 13th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <cstring>

#include <lua.hpp>

#include "modules/common/exception.h"
#include "modules/image/text.h"
#include "modules/image/texture.h"
#include "modules/image/image.h"
#include "modules/image/module.h"

#include "lraspi/lauxlib.h"
#include "lraspi/limage.h"
#include "lraspi/limage.h"

extern "C"
{

int lraspi_image_new(lua_State* L)
{
    const char* path = luaL_checkstring(L, 1);

    try
    {
        lraspi::Image* image = lraspi::image::newImage(path);
        lraspi::lua::push(L, image);
    }
    catch (lraspi::Exception& e)
    {
        return luaL_error(L, e.what());
    }

    return 1;
}

int lraspi_image_new_text(lua_State* L)
{
    lraspi::Font* font = static_cast<lraspi::Font*>(lraspi::lua::check(L, lraspi::Font::type, 1));
    const char* str = luaL_checkstring(L, 2);

    try
    {
        lraspi::Text* text = lraspi::image::newText(font, str);
        lraspi::lua::push(L, text);
    }
    catch (lraspi::Exception e)
    {
        return luaL_error(L, e.what());
    }

    return 1;
}

int lraspi_image_reset(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    texture->reset();

    return 0;
}

int lraspi_image_tint(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 2));
    texture->tint(color);

    return 0;
}

int lraspi_image_tint_color(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lraspi::lua::push(L, texture->getTintColor());

    return 1;
}

int lraspi_image_set_alpha(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    int alpha = luaL_checknumber(L, 2);
    texture->setAlpha(alpha);

    return 0;
}

int lraspi_image_get_alpha(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    int alpha = texture->getAlpha();
    lua_pushinteger(L, alpha);

    return 1;
}

int lraspi_image_get_width(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    int width = texture->getWidth();
    lua_pushinteger(L, width);

    return 1;
}

int lraspi_image_get_height(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    int height = texture->getHeight();
    lua_pushinteger(L, height);

    return 1;
}

int lraspi_image_get_real_width(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    int width = texture->getRealWidth();
    lua_pushinteger(L, width);

    return 1;   
}

int lraspi_image_get_real_height(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    int height = texture->getRealHeight();
    lua_pushinteger(L, height);

    return 1;
}

int lraspi_image_resize(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    int width = luaL_checknumber(L, 2);
    int height = luaL_checknumber(L, 3);
    texture->setWidth(width);
    texture->setHeight(height);

    return 0;
}

int lraspi_image_rotate(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    double angle = luaL_checknumber(L, 2);
    texture->setAngle(angle);

    return 0;
}

int lraspi_image_set_center(lua_State* L)
{
    int argc = lua_gettop(L);
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));

    if (argc == 0)
    {
        texture->setCenter();
    }
    else
    {
        int x = luaL_checknumber(L, 2);
        int y = luaL_checknumber(L, 3);
        texture->setCenter(x, y);
    }

    return 0;
}

int lraspi_image_get_center(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    int x, y;
    texture->getCenter(&x, &y);
    lua_pushinteger(L, x);
    lua_pushinteger(L, y);

    return 2;
}

int lraspi_image_v_flip(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    texture->setVFlip();

    return 0;
}

int lraspi_image_h_flip(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    texture->setHFlip();

    return 0;
}

int lraspi_image_is_flipped(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    bool h, v;
    texture->getFlip(&h, &v);
    lua_pushboolean(L, h);
    lua_pushboolean(L, v);

    return 2;
}

int lraspi_image_set_text(lua_State* L)
{
    lraspi::Text* text = static_cast<lraspi::Text*>(lraspi::lua::check(L, lraspi::Text::type, 1));
    const char* str = luaL_checkstring(L, 2);
    text->setText(str);
    return 0;
}

int lraspi_image_add_text(lua_State* L)
{
    lraspi::Text* text = static_cast<lraspi::Text*>(lraspi::lua::check(L, lraspi::Text::type, 1));
    const char* str = luaL_checkstring(L, 2);
    text->addText(str);
    return 0;    
}

int lraspi_image_clear_text(lua_State* L)
{
    lraspi::Text* text = static_cast<lraspi::Text*>(lraspi::lua::check(L, lraspi::Text::type, 1));
    const char* str = luaL_checkstring(L, 2);
    text->clear();
    return 0;    
}

int lraspi_image_free(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    delete texture;

    return 0;
}

// Image methods
static const luaL_Reg lraspi_image_methods[] =
{
    {"reset",         lraspi_image_reset},
    {"tint",          lraspi_image_tint},
    {"tintcolor",     lraspi_image_tint_color},
    {"getalpha",      lraspi_image_get_alpha},
    {"setalpha",      lraspi_image_set_alpha},
    {"rotate",        lraspi_image_rotate},
    {"getcenter",     lraspi_image_get_center},
    {"setcenter",     lraspi_image_set_center},
    {"vflip",         lraspi_image_v_flip},
    {"hflip",         lraspi_image_h_flip},
    {"isflipped",     lraspi_image_is_flipped},
    {"getwidth",      lraspi_image_get_width},
    {"getheight",     lraspi_image_get_height},
    {"getrealwidth",  lraspi_image_get_real_width},
    {"getrealheight", lraspi_image_get_real_height},
    {"resize",        lraspi_image_resize},
    {"free",          lraspi_image_free},
    {"__gc",          lraspi_image_free},
    {0, 0}
};

// Text methods
static const luaL_Reg lraspi_text_methods[] =
{
    {"reset",         lraspi_image_reset},
    {"tint",          lraspi_image_tint},
    {"tintcolor",     lraspi_image_tint_color},
    {"getalpha",      lraspi_image_get_alpha},
    {"setalpha",      lraspi_image_set_alpha},
    {"rotate",        lraspi_image_rotate},
    {"getcenter",     lraspi_image_get_center},
    {"setcenter",     lraspi_image_set_center},
    {"vflip",         lraspi_image_v_flip},
    {"hflip",         lraspi_image_h_flip},
    {"isflipped",     lraspi_image_is_flipped},
    {"getwidth",      lraspi_image_get_width},
    {"getheight",     lraspi_image_get_height},
    {"getrealwidth",  lraspi_image_get_real_width},
    {"getrealheight", lraspi_image_get_real_height},
    {"resize",        lraspi_image_resize},
    {"set",           lraspi_image_set_text},
    {"add",           lraspi_image_add_text},
    {"clear",         lraspi_image_clear_text},
    {"free",          lraspi_image_free},
    {"__gc",          lraspi_image_free},
    {0, 0}
};

// Image modules functions
static const luaL_Reg lraspi_image_functions[] =
{
    {"new",           lraspi_image_new},
    {"newtext",       lraspi_image_new_text},
    {"reset",         lraspi_image_reset},
    {"tint",          lraspi_image_tint},
    {"tintcolor",     lraspi_image_tint_color},
    {"getalpha",      lraspi_image_get_alpha},
    {"setalpha",      lraspi_image_set_alpha},
    {"rotate",        lraspi_image_rotate},
    {"getcenter",     lraspi_image_get_center},
    {"setcenter",     lraspi_image_set_center},
    {"vflip",         lraspi_image_v_flip},
    {"hflip",         lraspi_image_h_flip},
    {"isflipped",     lraspi_image_is_flipped},
    {"getwidth",      lraspi_image_get_width},
    {"getheight",     lraspi_image_get_height},
    {"getrealwidth",  lraspi_image_get_real_width},
    {"getrealheight", lraspi_image_get_real_height},
    {"resize",        lraspi_image_resize},
    {"free",          lraspi_image_free},
    {0, 0}
};

int luaopen_image(lua_State* L)
{
    lraspi::lua::registerobject(L, lraspi::Text::type, lraspi_text_methods);
    lraspi::lua::registerobject(L, lraspi::Image::type, lraspi_image_methods);
    luaL_newlib(L, lraspi_image_functions);
    return 1;
}

}