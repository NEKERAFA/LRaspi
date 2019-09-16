/*
    lraspi/lcanvas.h - NEKERAFA - 16th sep 2019

    See Copyright Notice in lraspi.h 
 */

#include <lua.hpp>

#include "modules/draw/canvas.h"

#include "lraspi/lauxlib.h"
#include "lraspi/ltexture.h"

extern "C" {

// Canvas methods
static const luaL_Reg lraspi_canvas_methods[] =
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

int luaopen_canvas(lua_State* L)
{
    lraspi::lua::registerobject(L, lraspi::Canvas::type, lraspi_canvas_methods);
    return 0;
}

}