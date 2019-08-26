/*
    include/modules/font/font.h - NEKERAFA - 23th aug 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_OBJECT_FONT_H
#define LRASPI_OBJECT_FONT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "common/type.h"
#include "common/object.h"

#define LRASPI_FONT_NAME "font"
#define LRASPI_FONT_DEFAULT "dejavu.ttf"
#define LRASPI_FONT_SIZE 12

namespace lraspi
{

/**
 * @brief Represents a wrapper between SDL TTF font reader
 * 
 */
class Font : public Object
{
private:
    int         _size;
    float       _line_height;
    TTF_Font*   _font;

public:
    static Type type;

    /**
     * @brief Construct a new font object
     */
    Font();

    /**
     * @brief Destroy the font object
     */
    ~Font();

    /**
     * @brief Load the default font (DejaVu) with a custom size
     * 
     * @param size The size of the font in pixels
     * @return true if the font was loaded or false otherwise
     */
    bool create(int size);

    /**
     * @brief Load a font file from the disk
     * 
     * @param path Path to the font file
     * @param size The sie of the font in pixels
     * 
     * @return true if the font was loaded or false otherwise
     */
    bool load(const char* path, int size);

    /**
    SDL_Surface getFastSdlSurface(const char* text);

    SDL_Surface getSdlSurface(const char* text);
    **/

    /**
     * @brief Get the maximun height of the font
     * 
     * @return The height of the font in pixels
     */
    int getHeight();

    /**
     * @brief Calculates the size of the text using font
     * 
     * @param text The UTF8 null terminated string
     * @return The size in pixels of the resulting texture if the text was rendered using the font
     */
    int getWidth(const char* text);

    /**
     * @brief Format the text with a maximun text width size.
     * This functions add new lines if the text width size reachs the given wrap limit.
     * 
     * @param text The text that will be wrapped
     * @param width The maximun width in pixels of each line
     * @return The text wrapped
     */
    const char* getWrap(const char* text, int width);

    /**
     * @brief Set the rendering style of the text
     * 
     * @param style The style composed of TTF_STYLE masks
     */
    void setStyle(int style);

    /**
     * @brief Get the current rendering style of the text
     * 
     * @return int A bitmask of TTF_STYLE
     */
    int getStyle();

    /**
     * @brief Set the outline size of the font
     * 
     * @param outline The size of the outline in pixels
     */
    void setOutline(int outline);

    /**
     * @brief Get the current outline size of the font
     * 
     * @return int The current size of the outline in pixels
     */
    int getOutline();

    /**
     * @brief Set the hinting mode of the font
     * 
     * @param hinting The hiting desided value matching one of the TTF_HINTING value
     */
    void setHintingMode(int hinting);

    /**
     * @brief Get the current hinting mode
     * 
     * @return A hinting type matching one of the TTF_HINTING value
     */
    int getHintingMode();

    /**
     * @brief Get the ascent of the font.
     * This function gets the maximun ascent size of all glyphs of the font
     * 
     * @return The maximun ascent in pixels
     */
    int getAscent();

    /**
     * @brief Get the descent of the font.
     * This function gets the maximun descent size of all glyphs of the font
     * 
     * @return The maximun descent in pixels
     */
    int getDescent();

    /**
     * @brief Get the recomended height of a rendered line of text of the font.
     * This value is usually larger than the font height
     * 
     * @return The maximun height of all glyphs in the font in pixels.
     */
    int getLineSkip();

    /**
     * @brief Set the line height of the font.
     * The space between lines is determined by the line height multiplied by the height of the font.
     * 
     * @param height The space between lines when the text is rendered. The default value is 1.0
     */
    void setLineHeight(float height);

    /**
     * @brief Get the line height of the font
     * 
     * @return The space between lines when the text is rendered.
     */
    float getLineHeight();

    /**
     * @brief Get the current family name of the font
     * 
     * @return The current family name of the font or NULL if the information is not avaliable
     */
    const char* getFamilyName();

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

}

#endif // LRASPI_OBJECT_FONT_H