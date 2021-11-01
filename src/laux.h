/**
 * laux.h - NEKERAFA - 1st november 2021
 * Auxiliary functions
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#ifndef LRASPI_AUX_H
#define LRASPI_AUX_H

#include "external/lua54/src/lua.h"

#define LRASPI_SCREENMODULE "module"

/**
 * @brief Opens default libraries
 */
int lraspi_openlibs(lua_State* L);

#endif // LRASPI_AUX_H

