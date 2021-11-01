/**
 * lraspi.c - NEKERAFA - 25th october 2021
 * Lua Raspi stand-alone program
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <stdio.h>

#include "lua.h"
#include "lauxlib.h"
#include "laux.h"
#include "lraspi.h"

int main(int argc, char **argv)
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    lraspi_init();
    lraspi_openlibs(L);

    luaL_dofile(L, "main.lua");
    lua_close(L);

    lraspi_close();

    printf("End\n");

    return 0;
}

