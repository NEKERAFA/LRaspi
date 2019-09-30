/*
    lraspi/ldraw.h - NEKERAFA - 16th sep 2019

    See Copyright Notice in lraspi.h 
 */

#include <cstring>

#include <lua.hpp>

#include "modules/common/exception.h"
#include "modules/draw/module.h"

#include "lraspi/lauxlib.h"
#include "lraspi/ldraw.h"

extern "C" {

int lraspi_draw_point(lua_State* L)
{
    float x = luaL_checknumber(L, 1);
    float y = luaL_checknumber(L, 2);
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 3));
    lraspi::draw::point(x, y, color);

    return 0;
}

int lraspi_draw_line(lua_State* L)
{
    float x1 = luaL_checknumber(L, 1);
    float y1 = luaL_checknumber(L, 2);
    float x2 = luaL_checknumber(L, 3);
    float y2 = luaL_checknumber(L, 4);
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 5));
    lraspi::draw::line(x1, y1, x2, y2, color);

    return 0;
}

int lraspi_draw_grad_line(lua_State* L)
{
    float x1 = luaL_checknumber(L, 1);
    float y1 = luaL_checknumber(L, 2);
    float x2 = luaL_checknumber(L, 3);
    float y2 = luaL_checknumber(L, 4);
    lraspi::Color* color1 = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 5));
    lraspi::Color* color2 = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 6));
    lraspi::draw::gradLine(x1, y1, x2, y2, color1, color2);

    return 0;
}

lraspi::draw::DrawMode lraspi_draw_get_draw_mode(const char* mode)
{
    if (std::strcmp(mode, "fill") == 0)
        return lraspi::draw::FILL;
    
    if (std::strcmp(mode, "outline") == 0)
        return lraspi::draw::OUTLINE;

    return lraspi::draw::MODE_NONE;
}

int lraspi_draw_triangle(lua_State* L)
{
    const char* strmode = luaL_checkstring(L, 1);
    lraspi::draw::DrawMode mode = lraspi_draw_get_draw_mode(strmode);
    if (mode == lraspi::draw::MODE_NONE)
    {
        const char* msg = lua_pushfstring(L, "must be `fill' or `outline'");
        luaL_argerror(L, 1, msg);
    }

    int x1 = luaL_checknumber(L, 2);
    int y1 = luaL_checknumber(L, 3);
    int x2 = luaL_checknumber(L, 4);
    int y2 = luaL_checknumber(L, 5);
    int x3 = luaL_checknumber(L, 6);
    int y3 = luaL_checknumber(L, 7);
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 8));
    lraspi::draw::triangle(mode, x1, y1, x2, y2, x3, y3, color);

    return 0;
}

int lraspi_draw_grad_triangle(lua_State* L)
{
    const char* strmode = luaL_checkstring(L, 1);
    lraspi::draw::DrawMode mode = lraspi_draw_get_draw_mode(strmode);
    if (mode == lraspi::draw::MODE_NONE)
    {
        const char* msg = lua_pushfstring(L, "must be `fill' or `outline'");
        luaL_argerror(L, 1, msg);
    }

    int x1 = luaL_checknumber(L, 2);
    int y1 = luaL_checknumber(L, 3);
    int x2 = luaL_checknumber(L, 4);
    int y2 = luaL_checknumber(L, 5);
    int x3 = luaL_checknumber(L, 6);
    int y3 = luaL_checknumber(L, 7);
    lraspi::Color* color1 = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 8));
    lraspi::Color* color2 = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 9));
    lraspi::Color* color3 = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 10));
    lraspi::draw::gradTriangle(mode, x1, y1, x2, y2, x3, y3, color1, color2, color3);

    return 0;
}

int lraspi_draw_rectangle(lua_State* L)
{
    const char* strmode = luaL_checkstring(L, 1);
    lraspi::draw::DrawMode mode = lraspi_draw_get_draw_mode(strmode);
    if (mode == lraspi::draw::MODE_NONE)
    {
        const char* msg = lua_pushfstring(L, "must be `fill' or `outline'");
        luaL_argerror(L, 1, msg);
    }

    int x = luaL_checknumber(L, 2);
    int y = luaL_checknumber(L, 3);
    int w = luaL_checknumber(L, 4);
    int h = luaL_checknumber(L, 5);
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 6));
    lraspi::draw::rectangle(mode, x, y, w, h, color);

    return 0;
}

int lraspi_draw_grad_rectangle(lua_State* L)
{
    const char* strmode = luaL_checkstring(L, 1);
    lraspi::draw::DrawMode mode = lraspi_draw_get_draw_mode(strmode);
    if (mode == lraspi::draw::MODE_NONE)
    {
        const char* msg = lua_pushfstring(L, "must be `fill' or `outline'");
        luaL_argerror(L, 1, msg);
    }

    int x = luaL_checknumber(L, 2);
    int y = luaL_checknumber(L, 3);
    int w = luaL_checknumber(L, 4);
    int h = luaL_checknumber(L, 5);
    lraspi::Color* color1 = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 6));
    lraspi::Color* color2 = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 7));
    lraspi::Color* color3 = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 8));
    lraspi::Color* color4 = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 9));
    lraspi::draw::gradRectangle(mode, x, y, w, h, color1, color2, color3, color4);

    return 0;
}

