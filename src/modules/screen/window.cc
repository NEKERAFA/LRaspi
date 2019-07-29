/**
 * modules/window/window.cc - NEKERAFA - 26th july 2019
 * 
 * See Copyright Notice in lraspi.h 
 */

#include <iostream>

#include <SDL2/SDL.h>

#include "modules/screen/window.h"
#include "common/exceptionf.h"

namespace lraspi
{
namespace screen
{

window::window() : _loaded(false), _showed(false) {}

window::~window() {}

void window::init()
{
    if (_loaded)
    {
        throw common::exceptionf("window submodule already loaded");
    }

    SDL_Rect _display_bounds;

    if (SDL_Init(SDL_INIT_VIDEO))
    {
        throw common::exceptionf("Could not initialize video subsytem (%s)", SDL_GetError());
    }

    if (SDL_GetDisplayBounds(0, &_display_bounds))
    {
        std::cout << SDL_GetError();
        throw common::exceptionf("Could not get display bounds (%s)", SDL_GetError());
    }

    _width  = _display_bounds.w;
    _height = _display_bounds.h;

    if (SDL_CreateWindowAndRenderer(_width, _height, SDL_WINDOW_BORDERLESS | SDL_WINDOW_SHOWN, &_sdl_window, &_sdl_renderer))
    {
        throw common::exceptionf("Could not create window (%s)", SDL_GetError());
    }

    _showed = true;
}

void window::close()
{
    if (!_loaded)
    {
        throw common::exceptionf("window submodule not loaded");
    }

    SDL_Delay(2000);

    _loaded = false;

    SDL_DestroyRenderer(_sdl_renderer);
    SDL_DestroyWindow(_sdl_window);
    SDL_Quit();
}

void window::clear()
{
    SDL_RenderClear(_sdl_renderer);
}

void window::update()
{
    SDL_RenderPresent(_sdl_renderer);
}

SDL_Renderer* window::getContext() const
{
    return _sdl_renderer;
}

int window::getWidth() const
{
    return _width;
}

int window::getHeight() const
{
    return _height;
}

} // namespace screen
} // namespace lraspi