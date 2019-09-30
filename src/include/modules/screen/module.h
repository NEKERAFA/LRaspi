/*
    include/modules/screen/module.h - NEKERAFA - 26th july 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_MODULE_SCREEN_H
#define LRASPI_MODULE_SCREEN_H

#include <cstdint>

#include <SDL2/SDL.h>

#include "modules/font/font.h"
#include "modules/color/color.h"
#include "modules/image/texture.h"

namespace lraspi
{

namespace screen
{

/**
 * @brief Start the window module subsystem
 * 
 * @return 
 */
void init();

/**
 * @brief Close the window module subsystem
 */
void close();

/**
 * @brief Clear the screen
 */
void clear(Color* color);

/**
 * @brief Blit a texture object in the screen
 * 
 * @param x The x-axis position to draw the texture
 * @param y The y-axis position to draw the texture
 * @param texture The texture to blit
 */
void blit(float x, float y, Texture* texture);

/**
 * @brief Print a text in the screen
 * 
 * @param x The x-axis position to draw the text
 * @param y The y-axis position to draw the text
 * @param textstring The string to print
 * @param color A lraspi::Color object
 */
void print(float x, float y, const char* textstring, Color* color);

/**
 * @brief Set the default font
 * 
 * @param font A lraspi::Font object 
 */
void setFont(Font* font);

/**
 * @brief Get the default font
 * 
 * @return A lraspi::Font object 
 */
Font* getFont();

/**
 * @brief Update the screen
 * 
 * @return true if the screen cannot be update (the window was closed or something)
 */
bool update();

/**
 * @brief Get the width of the screen
 * 
 * @return The width of the screen
 */
uint16_t getWidth();

/**
 * @brief Get the height of the screen
 * 
 * @return The height of the screen
 */
uint16_t getHeight();

} // namespace screen

} // namespace lraspi

#endif // LRASPI_MODULE_SCREEN_H