int lraspi_draw_ellipse(lua_State* L)
{
    const char* strmode = luaL_checkstring(L, 1);
    lraspi::draw::DrawMode mode = lraspi_draw_get_draw_mode(strmode);
    if (mode == lraspi::draw::MODE_NONE)
    {
        const char* msg = lua_pushfstring(L, "must be `fill' or `outline'");
        luaL_argerror(L, 1, msg);
    }

    int x = luaL_checknumber(L, 2);
    int y = luaL_checknumber(L, 3);
    double rx = luaL_checknumber(L, 4);
    double ry = luaL_checknumber(L, 5);
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 6));
    int segments = luaL_checknumber(L, 7);
    lraspi::draw::ellipse(mode, x, y, rx, ry, color, segments);

    return 0;
}

int lraspi_draw_grad_ellipse(lua_State* L)
{
    const char* strmode = luaL_checkstring(L, 1);
    lraspi::draw::DrawMode mode = lraspi_draw_get_draw_mode(strmode);
    if (mode == lraspi::draw::MODE_NONE)
    {
        const char* msg = lua_pushfstring(L, "must be `fill' or `outline'");
        luaL_argerror(L, 1, msg);
    }

    int x = luaL_checknumber(L, 2);
    int y = luaL_checknumber(L, 3);
    double rx = luaL_checknumber(L, 4);
    double ry = luaL_checknumber(L, 5);
    lraspi::Color* color1 = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 6));
    lraspi::Color* color2 = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 7));
    int segments = luaL_checknumber(L, 8);
    lraspi::draw::gradEllipse(mode, x, y, rx, ry, color1, color2, segments);

    return 0;
}

lraspi::draw::ArcType lraspi_draw_get_arc_type(const char* type)
{
    if (std::strcmp(type, "pie") == 0)
        return lraspi::draw::PIE;
    
    if (std::strcmp(type, "open") == 0)
        return lraspi::draw::OPEN;
    
    if (std::strcmp(type, "closed") == 0)
        return lraspi::draw::CLOSED;

    return lraspi::draw::TYPE_NONE;
}

int lraspi_draw_arc(lua_State* L)
{
    const char* strmode = luaL_checkstring(L, 1);
    lraspi::draw::DrawMode mode = lraspi_draw_get_draw_mode(strmode);
    if (mode == lraspi::draw::MODE_NONE)
    {
        const char* msg = lua_pushfstring(L, "must be `fill' or `outline'");
        luaL_argerror(L, 1, msg);
    }

    const char* strtype = luaL_checkstring(L, 2);
    lraspi::draw::ArcType type = lraspi_draw_get_arc_type(strtype);
    if (type == lraspi::draw::TYPE_NONE)
    {
        const char* msg = lua_pushfstring(L, "must be `pie', `open' or `closed'");
        luaL_argerror(L, 2, msg);
    }

    int x = luaL_checknumber(L, 3);
    int y = luaL_checknumber(L, 4);
    double rx = luaL_checknumber(L, 5);
    double ry = luaL_checknumber(L, 6);
    double angle1 = luaL_checknumber(L, 7);
    double angle2 = luaL_checknumber(L, 8);
    lraspi::Color* color = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 9));
    int segments = luaL_checknumber(L, 10);
    lraspi::draw::arc(mode, type, x, y, rx, ry, angle1, angle2, color, segments);

    return 0;
}

int lraspi_draw_grad_arc(lua_State* L)
{
    const char* strmode = luaL_checkstring(L, 1);
    lraspi::draw::DrawMode mode = lraspi_draw_get_draw_mode(strmode);
    if (mode == lraspi::draw::MODE_NONE)
    {
        const char* msg = lua_pushfstring(L, "must be `fill' or `outline'");
        luaL_argerror(L, 1, msg);
    }

    const char* strtype = luaL_checkstring(L, 2);
    lraspi::draw::ArcType type = lraspi_draw_get_arc_type(strtype);
    if (type == lraspi::draw::TYPE_NONE)
    {
        const char* msg = lua_pushfstring(L, "must be `pie', `open' or `closed'");
        luaL_argerror(L, 2, msg);
    }

    int x = luaL_checknumber(L, 3);
    int y = luaL_checknumber(L, 4);
    double rx = luaL_checknumber(L, 5);
    double ry = luaL_checknumber(L, 6);
    double angle1 = luaL_checknumber(L, 7);
    double angle2 = luaL_checknumber(L, 8);
    lraspi::Color* color1 = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 9));
    lraspi::Color* color2 = static_cast<lraspi::Color*>(lraspi::lua::check(L, lraspi::Color::type, 10));
    int segments = luaL_checknumber(L, 11);
    lraspi::draw::gradArc(mode, type, x, y, rx, ry, angle1, angle2, color1, color2, segments);

    return 0;
}

// Draw module functions
static const luaL_Reg lraspi_draw_functions[] =
{
    {"point",         lraspi_draw_point},
    {"gradline",      lraspi_draw_grad_line},
    {"line",          lraspi_draw_line},
    {"triangle",      lraspi_draw_triangle},
    {"gradtriangle",  lraspi_draw_grad_triangle},
    {"rectangle",     lraspi_draw_rectangle},
    {"gradrectangle", lraspi_draw_grad_rectangle},
    {"ellipse",       lraspi_draw_ellipse},
    {"gradellipse",   lraspi_draw_grad_ellipse},
    {"arc",           lraspi_draw_arc},
    {"gradarc",       lraspi_draw_grad_arc},
    {0, 0}
};

int luaopen_draw(lua_State* L)
{
    luaL_newlib(L, lraspi_draw_functions);
    return 1;
}

}