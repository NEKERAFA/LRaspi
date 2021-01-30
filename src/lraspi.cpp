/**
 * lraspi.cpp - NEKERAFA - 28th january 2020
 * Stand-alone program
 */

#include "external/lua54/src/lua.hpp"
#include "include/lraspi.h"

int main(int argc, char** argv) {  
    lraspi::init();
 
    lua_State *L = luaL_newstate();

    luaL_openlibs(L);

    luaL_dofile(L, "main.lua");

    lraspi::close();

    return 0;
}
