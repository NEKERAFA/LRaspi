/*
    lraspi/lcanvas.h - NEKERAFA - 16th sep 2019

    See Copyright Notice in lraspi.h 
 */

#include <lua.hpp>

#include "modules/draw/canvas.h"

#include "lraspi/lauxlib.h"
#include "lraspi/ldraw.h"

extern "C" {

// Canvas methods
static const luaL_Reg lraspi_canvas_methods[] =
{
    {"reset",         lraspi_draw_reset},
    {"tint",          lraspi_draw_tint},
    {"tintcolor",     lraspi_draw_tint_color},
    {"getalpha",      lraspi_draw_get_alpha},
    {"setalpha",      lraspi_draw_set_alpha},
    {"rotate",        lraspi_draw_rotate},
    {"getcenter",     lraspi_draw_get_center},
    {"setcenter",     lraspi_draw_set_center},
    {"vflip",         lraspi_draw_v_flip},
    {"hflip",         lraspi_draw_h_flip},
    {"isflipped",     lraspi_draw_is_flipped},
    {"getwidth",      lraspi_draw_get_width},
    {"getheight",     lraspi_draw_get_height},
    {"getrealwidth",  lraspi_draw_get_real_width},
    {"getrealheight", lraspi_draw_get_real_height},
    {"resize",        lraspi_draw_resize},
    {"getblendmode",  lraspi_draw_get_blend_mode},
    {"setblendmode",  lraspi_draw_set_blend_mode},
    {"getpixel",      lraspi_draw_get_pixel},
    {"setpixel",      lraspi_draw_set_pixel},
    {"free",          lraspi_draw_free},
    {"__gc",          lraspi_draw_free},
    {0, 0}
};

int luaopen_canvas(lua_State* L)
{
    lraspi::lua::registerobject(L, lraspi::Canvas::type, lraspi_canvas_methods);
    return 0;
}

}