/*
    include/modules/image/graphics.h - NEKERAFA - 8th aug 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_MODULE_IMAGE_H
#define LRASPI_MODULE_IMAGE_H

#include "modules/image/texture.h"
#include "modules/image/image.h"

namespace lraspi
{

namespace image
{

/**
 * @brief Start the image module subsystem
 * 
 * @return 
 */
void init();

/**
 * @brief Load an image object
 * 
 * @param path The path to the image file
 * @return An lraspi::Image object
 */
Image* loadImage(const char* path);

/**
 * @brief Create a blank texture object
 * 
 * @param width The width of the texture
 * @param height The height of the texture
 * @return A lraspi::Texture object
 */
Texture* createBlankTexture(int width, int height);

/**
 * @brief Close the image module subsystem
 */
void close();

} // namespace image

} // namespace lraspi

#endif // LRASPI_MODULE_IMAGE_H