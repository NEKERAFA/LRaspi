/*
 * lfont.h - NEKERAFA - 6th decembre 2021
 * Defines font module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#ifndef LRASPI_FONT_H
#define LRASPI_FONT_H

#include "lua.h"
#include "lraspi.h"

/**
 * @file lfont.h
 *
 * @addtogroup lua_aux
 *
 * @{
 */

/**
 * Defines a font type
 */
typedef lraspi_Font** lua_Font;

/**
 * @brief Pushes a font object onto the stack.
 *
 * @param L A Lua state.
 * @param font A font object.
 */
void lraspi_pushfont(lua_State* L, lraspi_Font* font);

/**
 * @brief Checks whether the function argument \p narg is a font object.
 *
 * @param L A Lua state.
 * @param narg The position of the argument.
 * @return A font object.
 */
lua_Font lraspi_checkfont(lua_State* L, int narg);

/**
 * @brief If the function argument \p arg is a font object, return this font. If this argument is absent or is nil, return \p d. Otherwise, raises an error.
 *
 * @param L A Lua state.
 * @param arg The position of the argument.
 * @param d The default value if the argument is absent or nil.
 * @return A font object.
 */
lua_Font lraspi_optfont(lua_State* L, int arg, lua_Font d);

/**
 * @}
 */

int luaopen_font(lua_State* L);

#endif // LRASPI_FONT_H
