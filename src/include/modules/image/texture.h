/*
    include/modules/image/texture.h - NEKERAFA - 28th july 2019

    See Copyright Notice in lraspi.h
 */

#ifndef LRASPI_OBJECT_TEXTURE_H
#define LRASPI_OBJECT_TEXTURE_H

#include <cstdint>

#include <SDL2/SDL.h>

#include "common/type.h"
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
    SDL_Texture*    _sdl_texture;
    bool            _target_access;
    int             _width, _height;
    int             _tex_width, _tex_height;
    double          _tex_angle;
    int             _tex_center_x, _tex_center_y;
    bool            _tex_flip_h, _tex_flip_v;

protected:
    /**
     * @brief Set the texture object
     * 
     * @param sdl_texture A SDL_Texture object
     */
    void setSdlTexture(SDL_Texture* sdl_texture);

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
     * @brief Get the alpha value
     * 
     * @return The alpha value 
     */
    uint8_t getAlpha();

    /**
     * @brief Get the blending mode
     * 
     * @return A SDL_BlendMode struct 
     */
    SDL_BlendMode getSdlBlendMode();

    /**
     * @brief Get the color modulation of the texture
     * 
     * @return The lraspi::Color object that represents the color modulation
     */
    Color* getTintColor();

    /**
     * @brief Set the flip of the texture
     * 
     * @param v True if the texture has vertical flip
     * @param h True if the texture has horizontal flip
     */
    void setFlip(bool v, bool h);

    /**
     * @brief Set the texture access as SDL_TEXTUREACCESS_TARGET
     */
    void setTargetAccess();

    /**
     * @brief Checks if the texture has target access
     * 
     * @return true if the texture has target access
     */
    bool isTargetAccess();

public:
    static Type type;

    /**
     * @brief Construct a new texture object
     */
    Texture();

    /**
     * @brief Destroy the texture object
     */
    ~Texture();

    /**
     * @brief Create a blank texture
     * 
     * @param width The width of the new texture
     * @param height The height of the new texture
     */
    void createBlank(int width, int height);

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
     * @brief Set the blending mode
     * 
     * @param bleding An SDL_BlendMode struct
     */
    void setSdlBlendMode(SDL_BlendMode bleding);

    /**
     * @brief Set the alpha modulation
     * 
     * @param alpha The alpha value
     */
    void setAlpha(uint8_t alpha);

    /**
     * @brief Get the texture object
     * 
     * @return A SDL_Texture object
     */
    SDL_Texture* getSdlTexture();

    /**
     * @brief Get the texture center point
     * 
     * @return A SDL_Point object
     */
    SDL_Point getSdlCenterPoint();

    /**
     * @brief Get the renderer flip
     * 
     * @return A SDL_RendererFlip object
     */
    SDL_RendererFlip getSdlFlipStatus();

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
     * @brief Set the vertical flip
     * 
     */
    void setVFlip();

    /**
     * @brief Set the horizontal flip
     * 
     */
    void setHFlip();

    /**
     * @brief Draws another texture in this texture
     * 
     * @param texture Another texture object
     * @param x the x-axis position to draw the texture
     * @param y the y-axis position to draw the texture
     */
    virtual void blit(Texture* texture, int x, int y);

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
