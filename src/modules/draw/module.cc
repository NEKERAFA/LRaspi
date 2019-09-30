/*
    modules/draw/module.cc - NEKERAFA - 13th sep 2019

    See Copyright Notice in lraspi.h 
 */

#include <cmath>
#include <iostream>
#include <algorithm>

#include <GL/glu.h>

#include "modules/color/color.h"
#include "modules/screen/module.h"
#include "modules/draw/module.h"

namespace lraspi
{

namespace draw
{

void point(float x, float y, Color* color)
{
    // Set shader mode
    glShadeModel(GL_FLAT);

    // Draw points
    glBegin(GL_POINTS);
    glColor4f(color->rf(), color->gf(), color->bf(), color->af());
    glVertex2f(x, y);
    glEnd();
}

void line(float x1, float y1, float x2, float y2, Color* color)
{
    // Set shader point
    glShadeModel(GL_FLAT);

    // Draw line
    glBegin(GL_LINES);
    glColor4f(color->rf(), color->gf(), color->bf(), color->af());
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void gradLine(float x1, float y1, float x2, float y2, Color* color1, Color* color2)
{
    // Set shader point
    glShadeModel(GL_SMOOTH);

    // Draw line
    glBegin(GL_LINES);
    glColor4f(color1->rf(), color1->gf(), color1->bf(), color1->af());
    glVertex2f(x1, y1);
    glColor4f(color2->rf(), color2->gf(), color2->bf(), color2->af());
    glVertex2f(x2, y2);
    glEnd();
}

void triangle(DrawMode mode, float x1, float y1, float x2, float y2, float x3, float y3, Color* color)
{
    // Set shader mode
    glShadeModel(GL_FLAT);

    // Set draw mode
    if (mode == OUTLINE)
        glBegin(GL_LINE_LOOP);
    else
        glBegin(GL_TRIANGLES);

    // Draw points
    glColor4f(color->rf(), color->gf(), color->bf(), color->af());
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    
    glEnd();
}

void gradTriangle(DrawMode mode, float x1, float y1, float x2, float y2, float x3, float y3, Color* color1, Color* color2, Color* color3)
{
    // Set shader mode
    glShadeModel(GL_SMOOTH);

    // Set draw mode
    if (mode == OUTLINE)
        glBegin(GL_LINE_LOOP);
    else
        glBegin(GL_TRIANGLES);

    // Draw points
    glColor4f(color1->rf(), color1->gf(), color1->bf(), color1->af());
    glVertex2f(x1, y1);
    glColor4f(color2->rf(), color2->gf(), color2->bf(), color2->af());
    glVertex2f(x2, y2);
    glColor4f(color3->rf(), color3->gf(), color3->bf(), color3->af());
    glVertex2f(x3, y3);

    glEnd();
}

void rectangle(DrawMode mode, float x, float y, float w, float h, Color* color)
{
    // Set shader mode
    glShadeModel(GL_FLAT);

    // Set draw mode
    if (mode == OUTLINE)
        glBegin(GL_LINE_LOOP);
    else
        glBegin(GL_QUADS);

    // Draw points
    glColor4f(color->rf(), color->gf(), color->bf(), color->af());
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x, y + h);
 
    glEnd();
}

void gradRectangle(DrawMode mode, float x, float y, float w, float h, Color* color1, Color* color2, Color* color3, Color* color4)
{
    // Set shader mode
    glShadeModel(GL_SMOOTH);
 
     // Set draw mode
    if (mode == OUTLINE)
        glBegin(GL_LINE_LOOP);
    else
        glBegin(GL_QUADS);

    // Draw points
    glColor4f(color1->rf(), color1->gf(), color1->bf(), color1->af());
    glVertex2f(x, y);
    glColor4f(color2->rf(), color2->gf(), color2->bf(), color2->af());
    glVertex2f(x + w, y);
    glColor4f(color3->rf(), color3->gf(), color3->bf(), color3->af());
    glVertex2f(x + w, y + h);
    glColor4f(color4->rf(), color4->gf(), color4->bf(), color4->af());
    glVertex2f(x, y + h);

    glEnd();
}

void ellipse(DrawMode mode, float cx, float cy, double rx, double ry, Color* color, int segments)
{
    // Calculate angle
    float theta = (2.f * M_PI) / ((float) segments);

    // Set shader mode
    glShadeModel(GL_FLAT);

     // Set draw mode
    if (mode == OUTLINE)
        glBegin(GL_LINE_LOOP);
    else
        glBegin(GL_TRIANGLE_FAN);
    

    // Set ellipse color
    glColor4f(color->rf(), color->gf(), color->bf(), color->af());

    // Draws center point to draw ellipse filled
    if (mode == FILL)
    {
        glVertex2f(cx, cy);
    }

    // Draw points
    for (int i = 0; i <= segments; i++)
    {
        // Calculates point
        float xp = std::cos(theta * ((float) i)) * rx;
        float yp = std::sin(theta * ((float) i)) * ry;

        // Draw points
        glVertex2f(xp + cx, yp + cy);
    }

    glEnd();
}

void gradEllipse(DrawMode mode, float cx, float cy, double rx, double ry, Color* color1, Color* color2, int segments)
{
    // Calculate angle
    float theta = (2.f * M_PI) / ((float) segments);

    // Set shader mode
    glShadeModel(GL_SMOOTH);

     // Set draw mode
    if (mode == OUTLINE)
        glBegin(GL_LINE_LOOP);
    else
        glBegin(GL_TRIANGLE_FAN);
    

    // Set ellipse center color
    glColor4f(color1->rf(), color1->gf(), color1->bf(), color1->af());

    // Draws center point to draw ellipse filled
    if (mode == FILL)
    {
        glVertex2f(cx, cy);
    }

    // Set ellipse border color
    glColor4f(color2->rf(), color2->gf(), color2->bf(), color2->af());
    
    // Draw points
    for (int i = 0; i <= segments; i++)
    {
        // Calculates point
        float xp = std::cos(theta * ((float) i)) * rx;
        float yp = std::sin(theta * ((float) i)) * ry;

        // Draw points
        glVertex2f(xp + cx, yp + cy);
    }

    glEnd();
}

void arc(DrawMode mode, ArcType type, float cx, float cy, double rx, double ry, double angle1, double angle2, Color* color, int segments)
{
    // Calculate angle
    float theta = (angle2 - angle1) / ((float) segments);

    // Set shader mode
    glShadeModel(GL_SMOOTH);

     // Set draw mode
    if (mode == OUTLINE)
        if (type == OPEN)
            glBegin(GL_LINE_STRIP);
        else
            glBegin(GL_LINE_LOOP);
    else
        glBegin(GL_TRIANGLE_FAN);
    

    // Set arc color
    glColor4f(color->rf(), color->gf(), color->bf(), color->af());

    // Draws center point of arc if is type pie
    if (type == PIE)
        glVertex2f(cx, cy);

    // Draw points
    for (int i = 0; i <= segments; i++)
    {
        // Calculates point
        float xp = std::cos(theta * ((float) i) + angle1) * rx;
        float yp = std::sin(theta * ((float) i) + angle1) * ry;

        // Draw points
        glVertex2f(xp + cx, yp + cy);
    }

    glEnd();
}

void gradArc(DrawMode mode, ArcType type, float cx, float cy, double rx, double ry, double angle1, double angle2, Color* color1, Color* color2, int segments)
{
    // Calculate angle
    float theta = (angle2 - angle1) / ((float) segments);

    // Set shader mode
    glShadeModel(GL_SMOOTH);

     // Set draw mode
    if (mode == OUTLINE)
        if (type == OPEN)
            glBegin(GL_LINE_STRIP);
        else
            glBegin(GL_LINE_LOOP);
    else
        glBegin(GL_TRIANGLE_FAN);
    

    // Set arc color
    glColor4f(color1->rf(), color1->gf(), color1->bf(), color1->af());

    // Draws center point of arc if is type pie
    if (type == PIE)
        glVertex2f(cx, cy);

    // Draw points
    for (int i = 0; i <= segments; i++)
    {
        // Set color of the vertex
        if (((type == PIE) && (i == 0)) || ((type != PIE) && (mode == FILL) && (i == 1)))
        {
            glColor4f(color2->rf(), color2->gf(), color2->bf(), color2->af());
        }
        else if ((type != PIE) && (mode != FILL))
        {
            float p = ((float) i) / ((float) segments);
            float r = (color1->rf() * (1.f - p)) + (color2->rf() * p);
            float g = (color1->gf() * (1.f - p)) + (color2->gf() * p);
            float b = (color1->bf() * (1.f - p)) + (color2->bf() * p);
            float a = (color1->af() * (1.f - p)) + (color2->af() * p);
            glColor4f(r, g, b, a);
        }

        // Calculates point
        float xp = std::cos(theta * ((float) i) + angle1) * rx;
        float yp = std::sin(theta * ((float) i) + angle1) * ry;

        // Draw points
        glVertex2f(xp + cx, yp + cy);
    }

    glEnd();  
}

} // namespace draw

} // namespace lraspi
