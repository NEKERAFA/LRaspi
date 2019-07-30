/*
    include/modules/image/image.h - NEKERAFA - 29th july 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_WRAPPER_IMAGE_H
#define LRASPI_WRAPPER_IMAGE_H

#include <string>

#include <SDL2/SDL.h>

#include "modules/image/texture.h"

namespace lraspi
{
namespace image
{

/**
 * @brief Represents a wrapper between SDL Image library.
 * 
 */
class image : public texture
{
private:
    std::string   _path;
    SDL_Renderer* _sdl_renderer;

public:
    /**
     * @brief Construct a new image object
     * 
     * @param path to the image
     */
    image(SDL_Renderer* sdl_renderer);

    /**
     * @brief Destroy the image object
     */
    ~image();

    /**
     * @brief Load a image file from disk
     * 
     * @param path to the image
     * 
     * @return true if the image was loaded.
     */
    bool load(std::string path);

    /**
     * @brief Get the path of the image
     * 
     * @return the path of the image 
     */
    std::string getPath();
};

} // namespace image
} // namespace lraspi

#endif // LRASPI_WRAPPER_IMAGE_H