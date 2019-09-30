/*
    include/modules/image/texture.h - NEKERAFA - 28th july 2019

    See Copyright Notice in lraspi.h
 */

#ifndef LRASPI_OBJECT_TEXTURE_H
#define LRASPI_OBJECT_TEXTURE_H

#include <atomic>
#include <cstdint>

#include <SDL2/SDL.h>
#include <GL/glu.h>

#include "modules/common/type.h"
#include "modules/color/color.h"

#define LRASPI_TEXTURE_NAME "texture"

namespace lraspi
{

/**
 * @brief Represents a wrapper between SDL_Texture type.
 * 
 */
class Texture : public Object {
private:
    GLuint _gl_id_texture;
    Color* _tint;
    int    _width;
    int    _height;
    int    _real_width;
    int    _real_height;
    double _angle;
    int    _center_x;
    int    _center_y;
    bool   _flip_h;
    bool   _flip_v;
    bool   _loaded;

protected:
    /**
     * @brief Set the surface object
     * 
     * @param sdl_surface A SDL_Surface object 
     * @param access A SDL_TextureAccess value
     */
    void setSdlSurface(SDL_Surface* sdl_surface);

    /**
     * @brief Set the real width of the texture
     * 
     * @param real_width The real width of the texture
     */
    void setRealWidth(int real_width);

    /**
     * @brief Set the real height of the texture
     * 
     * @param real_height The real height of the texture
     */
    void setRealHeight(int real_height);

    /**
     * @brief Set the flip of the texture
     * 
     * @param v True if the texture has vertical flip
     * @param h True if the texture has horizontal flip
     */
    void setFlip(bool v, bool h);

    /**
     * @brief Destroy the texture loaded
     */
    void glDestroy();

public:
    static Type type;

    /**
     * @brief Construct a new texture object
     */
    Texture();

    /**
     * @brief Destroy the texture object
     */
    virtual ~Texture() = 0;

    /**
     * @brief Get the id texture
     * 
     * @return the id texture
     */
    GLuint glIdTexture();

    /**
     * @brief Reset al values to default
     */
    void reset();

    /**
     * @brief Set the color modulation of the texture
     * 
     * @param color A lraspi::Color object to set the color modulation
     */
    void tint(Color* color);

    /**
     * @brief Get the color modulation of the texture
     * 
     * @return The lraspi::Color object that represents the color modulation
     */
    Color* getTintColor();

    /**
     * @brief Set the alpha modulation
     * 
     * @param alpha The alpha value
     */
    void setAlpha(uint8_t alpha);

    /**
     * @brief Get the alpha value
     * 
     * @return The alpha value 
     */
    uint8_t getAlpha();

    /**
     * @brief Set the width of the texture
     * 
     * @param width New width of texture 
     */
    void setWidth(int width);

    /**
     * @brief Set the height of the texture
     * 
     * @param height New height of texture
     */
    void setHeight(int height);

    /**
     * @brief Get the width of the texture
     * 
     * @return Width of texture 
     */
    int getWidth();

    /**
     * @brief Get the height of the texture
     * 
     * @return Height of texture 
     */
    int getHeight();

    /**
     * @brief Get the real width of the texture
     * 
     * @return Real width of texture 
     */
    int getRealWidth() const;

    /**
     * @brief Get the real height of the texture
     * 
     * @return Real height of texture 
     */
    int getRealHeight() const;

    /**
     * @brief Set the angle of the texture
     * 
     * @param angle An angle in degrees, rotating it in a clockwise direction
     */
    void setAngle(double angle);

    /**
     * @brief Get the angle of the texture
     * 
     * @return The angle in degress 
     */
    double getAngle();

    /**
     * @brief Set the center of the texture
     * 
     * @param x the x-axis position to set the center of the texture
     * @param y the y-axis position to set the center of the texture
     */
    void setCenter(int x, int y);

    /**
     * @brief Set the center point of the texture in the middle
     */
    void setCenter();

    /**
     * @brief Get the center of the texture
     * 
     * @param x the x-axis position to set the center of the texture
     * @param y the y-axis position to set the center of the texture
     */
    void getCenter(int* x, int* y);

    /**
     * @brief Set the vertical flip
     */
    void setVFlip();

    /**
     * @brief Set the horizontal flip
     */
    void setHFlip();

    /**
     * @brief Get the texture flip
     * 
     * @param h the horizontal flip
     * @param v the vertical flip
     */
    void getFlip(bool* h, bool* v);

    /**
     * @brief Get the color of the pixel in the texture
     * 
     * @param x The x-axis position of the pixel in the texture
     * @param y The y-axis position of the pixel in the texture
     * @return A lraspi::Color object
     */
    Color* getPixel(uint16_t x, uint16_t y);

    /**
     * @brief Set the color of the pixel in the texture
     * 
     * @param x The x-axis position of the pixel in the texture
     * @param y The y-axis position of the pixel in the texture
     * @param col A lraspi::Color object
     */
    void setPixel(uint16_t x, uint16_t y, Color* col);

    /**
     * @brief Check if an object is an instance of this type
     * 
     * @return true if the object is an instance of
     */
    virtual bool isInstanceOf(Type& other);
    
    /**
     * @brief Get the name of the object type
     * 
     * @return The name of the type
     */
    virtual const char* name();
};

} // namespace lraspi

#endif // LRASPI_OBJECT_TEXTURE_H
