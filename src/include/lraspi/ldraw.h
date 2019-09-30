/*
    include/lraspi/ldraw.h - NEKERAFA - 16th sep 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_DRAW_LUA_H
#define LRASPI_DRAW_LUA_H

#include <lua.hpp>

/***
 * 2D simple drawing rendering
 * @module Draw
 */

/***
 * Draws a point
 * @function draw.point
 * @number x The x-axis position of the point
 * @number y The y-axis position of the point
 * @tparam color color The color of the point
 */

/***
 * Draws a line
 * @function draw.line
 * @number x1 The x-axis position of the initial point
 * @number y1 The y-axis position of the initial point
 * @number x2 The x-axis position of the final point
 * @number y2 The y-axis position of the final point
 * @tparam color color The color of the line
 */

/***
 * Draws a line with gradient effect
 * @function draw.gradline
 * @number x1 The x-axis position of the initial point
 * @number y1 The y-axis position of the initial point
 * @number x2 The x-axis position of the final point
 * @number y2 The y-axis position of the final point
 * @tparam color color1 The initial color of the line
 * @tparam color color2 The final color of the line
 */

/**
 * Draws a triangle
 * @function draw.triangle
 * @string mode A string that controls whether shapes are draw, as the following values:
 * <ul>
 * <li><span class='parameter'>fill</span> for draw filled shape</li>
 * <li><span class='parameter'>outline</span> for draw outlined shape</li>
 * </ul>
 * @number x1 The x-axis position of the initial point
 * @number y1 The y-axis position of the initial point
 * @number x2 The x-axis position of the medium point
 * @number y2 The y-axis position of the medium point
 * @number x3 The x-axis position of the final point
 * @number y4 The y-axis position of the final point
 * @tparam color color The color of the triangle
 */

/**
 * Draws a triangle with gradient effect
 * @function draw.gradtriangle
 * @string mode A string that controls whether shapes are draw, as the following values:
 * <ul>
 * <li><span class='parameter'>fill</span> for draw filled shape</li>
 * <li><span class='parameter'>outline</span> for draw outlined shape</li>
 * </ul>
 * @number x1 The x-axis position of the initial point
 * @number y1 The y-axis position of the initial point
 * @number x2 The x-axis position of the medium point
 * @number y2 The y-axis position of the medium point
 * @number x3 The x-axis position of the final point
 * @number y4 The y-axis position of the final point
 * @tparam color color1 The color in the initial point
 * @tparam color color2 The color in the medium point
 * @tparam color color3 The color in the final point
 */

/**
 * Draws a rectangle
 * @function draw.rectangle
 * @string mode A string that controls whether shapes are draw, as the following values:
 * <ul>
 * <li><span class='parameter'>fill</span> for draw filled shape</li>
 * <li><span class='parameter'>outline</span> for draw outlined shape</li>
 * </ul>
 * @number x The x-axis position of the top left point
 * @number y The y-axis position of the top left point
 * @number w The width of the rectangle
 * @number h The height of the rectangle
 * @tparam color color The color of the rectangle
 */

/**
 * Draws a rectangle with gradient effect
 * @function draw.gradrectangle
 * @string mode A string that controls whether shapes are draw, as the following values:
 * <ul>
 * <li><span class='parameter'>fill</span> for draw filled shape</li>
 * <li><span class='parameter'>outline</span> for draw outlined shape</li>
 * </ul>
 * @number x The x-axis position of the top left point
 * @number y The y-axis position of the top left point
 * @number w The width of the rectangle
 * @number h The height of the rectangle
 * @tparam color color1 The color in the top left point
 * @tparam color color2 The color in the top right point
 * @tparam color color3 The color in the bottom right point
 * @tparam color color4 The color in the bottom left point
 */

/**
 * Draws an ellipse
 * @function draw.ellipse
 * @string mode A string that controls whether shapes are draw, as the following values:
 * <ul>
 * <li><span class='parameter'>fill</span> for draw filled shape</li>
 * <li><span class='parameter'>outline</span> for draw outlined shape</li>
 * </ul>
 * @number x The position of the center along the x-axis
 * @number y The position of the center along the y-axis
 * @number radiusx The radius of the ellipse along the x-axis (a half of the ellipse width)
 * @number radiusy The radius of the ellipse along the y-axis (a half of the ellipse height)
 * @tparam color color The color of the ellipse
 * @number segments The number of segments used for drawing the ellipse
 */

/**
 * Draws an ellipse with gradient effect
 * @function draw.gradellipse
 * @string mode A string that controls whether shapes are draw, as the following values:
 * <ul>
 * <li><span class='parameter'>fill</span> for draw filled shape</li>
 * <li><span class='parameter'>outline</span> for draw outlined shape</li>
 * </ul>
 * @number x The position of the center along the x-axis
 * @number y The position of the center along the y-axis
 * @number radiusx The radius of the ellipse along the x-axis (a half of the ellipse width)
 * @number radiusy The radius of the ellipse along the y-axis (a half of the ellipse height)
 * @tparam color color1 The color in the center of the ellipse
 * @tparam color color2 The color in the border of the ellipse
 * @number segments The number of segments used for drawing the ellipse
 */

/**
 * Draws an ellipse arc
 * @function draw.arc
 * @string mode A string that controls whether shapes are draw, as the following values:
 * <ul>
 * <li><span class='parameter'>fill</span> for draw filled shape</li>
 * <li><span class='parameter'>outline</span> for draw outlined shape</li>
 * </ul>
 * @string type A string that controls the type of arc, as the following values:
 * <ul>
 * <li><span class='parameter'>pie</span> for draw the arc as a slice of pie, connecting the end-points with the center</li>
 * <li><span class='parameter'>open</span> for draw the arc without the end-points unconnected</li>
 * <li><span class='parameter'>closed</span> for draw the arc with the end-points connected to each other</li>
 * </ul>
 * @number x The position of the center along the x-axis
 * @number y The position of the center along the y-axis
 * @number radiusx The radius of the ellipse along the x-axis (a half of the ellipse width)
 * @number radiusy The radius of the ellipse along the y-axis (a half of the ellipse height)
 * @number angle1 The angle at which the arc starts
 * @number angle2 The angle at which the arc ends
 * @tparam color color The color of the arc
 * @number segments The number of segments used for drawing the arc
 */

/**
 * Draws an ellipse arc with gradient effect
 * @function draw.gradarc
 * @string mode A string that controls whether shapes are draw, as the following values:
 * <ul>
 * <li><span class='parameter'>fill</span> for draw filled shape</li>
 * <li><span class='parameter'>outline</span> for draw outlined shape</li>
 * </ul>
 * @string type A string that controls the type of arc, as the following values:
 * <ul>
 * <li><span class='parameter'>pie</span> for draw the arc as a slice of pie, connecting the end-points with the center</li>
 * <li><span class='parameter'>open</span> for draw the arc without the end-points unconnected</li>
 * <li><span class='parameter'>closed</span> for draw the arc with the end-points connected to each other</li>
 * </ul>
 * @number x The position of the center along the x-axis
 * @number y The position of the center along the y-axis
 * @number radiusx The radius of the ellipse along the x-axis (a half of the ellipse width)
 * @number radiusy The radius of the ellipse along the y-axis (a half of the ellipse height)
 * @number angle1 The angle at which the arc starts
 * @number angle2 The angle at which the arc ends
 * @tparam color color1 The color in the center of the arc
 * @tparam color color2 The color in the border of the arc
 * @number segments The number of segments used for drawing the arc
 */

extern "C" {

int luaopen_draw(lua_State* L);

}

#endif // LRASPI_DRAW_LUA_H