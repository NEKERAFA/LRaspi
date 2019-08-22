/*
    lraspi/limage.cc - NEKERAFA - 13th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <cstring>

#include <lua.hpp>

#include "common/exception.h"
#include "modules/color/color.h"
#include "modules/image/texture.h"
#include "modules/image/image.h"
#include "modules/image/image_mod.h"

#include "lraspi/lauxlib.h"
#include "lraspi/limage.h"

extern "C"
{

static int lraspi_image_init(lua_State* L)
{
    try {
        lraspi::image::init();
    }
    catch (lraspi::Exception& e)
    {
        return luaL_error(L, e.what());
    }

    return 0;
}

static int lraspi_image_new(lua_State* L)
{
    try {
        lua_Integer width = luaL_checkinteger(L, 1);
        lua_Integer height = luaL_checkinteger(L, 2);
        lraspi::Texture* texture = lraspi::image::createBlankTexture(width, height);
        lraspi::lua::push(L, lraspi::Texture::type, texture);
    }
    catch (lraspi::Exception& e)
    {
        return luaL_error(L, e.what());
    }

    return 1;
}

static int lraspi_image_load(lua_State* L)
{
    try {
        const char* path = luaL_checkstring(L, 1);
        lraspi::Image* image = lraspi::image::loadImage(path);
        lraspi::lua::push(L, lraspi::Image::type, image);
    }
    catch (lraspi::Exception& e)
    {
        return luaL_error(L, e.what());
    }

    return 1;
}

static int lraspi_image_reset(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    texture->reset();

    return 0;
}

static int lraspi_image_tint(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 2));
    texture->tint(color);

    return 0;
}

static int lraspi_image_blend_mode(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    const char* mode = luaL_checkstring(L, 2);

    if (!std::strcmp(mode, "add")) {
        texture->setSdlBlendMode(SDL_BLENDMODE_ADD);
    }
    else if (!std::strcmp(mode, "mod"))
    {
        texture->setSdlBlendMode(SDL_BLENDMODE_MOD);
    }
    else if (!std::strcmp(mode, "blend"))
    {
        texture->setSdlBlendMode(SDL_BLENDMODE_BLEND);
    }
    else
    {
        texture->setSdlBlendMode(SDL_BLENDMODE_NONE);
    }

    return 0;
}

static int lraspi_image_set_alpha(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer alpha = luaL_checkinteger(L, 2);
    texture->setAlpha(alpha);

    return 0;
}

static int lraspi_image_set_width(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    int width = luaL_checkinteger(L, 2);
    texture->setWidth(width);

    return 0;
}

static int lraspi_image_set_height(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    int height = luaL_checkinteger(L, 2);
    texture->setHeight(height);

    return 0;
}

static int lraspi_image_get_width(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer width = texture->getWidth();
    lua_pushinteger(L, width);

    return 1;
}

static int lraspi_image_get_height(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer height = texture->getHeight();
    lua_pushinteger(L, height);

    return 1;
}

static int lraspi_image_get_real_width(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer width = texture->getRealWidth();
    lua_pushinteger(L, width);

    return 1;   
}

static int lraspi_image_get_real_height(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer height = texture->getRealHeight();
    lua_pushinteger(L, height);

    return 1;
}

static int lraspi_image_rotate(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Number angle = luaL_checknumber(L, 2);
    texture->setAngle(angle);

    return 0;
}

static int lraspi_image_set_center(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lua_Integer x = luaL_checkinteger(L, 2);
    lua_Integer y = luaL_checkinteger(L, 3);
    texture->setCenter(x, y);

    return 0;
}

static int lraspi_image_get_center(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    SDL_Point point = texture->getSdlCenterPoint();
    lua_pushinteger(L, point.x);
    lua_pushinteger(L, point.y);

    return 2;
}

static int lraspi_image_set_v_flip(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    texture->setVFlip();

    return 0;
}

static int lraspi_image_get_v_flip(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    SDL_RendererFlip flip = texture->getSdlFlipStatus();
    lua_pushboolean(L, flip & SDL_FLIP_VERTICAL);

    return 0;
}

static int lraspi_image_set_h_flip(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    texture->setHFlip();

    return 0;
}

static int lraspi_image_get_h_flip(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    SDL_RendererFlip flip = texture->getSdlFlipStatus();
    lua_pushboolean(L, flip & SDL_FLIP_HORIZONTAL);

    return 0;
}

static int lraspi_image_blit(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    lraspi::Texture* other = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 2));
    lua_Integer x = luaL_checkinteger(L, 3);
    lua_Integer y = luaL_checkinteger(L, 4);
    texture->blit(other, x, y);

    return 0;
}

static int lraspi_image__gc(lua_State* L)
{
    lraspi::Texture* texture = static_cast<lraspi::Texture*>(lraspi::lua::check(L, lraspi::Texture::type, 1));
    delete texture;

    return 0;
}

static int lraspi_image_close(lua_State* L)
{
    try
    {
        lraspi::image::close();
    }
    catch(lraspi::Exception& e)
    {
        return luaL_error(L, e.what());
    }

    return 0;
}

static const luaL_Reg lraspi_texture_object[] =
{
    {"reset",         lraspi_image_reset},
    {"tint",          lraspi_image_tint},
    {"setAlpha",      lraspi_image_set_alpha},
    {"rotate",        lraspi_image_rotate},
    {"setCenter",     lraspi_image_set_center},
    {"getCenter",     lraspi_image_get_center},
    {"setVFlip",      lraspi_image_set_v_flip},
    {"getVFlip",      lraspi_image_get_v_flip},
    {"setHFlip",      lraspi_image_set_h_flip},
    {"getHFlip",      lraspi_image_get_h_flip},
    {"setWidth",      lraspi_image_set_width},
    {"getWidth",      lraspi_image_get_width},
    {"getRealWidth",  lraspi_image_get_real_width},
    {"setHeight",     lraspi_image_set_height},
    {"getHeight",     lraspi_image_get_height},
    {"getRealHeight", lraspi_image_get_real_height},
    {"setBlendMode",  lraspi_image_blend_mode},
    {"__gc",          lraspi_image__gc},
    {0, 0}
};

static const luaL_Reg lraspi_image[] =
{
    {"init",          lraspi_image_init},
    {"new",           lraspi_image_new},
    {"load",          lraspi_image_load},
    {"reset",         lraspi_image_reset},
    {"tint",          lraspi_image_tint},
    {"setAlpha",      lraspi_image_set_alpha},
    {"rotate",        lraspi_image_rotate},
    {"setCenter",     lraspi_image_set_center},
    {"getCenter",     lraspi_image_get_center},
    {"setVFlip",      lraspi_image_set_v_flip},
    {"getVFlip",      lraspi_image_get_v_flip},
    {"setHFlip",      lraspi_image_set_h_flip},
    {"getHFlip",      lraspi_image_get_h_flip},
    {"setWidth",      lraspi_image_set_width},
    {"getWidth",      lraspi_image_get_width},
    {"getRealWidth",  lraspi_image_get_real_width},
    {"setHeight",     lraspi_image_set_height},
    {"getHeight",     lraspi_image_get_height},
    {"getRealHeight", lraspi_image_get_real_height},
    {"setBlendMode",  lraspi_image_blend_mode},
    {"free",          lraspi_image__gc},
    {"close",         lraspi_image_close},
    {0, 0}
};

int luaopen_image(lua_State* L)
{
    lraspi::lua::registerobject(L, lraspi::Texture::type, lraspi_texture_object);
    lraspi::lua::registerobject(L, lraspi::Image::type, lraspi_texture_object);
    luaL_newlib(L, lraspi_image);
    return 1;
}

}