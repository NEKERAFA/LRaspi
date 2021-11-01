/*
 * laux.c - NEKERAFA - 1st november 2021
 * Axiliary functions implementation
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include "external/lua54/src/lua.h"
#include "external/lua54/src/lauxlib.h"
#include "laux.h"
#include "lscreen.h"

static const luaL_Reg lraspi_libs[] = {
    {"screen", luaopen_screen},
    {NULL, NULL}
};

/* based on luaL_openlibs code */
int lraspi_openlibs(lua_State* L) {
    const luaL_Reg *lib;
    for (lib = lraspi_libs; lib->func; lib++) {
        luaL_requiref(L, lib->name, lib->func, 1); /* loads the library using require function */
        lua_pop(L, 1);  /* remove lib */
    }
}

