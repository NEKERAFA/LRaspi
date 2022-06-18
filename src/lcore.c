/*
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

// Wrappers

/**
 * Core functions
 *
 * @module lraspi
 */

/**
 * Checks if the window will be closed.
 *
 * @function isclosing
 * @return true if the window will be close, otherwise false.
 */
int lua_isclosing(lua_State* L) {
    int is_closing = lraspi_isclosing();
    lua_pushboolean(L, is_closing);
    return 1;
}

