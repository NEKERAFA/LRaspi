/*
    include/modules/draw/module.h - NEKERAFA - 12th sep 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_MODULE_DRAW_H
#define LRASPI_MODULE_DRAW_H

#include "modules/color/color.h"
#include "modules/draw/canvas.h"
#include "modules/draw/text.h"

namespace lraspi
{

namespace draw
{

/**
 * @brief Represents the mode of draw the shape
 */
enum DrawMode {
    FILL,   /**< Draws the filled shape */
    OUTLINE /**< Draws the outlined shape */
};

/**
 * @brief The type of the arc to draw
 */
enum ArcType {
    PIE,   /**< The arc is drawn connecting the ends of the border with the center*/
    OPEN,  /**< The arc is drawn unconnecting the ends of the border*/
    CLOSED /**< The arc is drawn connecting the ends of the border each other*/
};

/**
 * @brief Draw a point
 * 
 * @param x The x-axis position of the point
 * @param y The y-axis position of the point
 * @param col The color of the point
 */
void point(int x, int y, Color* col);

/**
 * @brief Draw a line
 * 
 * @param x1 The x-axis position of the initial point
 * @param y1 The y-axis position of the initial point
 * @param x2 The x-axis position of the final point
 * @param y2 The y-axis position of the final point
 * @param col The color of the line
 */
void line(int x1, int y1, int x2, int y2, Color* col);

/**
 * @brief Draw a line with gradient effect
 * 
 * @param x1 The x-axis position of the initial point
 * @param y1 The y-axis position of the initial point
 * @param x2 The x-axis position of the final point
 * @param y2 The y-axis position of the final point
 * @param col1 The initial color of the line
 * @param col2 The final color of the line
 */
void gradLine(int x1, int y1, int x2, int y2, Color* col1, Color* col2);

/**
 * @brief Draw a triangle
 * 
 * @param x1 The x-axis position of the initial point
 * @param y1 The y-axis position of the initial point
 * @param x2 The x-axis position of the medium point
 * @param y2 The y-axis position of the medium point
 * @param x3 The x-axis position of the final point
 * @param y4 The y-axis position of the final point
 * @param col The color of the triangle
 */
void triangle(DrawMode mode, int x1, int y1, int x2, int y2, int x3, int y3, Color* col);

/**
 * @brief Draw a triangle with gradient effect
 * 
 * @param mode The mode to draw the rectangle
 * @param x1 The x-axis position of the initial point
 * @param y1 The y-axis position of the initial point
 * @param x2 The x-axis position of the medium point
 * @param y2 The y-axis position of the medium point
 * @param x3 The x-axis position of the final point
 * @param y4 The y-axis position of the final point
 * @param col1 The color in the initial point
 * @param col2 The color in the medium point
 * @param col3 The color in the final point
 */
void gradTriangle(DrawMode mode, int x1, int y1, int x2, int y2, int x3, int y3, Color* col1, Color* col2, Color* col3);

/**
 * @brief Draw a rectangle
 * 
 * @param mode The mode to draw the rectangle
 * @param x The x-axis position of the top left point
 * @param y The y-axis position of the top left point
 * @param w The width of the rectangle
 * @param h The height of the rectangle
 * @param col The color of the rectangle
 */
void rectangle(DrawMode mode, int x, int y, int w, int h, Color* col);

/**
 * @brief Draw a rectangle with gradient effect
 * 
 * @param mode The mode to draw the rectangle
 * @param x The x-axis position of the top left point
 * @param y The y-axis position of the top left point
 * @param w The width of the rectangle
 * @param h The height of the rectangle
 * @param col1 The color in the top left point
 * @param col2 The color in the top right point
 * @param col3 The color in the bottom right point
 * @param col4 The color in the bottom left point
 */
void gradRectangle(DrawMode mode, int x, int y, int w, int h, Color* col1, Color* col2, Color* col3, Color* col4);

/**
 * @brief Draw an ellipse
 * 
 * @param mode The mode to draw the ellipse
 * @param x The position of the center along the x-axis
 * @param y The position of the center along the y-axis
 * @param radiusx The radius of the ellipse along the x-axis (a half of the ellipse width)
 * @param radiusy The radius of the ellipse along the y-axis (a half of the ellipse height)
 * @param col The color of the ellipse
 * @param segments The number of segments used for drawing the ellipse
 */
void ellipse(DrawMode mode, int x, int y, double radiusx, double radiusy, Color* col, int segments);

/**
 * @brief Draw an ellipse with gradient effect
 * 
 * @param mode The mode to draw the ellipse
 * @param x The position of the center along the x-axis
 * @param y The position of the center along the y-axis
 * @param radiusx The radius of the ellipse along the x-axis (a half of the ellipse width)
 * @param radiusy The radius of the ellipse along the y-axis (a half of the ellipse height)
 * @param col1 The color in the center of the ellipse
 * @param col2 The color in the border of the ellipse
 * @param segments The number of segments used for drawing the ellipse
 */
void gradEllipse(DrawMode mode, int x, int y, double radiusx, double radiusy, Color* col1, Color* col2, int segments);

/**
 * @brief Draw a circle
 * This function is equals to a ellipse with the same radius in x-axis and y-axis.
 * 
 * @param mode The mode to draw the circle
 * @param x The position of the center along the x-axis
 * @param y The position of the center along the y-axis
 * @param radius The radius of the circle
 * @param col The color of the circle
 * @param segments The number of segments used for drawing the circle
 */
void circle(DrawMode mode, int x, int y, double radius, Color* col, int segments);

/**
 * @brief Draw a circle with gradient effect
 * 
 * @param mode The mode to draw the circle
 * @param x The position of the center along the x-axis
 * @param y The position of the center along the y-axis
 * @param radius The radius of the circle
 * @param col1 The color in the center of the circle
 * @param col2 The color in the border of the circle
 * @param segments The number of segments used for drawing the circle
 */
void gradCircle(DrawMode mode, int x, int y, double radius, Color* col1, Color* col2, int segments);

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
 * @param col The color of the arc
 * @param segments The number of segments used for drawing the arc
 */
void arc(DrawMode mode, ArcType type, int x, int y, double radiusx, double radiusy, double angle1, double angle2, Color* col, int segments);

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
 * @param col1 The color in the center of the arc
 * @param col2 The color in the border of the arc
 * @param segments The number of segments used for drawing the arc
 */
void gradArc(DrawMode mode, int x, int y, double radiusx, double radiusy, double angle1, double angle2, Color* col1, Color* col2, int segments);

/**
 * @brief Create a canvas
 * 
 * @param width The width of the canvas
 * @param height The height of the canvas
 * @return A lraspi::Canvas object
 */
Canvas* newCanvas(int width, int height);

/**
 * @brief Create a text object
 * 
 * @param font A lraspi::Font object
 * @param text The text to render
 * @return A lraspi::Text object
 */
Text* newText(Font* font, const char* str);

} // namespace draw

} // namespace lraspi

#endif // LRASPI_MODULE_DRAW_H