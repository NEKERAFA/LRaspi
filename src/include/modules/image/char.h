/*
    include/modules/image/char.h - NEKERAFA - 24th sep 2019

    See Copyright Notice in lraspi.h
 */

#ifndef LRASPI_OBJECT_CHAR_H
#define LRASPI_OBJECT_CHAR_H

#include "modules/common/type.h"
#include "modules/font/font.h"
#include "modules/image/texture.h"

#define LRASPI_CHAR_NAME "char"

namespace lraspi
{

/**
 * @brief Represents a rendered char to draw on screen
 * 
 */
class Char : public Texture
{
public:
    static Type type;

    /**
     * @brief Construct a new char object
     */
    Char(Font* font, char16_t glyph);

    /**
     * @brief Destroy the char object
     */
    ~Char();

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

#endif // LRASPI_OBJECT_TEXT_H