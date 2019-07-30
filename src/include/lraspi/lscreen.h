/*
    include/lraspi/lscreen.h - NEKERAFA - 27th july 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_SCREEN_LUA_H
#define LRASPI_SCREEN_LUA_H

#include <SDL2/SDL.h>

#include <lua.hpp>

/**
 * @brief Get the context of the screen to load textures
 * 
 * @return SDL_Renderer* 
 */
SDL_Renderer* lraspi_screen_getContext();

extern "C" {
    /**
     * @brief Loads the screen module
     * 
     * @param L a Lua State
     */
    int luaopen_screen(lua_State* L);
}

#endif // LRASPI_SCREEN_LUA_H