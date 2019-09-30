/*
    include/modules/color/color.h - NEKERAFA - 7th aug 2019

    See Copyright Notice in lraspi.h 
 */

#include <cstdint>

#include <SDL2/SDL_pixels.h>

#include "modules/common/type.h"
#include "modules/common/object.h"

#ifndef LRASPI_OBJECT_COLOR_H
#define LRASPI_OBJECT_COLOR_H

#define LRASPI_COLOR_NAME "color"

namespace lraspi
{

class Color : public Object
{
private:
    uint8_t _red;
    uint8_t _green;
    uint8_t _blue;
    uint8_t _alpha;

public:
    static Type type;

    /**
     * @brief Construct a new color object
     * 
     * @param red The red value
     * @param green The green value
     * @param blue The blue value
     */
    Color(uint8_t red, uint8_t green, uint8_t blue);

    /**
     * @brief Construct a new color object
     * 
     * @param red The red value
     * @param green The green value
     * @param blue The blue value
     * @param alpha The alpha value
     */
    Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

    /**
     * @brief Destroy a color object
     * 
     */
    ~Color();

    /**
     * @brief Gets the red color
     * 
     * @return Red color as unsigned 8 bits interger
     */
    uint8_t red();

    /**
     * @brief Sets the red color
     * 
     * @param red Red color as unsigned 8 bits interger
     */
    void red(uint8_t red);

    /**
     * @brief Gets the red color as float color
     * 
     * @return Red color as float value between 0 and 1 
     */
    float rf();

    /**
     * @brief Gets the green color
     * 
     * @return Green color as unsigned 8 bits interger
     */
    uint8_t green();

    /**
     * @brief Sets the green color
     * 
     * @param green Green color as unsigned 8 bits interger
     */
    void green(uint8_t green);

    /**
     * @brief Gets the green color as float color
     * 
     * @return Green color as float value between 0 and 1 
     */
    float gf();

    /**
     * @brief Gets the blue color
     * 
     * @return Blue color as unsigned 8 bits interger
     */
    uint8_t blue();

    /**
     * @brief Sets the blue color
     * 
     * @param blue Blue color as unsigned 8 bits interger
     */
    void blue(uint8_t blue);

    /**
     * @brief Gets the blue color as float color
     * 
     * @return Blue color as float value between 0 and 1 
     */
    float bf();

    /**
     * @brief Gets the alpha color
     * 
     * @return Alpha color as unsigned 8 bits interger
     */
    uint8_t alpha();

    /**
     * @brief Sets the alpha color
     * 
     * @param alpha Alpha color as unsigned 8 bits interger
     */
    void alpha(uint8_t alpha);

    /**
     * @brief Gets the alpha color as float color
     * 
     * @return Alpha color as float value between 0 and 1 
     */
    float af();

    /**
     * @brief Get the color
     * 
     * @return A SDL_Color struct
     */
    SDL_Color getSdlColor();

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

#endif // LRASPI_OBJECT_COLOR_H