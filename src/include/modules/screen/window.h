/**
 * include/modules/screen/window.h - NEKERAFA - 26th july 2019
 * 
 * See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_WRAPPER_WINDOW_H
#define LRASPI_WRAPPER_WINDOW_H

#include <SDL2/SDL.h>

namespace lraspi
{
namespace screen
{

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
    window();
    ~window();

    void init();
    void close();
    void clear();
    void update();
    SDL_Renderer* getContext() const;
    int getWidth() const;
    int getHeight() const;
};

} // namespace screen
} // namespace lraspi

#endif // LRASPI_WRAPPER_WINDOW_H