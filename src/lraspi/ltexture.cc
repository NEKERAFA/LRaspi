/*
    lraspi/ltexture.h - NEKERAFA - 16th sep 2019

    See Copyright Notice in lraspi.h 
 */

#include <cstring>

#include <lua.hpp>

#include "common/exception.h"
#include "modules/color/color.h"
#include "modules/draw/texture.h"

#include "lraspi/lauxlib.h"
#include "lraspi/ltexture.h"

extern "C" {

int lraspi_texture_reset(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    texture->reset();

    return 0;
}

int lraspi_texture_tint(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 2));
    texture->tint(color);

    return 0;
}

int lraspi_texture_tint_color(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lraspi::lua::push(L, texture->getTintColor());

    return 1;
}

int lraspi_texture_set_blend_mode(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    const char* mode = luaL_checkstring(L, 2);

    if (std::strcmp(mode, "add") == 0) {
        texture->setSdlBlendMode(SDL_BLENDMODE_ADD);
    }
    else if (std::strcmp(mode, "mod") == 0)
    {
        texture->setSdlBlendMode(SDL_BLENDMODE_MOD);
    }
    else if (std::strcmp(mode, "blend") == 0)
    {
        texture->setSdlBlendMode(SDL_BLENDMODE_BLEND);
    }
    else if (std::strcmp(mode, "none") == 0)
    {
        texture->setSdlBlendMode(SDL_BLENDMODE_NONE);
    }
    else
    {
        const char* msg = lua_pushfstring(L, "must be `add', `mod', `blend' or `none'");
        return luaL_argerror(L, 2, msg);
    }

    return 0;
}

int lraspi_texture_get_blend_mode(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    const char* mode = luaL_checkstring(L, 2);

    if (texture->getSdlBlendMode() == SDL_BLENDMODE_ADD)
        lua_pushliteral(L, "add");
    else if (texture->getSdlBlendMode() == SDL_BLENDMODE_MOD)
        lua_pushliteral(L, "mod");
    else if (texture->getSdlBlendMode() == SDL_BLENDMODE_BLEND)
        lua_pushliteral(L, "blend");
    else if (texture->getSdlBlendMode() == SDL_BLENDMODE_NONE)
        lua_pushliteral(L, "none");

    return 1;
}

int lraspi_texture_set_alpha(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer alpha = luaL_checkinteger(L, 2);
    texture->setAlpha(alpha);

    return 0;
}

int lraspi_texture_get_alpha(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_pushinteger(L, texture->getAlpha());

    return 1;
}

int lraspi_texture_get_width(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer width = texture->getWidth();
    lua_pushinteger(L, width);

    return 1;
}

int lraspi_texture_get_height(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer height = texture->getHeight();
    lua_pushinteger(L, height);

    return 1;
}

int lraspi_texture_get_real_width(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer width = texture->getRealWidth();
    lua_pushinteger(L, width);

    return 1;   
}

int lraspi_texture_get_real_height(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer height = texture->getRealHeight();
    lua_pushinteger(L, height);

    return 1;
}

int lraspi_texture_resize(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    int width = luaL_checkinteger(L, 2);
    int height = luaL_checkinteger(L, 3);
    texture->setWidth(width);
    texture->setHeight(height);

    return 0;
}

int lraspi_texture_rotate(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Number angle = luaL_checknumber(L, 2);
    texture->setAngle(angle);

    return 0;
}

int lraspi_texture_set_center(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer x = luaL_checkinteger(L, 2);
    lua_Integer y = luaL_checkinteger(L, 3);
    texture->setCenter(x, y);

    return 0;
}

int lraspi_texture_get_center(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    SDL_Point point = texture->getSdlCenterPoint();
    lua_pushinteger(L, point.x);
    lua_pushinteger(L, point.y);

    return 2;
}

int lraspi_texture_v_flip(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    texture->setVFlip();

    return 0;
}

int lraspi_texture_h_flip(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    texture->setHFlip();

    return 0;
}

int lraspi_texture_is_flipped(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    SDL_RendererFlip flip = texture->getSdlFlipStatus();
    lua_pushboolean(L, flip & SDL_FLIP_VERTICAL);
    lua_pushboolean(L, flip & SDL_FLIP_HORIZONTAL);

    return 2;
}

int lraspi_texture_set_pixel(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    
    try
    {
        lua_Integer x = luaL_checkinteger(L, 2);
        lua_Integer y = luaL_checkinteger(L, 3);
        lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 4));
        texture->setPixel(x, y, color);
    }
    catch (lraspi::Exception& e)
    {
        return luaL_error(L, e.what());
    }

    return 0;
}

int lraspi_texture_get_pixel(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    
    lua_Integer x = luaL_checkinteger(L, 2);
    lua_Integer y = luaL_checkinteger(L, 3);
    lraspi::Color* color = texture->getPixel(x, y);
    lraspi::lua::push(L, color);

    return 1;
}

int lraspi_texture_free(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    delete texture;

    return 0;
}

// Texture module functions
static const luaL_Reg lraspi_texture_functions[] =
{
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
    {"free",          lraspi_texture_free},
    {0, 0}
};

int luaopen_texture(lua_State* L)
{
    luaL_newlib(L, lraspi_texture_functions);
    return 1;
}

}