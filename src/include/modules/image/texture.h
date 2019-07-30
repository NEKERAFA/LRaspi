/*
    include/modules/image/texture.h - NEKERAFA - 28th july 2019

    See Copyright Notice in lraspi.h
 */

#ifndef LRASPI_WRAPPER_TEXTURE_H
#define LRASPI_WRAPPER_TEXTURE_H

#include <string>

#include <SDL2/SDL.h>

namespace lraspi
{
namespace image
{

/**
 * @brief Represents a wrapper between SDL_Texture type.
 * 
 */
class texture {
private:
    SDL_Texture* _sdl_texture;
    unsigned int _width, _height;
    unsigned int _tex_width, _tex_height;
    double _tex_angle;
    SDL_Point _tex_center;
    SDL_RendererFlip _tex_flip;

protected:
    /**
     * @brief Set the SDL_Texture object
     * 
     * @param sdl_texture 
     */
    void setSdlTexture(SDL_Texture* sdl_texture);

    /**
     * @brief Set the real width of the texture
     * 
     * @param real_width 
     */
    void setRealWidth(unsigned int real_width);

    /**
     * @brief Set the real height of the texture
     * 
     * @param real_height 
     */
    void setRealHeight(unsigned int real_height);

public:
    /**
     * @brief Construct a new texture object
     */
    texture();

    /**
     * @brief Destroy the texture object
     */
    ~texture();

    /**
     * @brief Get the SDL_Texture object
     * 
     * @return SDL_Texture* 
     */
    SDL_Texture* getSdlTexture();

    /**
     * @brief Set the width of the texture
     * 
     * @param width New width of texture 
     */
    void setWidth(unsigned int width);

    /**
     * @brief Set the height of the texture
     * 
     * @param height New height of texture
     */
    void setHeight(unsigned int height);

    /**
     * @brief Get the width of the texture
     * 
     * @return Width of texture 
     */
    unsigned int getWidth();

    /**
     * @brief Get the height of the texture
     * 
     * @return Height of texture 
     */
    unsigned int getHeight();

    /**
     * @brief Get the real width of the texture
     * 
     * @return Real width of texture 
     */
    unsigned int getRealWidth() const;

    /**
     * @brief Get the real height of the texture
     * 
     * @return Real height of texture 
     */
    unsigned int getRealHeight() const;
};

} // namespace image
} // namespace lraspi

#endif // LRASPI_WRAPPER_TEXTURE_H