/*
    include/modules/image/text.h - NEKERAFA - 27th aug 2019

    See Copyright Notice in lraspi.h
 */

#ifndef LRASPI_OBJECT_TEXT_H
#define LRASPI_OBJECT_TEXT_H

#include <string>

#include "common/type.h"
#include "modules/font/font.h"
#include "modules/color/color.h"
#include "modules/image/texture.h"

#define LRASPI_TEXT_NAME "name"

namespace lraspi
{

/**
 * @brief Represents a rendered text to draw on screen
 * 
 */
class Text : public Texture
{
private:
    std::string text;
    Color* color;

public:
    static Type type;

    /**
     * @brief Construct a new text object
     */
    Text();

    /**
     * @brief Destroy the text object
     */
    ~Text();

    /**
     * @brief Render a text with a font
     * 
     * @param font The font to render the text
     * @param text The text to render
     */
    void render(Font* font, const char* text);

    /**
     * @brief Set the color to draw the text
     * 
     * @param color A lraspi::Color object
     */
    void setColor(Color* color);

    /**
     * @brief Replace the content with a new value
     * 
     * @param text The new text to render
     */
    void setText(std::string text);

    /**
     * @brief Add a new text to the rendered text
     * 
     * @param text 
     */
    void addText(std::string text);

    /**
     * @brief Crear all internal text
     */
    void clear();

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