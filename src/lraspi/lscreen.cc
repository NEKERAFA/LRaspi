/**
 * common/lscreen.cc - NEKERAFA - 26th july 2019
 * 
 * See Copyright Notice in lraspi.h 
 */

#include <exception>

#include "lraspi/lscreen.h"
#include "modules/screen/window.h"

static lraspi::screen::window _window;

extern "C"{

    static int lraspi_screen_init(lua_State *L)
    {
        try {
            _window.init();
        }
        catch (std::exception &e)
        {
            luaL_error(L, e.what());
        }

        return 0;
    }

    static int lraspi_screen_close(lua_State *L)
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

    static int lraspi_screen_clear(lua_State *L)
    {
        _window.clear();
        return 0;
    }

    static int lraspi_screen_update(lua_State *L)
    {
        _window.update();
        return 0;
    }

    static int lraspi_screen_getWidth(lua_State *L)
    {
        lua_pushinteger(L, _window.getWidth());
        return 1;
    }

    static int lraspi_screen_getHeight(lua_State *L)
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
        {"getWidth",  lraspi_screen_getWidth},
        {"getHeight", lraspi_screen_getHeight},
        {0, 0}
    };

    int luaopen_screen(lua_State *L)
    {
        luaL_newlib(L, lraspi_screen);
        return 1;
    }

}
