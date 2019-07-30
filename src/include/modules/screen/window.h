/*
    include/modules/screen/window.h - NEKERAFA - 26th july 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_WRAPPER_WINDOW_H
#define LRASPI_WRAPPER_WINDOW_H

#include <SDL2/SDL.h>

#include "modules/image/texture.h"

namespace lraspi
{
namespace screen
{

/**
 * @brief Represents a wrapper between SDL_Window type.
 * 
 */
class window
{
private:
    int  _height;
    int  _width;
    bool _loaded;
    bool _showed;

    SDL_Window*   _sdl_window;
    SDL_Renderer* _sdl_renderer;

public:
    /**
     * @brief Construct a new window object
     */
    window();

    /**
     * @brief Destroy the window object
     */
    ~window();

    /**
     * @brief Start the window module subsystem
     */
    void init();

    /**
     * @brief Close the window module subsystem
     * 
     */
    void close();

    /**
     * @brief Clear the window
     * 
     */
    void clear();

    /**
     * @brief Update the window
     * 
     */
    void update();

    /**
     * @brief Blit a texture onto the window
     * 
     * @param texture the texture to blit
     * @param x the x-axis position to draw the texture
     * @param y the y-axis position to draw the texture
     */
    void blit(image::texture* texture, int x, int y);

    /**
     * @brief Get the Renderer object
     * 
     * @return A SDL_Renderer object
     */
    SDL_Renderer* getRenderer();

    /**
     * @brief Get the width of the screen
     * 
     * @return the width of the screen
     */
    int getWidth() const;

    /**
     * @brief Get the height of the screen
     * 
     * @return the height of the screen
     */
    int getHeight() const;
};

} // namespace screen
} // namespace lraspi

#endif // LRASPI_WRAPPER_WINDOW_H