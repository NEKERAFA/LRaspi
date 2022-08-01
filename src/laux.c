/*
 * laux.c - NEKERAFA - 1st november 2021
 * Axiliary functions implementation
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lua.h"
#include "lauxlib.h"
#include "laux.h"
#include "lscreen.h"
#include "lfont.h"
#include "lcolour.h"
#include "ldraw.h"
#include "limage.h"

static const luaL_Reg lraspi_libs[] = {
    {LRASPI_SCREENMODULE, luaopen_screen},
    {LRASPI_FONTMODULE, luaopen_font},
    {LRASPI_COLOURMODULE, luaopen_colour},
    {LRASPI_DRAWMODULE, luaopen_draw},
    {LRASPI_IMAGEMODULE, luaopen_image},
    {NULL, NULL}
};

const char* strtoupper(const char* str) {
    size_t str_len = strlen(str);
    char* buff = malloc(sizeof(char) * str_len);
    
    int pos;
    for (pos = 0; str[pos]; pos++) {
        buff[pos] = (char)toupper((unsigned char) str[pos]);
    }

    return buff;
}

/* based on luaL_openlibs code */
void lraspi_openlibs(lua_State* L) {
    // Add LRASPI_LIB_VERSION
    lua_pushfstring(L, "lraspi %s", LRASPI_LIB_VERSION);
    lua_setglobal(L, "_LRASPI_LIB_VERSION");
    
    // Add LRASPI_VERSION
    lua_pushfstring(L, "Lua Raspi %s",  LRASPI_VERSION);
    lua_setglobal(L, "_LRASPI_VERSION");

    // Add filtermode types
    lua_newtable(L);
    int pos;
    for (pos = 0; lraspi_filtermodes[pos]; pos++) {
        lua_pushstring(L, lraspi_filtermodes[pos]);
        const char* buff = strtoupper(lraspi_filtermodes[pos]);
        lua_setfield(L, -2, buff);
    }
    lua_setglobal(L, "filtermodes");

    // Add libraries
    const luaL_Reg *lib;
    for (lib = lraspi_libs; lib->func; lib++) {
        luaL_requiref(L, lib->name, lib->func, 1); /* loads the library using require function */
        lua_pop(L, 1);  /* remove lib */
    }
}

static int printtraceback(lua_State* L) {
    const char* msg = lua_tostring(L, 1);
    luaL_traceback(L, L, msg, 0);
    fprintf(stderr, "error: %s\n", lua_tostring(L, -1));
    exit(EXIT_FAILURE);
    return 0;
}

void call(lua_State* L, int narg, int nres) {
    int base = lua_gettop(L) - narg;
    lua_pushcfunction(L, printtraceback);
    lua_insert(L, base);
    lua_pcall(L, narg, nres, base);
}

void lraspi_dofile(lua_State* L, const char* path) {
    if (luaL_loadfile(L, path) == LUA_OK) {
        call(L, 0, LUA_MULTRET);
    } else {
        fprintf(stderr, "error: %s\n", lua_tostring(L, -1));
        exit(EXIT_FAILURE);
    }
}

void lraspi_newobject(lua_State* L, const char* objname, const luaL_Reg methods[]) {
    if (luaL_newmetatable(L, objname)) { // stack = { mtbl, args... }
        lua_pushvalue(L, -1); // stack = { mtbl, mtbl, args... }
        lua_setfield(L, -2, "__index"); // stack = { mtbl = {__index = mtbl}, args... }
        luaL_setfuncs(L, methods, 0); // stack = { mtbl = {__index = mtbl, methods...}, args...}
    }
}

