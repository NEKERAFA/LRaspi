/**
 * lcore.c - NEKERAFA - 10th novembre 2021
 * Implements core module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include "lua.h"
#include "lauxlib.h"
#include "lraspi.h"
#include "lcore.h"

/****************************
  * Wrappers
****************************/

static int lua_isclosing(lua_State* L) {
    int is_closing = lraspi_isclosing();
    lua_pushboolean(L, is_closing);
    return 1;
}

/****************************
  * Lua registry
  ****************************/

const struct luaL_Reg lua_core[] = {
    {"isclosing", lua_isclosing},
    {NULL, NULL}
};

