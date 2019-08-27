/*
    include/modules/image/text.h - NEKERAFA - 27th aug 2019

    See Copyright Notice in lraspi.h
 */

#ifndef LRASPI_OBJECT_TEXT_H
#define LRASPI_OBJECT_TEXT_H

#include <string>

#include "common/type.h"
#include "modules/font/font.h"
#include "modules/image/texture.h"

#define LRASPI_TEXT_NAME "name"

namespace lraspi
{

enum TextQuality
{
    FAST,
    NORMAL
};

/**
 * @brief Represents a rendered text to draw on screen
 * 
 */
class Text : public Texture
{
private:
    std::string _text;
    Font* _font;
    TextQuality _quality;

    /**
     * @brief Render the setted text with the setted font
     */
    void render();

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
     * @brief Set the quality to render text
     *  
     * @param quality The quality to render text
     */
    void setQuality(TextQuality quality);

    /**
     * @brief Get the quality of the render text
     * 
     * @return The quality to render text 
     */
    TextQuality getQuality();

    /**
     * @brief Replace the content with a new value
     * 
     * @param text The new text to render
     */
    void setText(const char* text);

    /**
     * @brief Add a new text to the rendered text
     * 
     * @param text The text to append
     */
    void addText(const char* text);

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