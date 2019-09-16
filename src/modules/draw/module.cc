/*
    modules/draw/module.cc - NEKERAFA - 13th sep 2019

    See Copyright Notice in lraspi.h 
 */

#include "modules/color/color.h"
#include "modules/draw/canvas.h"
#include "modules/draw/text.h"
#include "modules/draw/module.h"

namespace lraspi
{

namespace draw
{

void point(int x, int y, Color* col)
{

}

void line(int x1, int y1, int x2, int y2, Color* col)
{

}

void gradLine(int x1, int y1, int x2, int y2, Color* col1, Color* col2)
{

}

void triangle(DrawMode mode, int x1, int y1, int x2, int y2, int x3, int y3, Color* col)
{

}

void gradTriangle(DrawMode mode, int x1, int y1, int x2, int y2, int x3, int y3, Color* col1, Color* col2, Color* col3)
{

}

void rectangle(DrawMode mode, int x, int y, int w, int h, Color* col)
{

}

void gradRectangle(DrawMode mode, int x, int y, int w, int h, Color* col1, Color* col2, Color* col3, Color* col4)
{

}

void ellipse(DrawMode mode, int x, int y, double radiusx, double radiusy, Color* col, int segments)
{

}

void gradEllipse(DrawMode mode, int x, int y, double radiusx, double radiusy, Color* col1, Color* col2, int segments)
{

}

void circle(DrawMode mode, int x, int y, double radius, Color* col, int segments)
{

}

void gradCircle(DrawMode mode, int x, int y, double radius, Color* col1, Color* col2, int segments)
{

}

void arc(DrawMode mode, ArcType type, int x, int y, double radiusx, double radiusy, double angle1, double angle2, Color* col, int segments)
{

}

void gradArc(DrawMode mode, int x, int y, double radiusx, double radiusy, double angle1, double angle2, Color* col1, Color* col2, int segments)
{
    
}

Canvas* newCanvas(int width, int height)
{
    Canvas* canvas = new Canvas();
    canvas->create(width, height);
    return canvas;
}

Text* newText(Font* font, const char* str)
{
    Text* text = new Text();
    text->render(font, str);
    return text;
}

} // namespace draw

} // namespace lraspi
