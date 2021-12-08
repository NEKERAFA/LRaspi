/**
 * lfont.h - NEKERAFA - 6th decembre 2021
 * Defines font module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#ifndef LRASPI_FONT_MODULE_H
#define LRASPI_FONT_MODULE_H

#include "lua.h"
#include "lraspi.h"


/**
 * @brief Pushes a font object onto the stack
 * @param L A Lua state
 * @param font The font object
 */
void lraspi_pushfont(lua_State* L, lraspi_Font* font);

/**
 * @brief Checks whether the function argument narg hat a font object
 * @param L A Lua state
 * @param narg The position of the argument
 * @return The font object
 */
lraspi_Font* lraspi_checkfont(lua_State* L, int arg);

/**
 * @brief If the function argument arg is a font object, return this font. If this argument is absent or is nil, return d. Otherwise, raises an error.
 * @param L A Lua state
 * @param arg The position of the argument
 * @param d The default value if the arguments is absent or nil
 * @return The font object
 */
lraspi_Font* lraspi_optfont(lua_State* L, int arg, lraspi_Font* d);

int luaopen_font(lua_State* L);

#endif // LRASPI_FONT_MODULE_H
