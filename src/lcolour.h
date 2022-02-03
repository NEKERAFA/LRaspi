/*
 * lcolour.h - NEKERAFA - 7th january 2022
 * Defines colour module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#ifndef LRASPI_COLOUR_H
#define LRASPI_COLOUR_H

#include "lua.h"
#include "lraspi.h"

/**
 * @file lcolour.h
 *
 * @addtogroup lua_aux
 *
 * @{
 */

/**
 * @brief Puses a colour object onto the stack.
 *
 * @param L A Lua state.
 * @param colour A colour object.
 */
void lraspi_pushcolour(lua_State* L, lraspi_Colour* colour);

/**
 * @brief Checks whether the function argument \p narg is a colour object.
 *
 * @param L A Lua state.
 * @param narg The position of the argument.
 * @return A font object.
 */
lraspi_Colour* lraspi_checkcolour(lua_State* L, int narg);

/**
 * @brief If the function argument \p arg is a colour object, return this colour. If the argument is absent or is nil, return \p d. Otherwise, raises an error.
 *
 * @param L A Lua state.
 * @param arg The position of the argument.
 * @param d The default value if the argument is absent or nil.
 * @return A colour object.
 */
lraspi_Colour* lraspi_optcolour(lua_State* L, int arg, lraspi_Colour* d);

/**
 * @}
 */

int luaopen_colour(lua_State* L);

#endif // LRASPI_COLOUR_H

