/*
    include/modules/draw/module.h - NEKERAFA - 12th sep 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_MODULE_DRAW_H
#define LRASPI_MODULE_DRAW_H

#include "modules/color/color.h"

namespace lraspi
{

namespace draw
{

/**
 * @brief Represents the mode of draw the shape
 */
enum DrawMode {
    FILL,   /**< Draws the filled shape */
    OUTLINE, /**< Draws the outlined shape */
    MODE_NONE 
};

/**
 * @brief The type of the arc to draw
 */
enum ArcType {
    PIE,   /**< The arc is drawn connecting the ends of the border with the center*/
    OPEN,  /**< The arc is drawn unconnecting the ends of the border*/
    CLOSED, /**< The arc is drawn connecting the ends of the border each other*/
    TYPE_NONE
};

/**
 * @brief Draw a point
 * 
 * @param x The x-axis position of the point
 * @param y The y-axis position of the point
 * @param color The color of the point
 */
void point(float x, float y, Color* color);

/**
 * @brief Draw a line
 * 
 * @param x1 The x-axis position of the initial point
 * @param y1 The y-axis position of the initial point
 * @param x2 The x-axis position of the final point
 * @param y2 The y-axis position of the final point
 * @param color The color of the line
 */
void line(float x1, float y1, float x2, float y2, Color* color);

/**
 * @brief Draw a line with gradient effect
 * 
 * @param x1 The x-axis position of the initial point
 * @param y1 The y-axis position of the initial point
 * @param x2 The x-axis position of the final point
 * @param y2 The y-axis position of the final point
 * @param color1 The initial color of the line
 * @param color2 The final color of the line
 */
void gradLine(float x1, float y1, float x2, float y2, Color* color1, Color* color2);

/**
 * @brief Draw a triangle
 * 
 * @param mode The mode to draw the triangle
 * @param x1 The x-axis position of the initial point
 * @param y1 The y-axis position of the initial point
 * @param x2 The x-axis position of the medium point
 * @param y2 The y-axis position of the medium point
 * @param x3 The x-axis position of the final point
 * @param y4 The y-axis position of the final point
 * @param color The color of the triangle
 */
void triangle(DrawMode mode, float x1, float y1, float x2, float y2, float x3, float y3, Color* color);

/**
 * @brief Draw a triangle with gradient effect
 * 
 * @param mode The mode to draw the triangle
 * @param x1 The x-axis position of the initial point
 * @param y1 The y-axis position of the initial point
 * @param x2 The x-axis position of the medium point
 * @param y2 The y-axis position of the medium point
 * @param x3 The x-axis position of the final point
 * @param y4 The y-axis position of the final point
 * @param color1 The color in the initial point
 * @param color2 The color in the medium point
 * @param color3 The color in the final point
 */
void gradTriangle(DrawMode mode, float x1, float y1, float x2, float y2, float x3, float y3, Color* color1, Color* color2, Color* col3);

/**
 * @brief Draw a rectangle
 * 
 * @param mode The mode to draw the rectangle
 * @param x The x-axis position of the top left point
 * @param y The y-axis position of the top left point
 * @param w The width of the rectangle
 * @param h The height of the rectangle
 * @param color The color of the rectangle
 */
void rectangle(DrawMode mode, float x, float y, float w, float h, Color* color);

/**
 * @brief Draw a rectangle with gradient effect
 * 
 * @param mode The mode to draw the rectangle
 * @param x The x-axis position of the top left point
 * @param y The y-axis position of the top left point
 * @param w The width of the rectangle
 * @param h The height of the rectangle
 * @param color1 The color in the top left point
 * @param color2 The color in the top right point
 * @param color3 The color in the bottom right point
 * @param color4 The color in the bottom left point
 */
void gradRectangle(DrawMode mode, float x, float y, float w, float h, Color* color1, Color* color2, Color* col3, Color* col4);

/**
 * @brief Draw an ellipse
 * 
 * @param mode The mode to draw the ellipse
 * @param x The position of the center along the x-axis
 * @param y The position of the center along the y-axis
 * @param radiusx The radius of the ellipse along the x-axis (a half of the ellipse width)
 * @param radiusy The radius of the ellipse along the y-axis (a half of the ellipse height)
 * @param color The color of the ellipse
 * @param segments The number of segments used for drawing the ellipse
 */
void ellipse(DrawMode mode, float x, float y, double radiusx, double radiusy, Color* color, int segments);

/**
 * @brief Draw an ellipse with gradient effect
 * 
 * @param mode The mode to draw the ellipse
 * @param x The position of the center along the x-axis
 * @param y The position of the center along the y-axis
 * @param radiusx The radius of the ellipse along the x-axis (a half of the ellipse width)
 * @param radiusy The radius of the ellipse along the y-axis (a half of the ellipse height)
 * @param color1 The color in the center of the ellipse
 * @param color2 The color in the border of the ellipse
 * @param segments The number of segments used for drawing the ellipse
 */
void gradEllipse(DrawMode mode, float x, float y, double radiusx, double radiusy, Color* color1, Color* color2, int segments);

/**
 * @brief Draw an ellipse arc
 * 
 * @param mode The mode to draw the ellipse arc
 * @param type The type of the ellipse arc
 * @param x The position of the center along the x-axis
 * @param y The position of the center along the y-axis
 * @param radiusx The radius of the ellipse along the x-axis (a half of the ellipse width)
 * @param radiusy The radius of the ellipse along the y-axis (a half of the ellipse height)
 * @param angle1 The angle at which the arc starts
 * @param angle2 The angle at which the arc ends
 * @param color The color of the arc
 * @param segments The number of segments used for drawing the arc
 */
void arc(DrawMode mode, ArcType type, float x, float y, double radiusx, double radiusy, double angle1, double angle2, Color* color, int segments);

/**
 * @brief Draw an ellipse arc with gradient effect
 * 
 * @param mode The mode to draw the ellipse arc
 * @param type The type of the ellipse arc
 * @param x The position of the center along the x-axis
 * @param y The position of the center along the y-axis
 * @param radiusx The radius of the ellipse along the x-axis (a half of the ellipse width)
 * @param radiusy The radius of the ellipse along the y-axis (a half of the ellipse height)
 * @param angle1 The angle at which the arc starts
 * @param angle2 The angle at which the arc ends
 * @param color1 The color in the center of the arc
 * @param color2 The color in the border of the arc
 * @param segments The number of segments used for drawing the arc
 */
void gradArc(DrawMode mode, ArcType type, float x, float y, double radiusx, double radiusy, double angle1, double angle2, Color* color1, Color* color2, int segments);

} // namespace draw

} // namespace lraspi

#endif // LRASPI_MODULE_DRAW_H