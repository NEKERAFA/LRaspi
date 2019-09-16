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
#include "modules/draw/canvas.h"

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
 * @brief Set a canvas as a target to blit
 * 
 * @param canvas A lraspi::Canvas to set the render
 */
void setCanvas(Canvas* canvas);

/**
 * @brief Get the current canvas
 * 
 * @return A lraspi::Canvas object
 */
Canvas* getCanvas();

/**
 * @brief Blit a texture object in the screen
 * 
 * @param texture The texture to blit
 * @param x The x-axis position to draw the texture
 * @param y The y-axis position to draw the texture
 */
void blit(Texture* texture, int x, int y);

/**
 * @brief Print a text in the screen
 * 
 * @param x The x-axis position to draw the text
 * @param y The y-axis position to draw the text
 * @param textstring The string to print
 * @param color A lraspi::Color object
 */
void print(int x, int y, const char* textstring, Color* color);

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