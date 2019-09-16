/*
    lraspi/limage.cc - NEKERAFA - 13th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <cstring>

#include <lua.hpp>

#include "common/exception.h"
#include "modules/image/image.h"
#include "modules/image/module.h"

#include "lraspi/lauxlib.h"
#include "lraspi/ltexture.h"
#include "lraspi/limage.h"

extern "C"
{

int lraspi_image_init(lua_State* L)
{
    try
    {
        lraspi::image::init();
    }
    catch (lraspi::Exception e)
    {
        return luaL_error(L, e.what());
    }

    return 0;
}

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

int lraspi_image_close(lua_State* L)
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

// Image methods
static const luaL_Reg lraspi_image_methods[] =
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
    {"__gc",          lraspi_texture_free},
    {0, 0}
};

// Image modules functions
static const luaL_Reg lraspi_image_functions[] =
{
    {"init",       lraspi_image_init},
    {"new",        lraspi_image_new},
    {"close",      lraspi_image_close},
    {0, 0}
};

int luaopen_image(lua_State* L)
{
    lraspi::lua::registerobject(L, lraspi::Image::type, lraspi_image_methods);
    luaL_newlib(L, lraspi_image_functions);
    return 1;
}

}