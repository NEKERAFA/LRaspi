/*
    include/modules/draw/canvas.h - NEKERAFA - 12th sep 2019

    See Copyright Notice in lraspi.h
 */

#ifndef LRASPI_OBJECT_CANVAS_H
#define LRASPI_OBJECT_CANVAS_H

#include "common/type.h"
#include "modules/draw/texture.h"

#define LRASPI_CANVAS_NAME "canvas"

namespace lraspi
{

class Canvas : public Texture
{
public:
    static Type type;

    Canvas();

    ~Canvas();

    /**
     * @brief Create a new canvas
     * 
     * @param w Width of canvas
     * @param h Height of canvas
     */
    void create(int w, int h);

    /**
     * @brief Check if an object is an instance of this type
     * 
     * @return true if the object is an instance of
     */
    bool isInstanceOf(Type& other);
    
    /**
     * @brief Get the name of the object type
     * 
     * @return The name of the type
     */
    const char* name();
};

} // namespace lraspi

#endif // LRASPI_OBJECT_CANVAS_H