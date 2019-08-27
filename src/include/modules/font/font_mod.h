/*
    include/modules/font/font_mod.h - NEKERAFA - 23th aug 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_MODULE_FONT_H
#define LRASPI_MODULE_FONT_H

#include "modules/font/font.h"

namespace lraspi
{

namespace font
{

/**
 * @brief Start the font module subsystem
 */
void init();

/**
 * @brief Load an font file
 * 
 * @param path The path to the font file
 * @param size The size of the font in pixels
 * @return An lraspi::Font object
 */
Font* loadFont(const char* path, int size);

/**
 * @brief Creates a font using the default font (DejaVu) with a custon size
 * 
 * @param size The size of the font in pixels
 * @return An lraspi::Font object
 */
Font* createDefault(int size);

/**
 * @brief Close the font module subsystem
 */
void close();

} // namespace font

} // namespace lraspi

#endif // LRASPI_MODULE_FONT_H