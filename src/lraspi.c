#include <stdio.h>

#include "lua.h"
#include "lauxlib.h"
#include "lraspi.h"

int main(int argc, char **argv)
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    lraspi_init();

    luaL_dofile(L, "main.lua");
    lua_close(L);

    lraspi_close();

    printf("End\n");

    return 0;
}