/**
 * lua-raspi.cc - NEKERAFA - 25th july 2019
 * 
 * See Copyright Notice in lraspi.h 
 */

#include <iostream>

#include <lua.hpp>

#include "lraspi/lscreen.h"
#include "lraspi/limage.h"

static void print_traceback (lua_State* L) 
{
    lua_getglobal(L, "debug");
    lua_getfield(L, -1, "traceback");
    lua_remove(L, -2);
    lua_pushvalue(L, 1);
    lua_pushinteger(L, 2);
    lua_pcall(L, 2, 1, 0);

    std::cerr << lua_tostring(L, -1) << std::endl;
}

int main(int argc, char* const argv[])
{
    int state;

    // Create new virtual machine
    lua_State *L = luaL_newstate();
    // luaL_openlibs(L);
    luaL_requiref(L, "", luaopen_base, 1);
    luaL_requiref(L, "screen", luaopen_screen, 1);
    luaL_requiref(L, "image", luaopen_image, 1);

    lua_getglobal(L, "screen");
    lua_getfield(L, -1, "init");
    lua_remove(L, -2);
    lua_pushinteger(L, 600);
    lua_pushinteger(L, 200);
    if(lua_pcall(L, 2, 0, 0) != LUA_OK) {
        std::cerr << "error: [C] " << lua_tostring(L, -1) << std::endl;
        return EXIT_FAILURE;
    }

    // Open the file
    state = luaL_dofile(L, "script.lua");
    if (state) {
        std::cerr << "error: " << lua_tostring(L, -1) << std::endl;
        luaL_requiref(L, "debug", luaopen_debug, 1);
        print_traceback(L);
        return EXIT_FAILURE;
    }

    lua_getglobal(L, "screen");
    lua_getfield(L, -1, "close");
    lua_remove(L, -2);
    if(lua_pcall(L, 0, 0, 0) != LUA_OK) {
        std::cerr << "error: [C] " << lua_tostring(L, -1) << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
