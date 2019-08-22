/*
    include/modules/screen/screen_mod.h - NEKERAFA - 26th july 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_MODULE_SCREEN_H
#define LRASPI_MODULE_SCREEN_H

#include <cstdint>

#include <SDL2/SDL.h>

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
 * @brief Get the render context object
 * 
 * @return A SDL_Renderer object
 */
SDL_Renderer* getRenderer();

/**
 * @brief Set the target render
 * 
 * @param texture the texture to set the render
 */
void setTarget(SDL_Texture* texture);

/**
 * @brief Blit a texture object in the screen
 * 
 * @param texture The texture to blit
 * @param x The x-axis position to draw the drawable
 * @param y The y-axis position to draw the drawable
 */
void blit(Texture* texture, int x, int y);

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