/*
 * limage.h - NEKERAFA - 16th june 2022
 * Defines image module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#ifndef LRASPI_IMAGE_H
#define LRASPI_IMAGE_H

#include "lua.h"
#include "lraspi.h"

/**
 * @file limage.h
 *
 * @addtogroup lua_aux
 *
 * @{
 */

/**
 * Defines a image type
 */
typedef lraspi_Image** lua_Image;

/**
 * @brief list of filter modes
 */
extern const char* const lraspi_filtermodes[];

/**
 * @brief Pushes a image object onto the stack.
 *
 * @param L A Lua state.
 * @param image A image object.
 */
void lraspi_pushimage(lua_State* L, lraspi_Image* image);

/**
 * @brief Checks whether the function argument \p narg is a image object.
 *
 * @param L A Lua state.
 * @param narg The position of the argument.
 * @return A image object.
 */
lua_Image lraspi_checkimage(lua_State* L, int narg);

/**
 * @brief If the function argument \p arg is an image object, return this image. If the argument is absent or is nil, return \p d. Otherwise, raises an error.
 *
 * @param L A Lua state.
 * @param arg The position of the argument.
 * @param d The default value if the argument is absent or nil.
 * @return A image object.
 */
lua_Image lraspi_optimage(lua_State* L, int arg, lua_Image d);

/**
 * @}
 */

int luaopen_image(lua_State* L);

#endif // LRASPI_IMAGE_H
