/*
    include/modules/image/image.h - NEKERAFA - 29th july 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_OBJECT_IMAGE_H
#define LRASPI_OBJECT_IMAGE_H

#include <SDL2/SDL.h>

#include "modules/image/texture.h"

#define LRASPI_IMAGE_NAME "image"

namespace lraspi
{

/**
 * @brief Represents a wrapper between SDL Image library.
 * 
 */
class Image : public Texture
{
private:
    const char* _path;

public:
    static Type type;

    /**
     * @brief Construct a new image object
     */
    Image();

    /**
     * @brief Destroy the image object
     */
    ~Image();

    /**
     * @brief Load a image file from disk
     * 
     * @param path to the image
     * 
     * @return true if the image was loaded.
     */
    bool load(const char* path);

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

#endif // LRASPI_OBJECT_IMAGE_H