/*
    lraspi/limage.cc - NEKERAFA - 26th july 2019

    See Copyright Notice in lraspi.h 
 */

#include <exception>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "lraspi/lscreen.h"
#include "lraspi/limage.h"
#include "modules/image/image.h"

#define LRASPI_META_IMAGE "tex_meta"

extern "C" {

    static int lraspi_push_image_metatable(lua_State* L);

    static int lraspi_image_init(lua_State* L)
    {
        int imgFlags = IMG_INIT_PNG;
        if(!(IMG_Init(imgFlags) & imgFlags))
        {
            luaL_error(L, "Could not initialize video subsytem (%s)", IMG_GetError());
        }

        return 0;
    }

    static int lraspi_image_new(lua_State* L)
    {
        const char* path = luaL_checkstring(L, 1);
        lraspi::image::image* image = *static_cast<lraspi::image::image**>(lua_newuserdata(L, sizeof(lraspi::image::image*))) = new lraspi::image::image(lraspi_screen_getContext());
        image->load(std::string(path));
        return lraspi_push_image_metatable(L);
    }

    static int lraspi_image_free(lua_State* L)
    {
        delete *static_cast<lraspi::image::image**>(luaL_checkudata(L, 1, "tex_meta"));
        return 0;
    }

    static int lraspi_push_image_metatable(lua_State* L)
    {
        if(luaL_newmetatable(L, "tex_meta")){
            static const luaL_Reg functions[] =
            {
                {"__gc", lraspi_image_free},
                {nullptr, nullptr}
            };
            luaL_setfuncs(L, functions, 0);
            lua_pushvalue(L, -1);
            lua_setfield(L, -2, "__index");
        }
        lua_setmetatable(L, -2);
        return 1;
    }

    static const luaL_Reg lraspi_image[] =
    {
        {"init",      lraspi_image_init},
        {"new",       lraspi_image_new},
        {0, 0}
    };

    int luaopen_image(lua_State* L)
    {
        luaL_newlib(L, lraspi_image);
        return 1;
    }
}