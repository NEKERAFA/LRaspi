/*
    include/modules/image/module.h - NEKERAFA - 8th aug 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_MODULE_IMAGE_H
#define LRASPI_MODULE_IMAGE_H

#include "modules/image/image.h"

namespace lraspi
{

namespace image
{

/**
 * @brief Start the image module subsystem
 */
void init();

/**
 * @brief Load an image file
 * 
 * @param path The path to the image file
 * @return An lraspi::Image object
 */
Image* newImage(const char* path);

/**
 * @brief Close the image module subsystem
 */
void close();

} // namespace image

} // namespace lraspi

#endif // LRASPI_MODULE_IMAGE_H