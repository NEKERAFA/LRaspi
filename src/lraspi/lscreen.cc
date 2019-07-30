/*
    lraspi/lscreen.cc - NEKERAFA - 26th july 2019

    See Copyright Notice in lraspi.h 
 */

#include <exception>

#include <SDL2/SDL.h>

#include "lraspi/lscreen.h"
#include "modules/screen/window.h"
#include "modules/image/texture.h"

static lraspi::screen::window _window;

SDL_Renderer* lraspi_screen_getContext() {
    return _window.getRenderer();
}

extern "C" {

    static int lraspi_screen_init(lua_State* L)
    {
        try {
            _window.init();
        }
        catch (std::exception& e)
        {
            luaL_error(L, e.what());
        }

        return 0;
    }

    static int lraspi_screen_close(lua_State* L)
    {
        try {
            _window.close();
        }
        catch (std::exception &e)
        {
            luaL_error(L, e.what());
        }

        return 0;
    }

    static int lraspi_screen_clear(lua_State* L)
    {
        _window.clear();
        return 0;
    }

    static int lraspi_screen_update(lua_State* L)
    {
        _window.update();
        return 0;
    }

    static int lraspi_screen_blit(lua_State* L)
    {
        lraspi::image::texture* texture = *static_cast<lraspi::image::texture**>(luaL_checkudata(L, 1, "tex_meta"));
        int x = luaL_checknumber(L, 2);
        int y = luaL_checknumber(L, 3);

        _window.blit(texture, x, y);
    }

    static int lraspi_screen_getWidth(lua_State* L)
    {
        lua_pushinteger(L, _window.getWidth());
        return 1;
    }

    static int lraspi_screen_getHeight(lua_State* L)
    {
        lua_pushinteger(L, _window.getHeight());
        return 1;
    }

    static const luaL_Reg lraspi_screen[] =
    {
        {"init",      lraspi_screen_init},
        {"close",     lraspi_screen_close},
        {"clear",     lraspi_screen_clear},
        {"update",    lraspi_screen_update},
        {"blit",      lraspi_screen_blit},
        {"getWidth",  lraspi_screen_getWidth},
        {"getHeight", lraspi_screen_getHeight},
        {0, 0}
    };

    int luaopen_screen(lua_State* L)
    {
        luaL_newlib(L, lraspi_screen);
        return 1;
    }

}
