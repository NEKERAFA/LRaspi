/**
 * lraspi.cpp - NEKERAFA - 28th january 2020
 * LRaspi stand-alone program
 *
 * See "lraspi.h" for license notice
 */

#include <iostream>
#include "lua.hpp"
#include "lraspi.h"
#include "laux.h"

int main(int argc, char** argv) {
	lraspi::init(); /* intializes lraspi libraries */

	lua_State* L = luaL_newstate(); /* opens new Lua state */
	luaL_openlibs(L); /* opens all lua standard libraries */
	lraspi::open_libraries(L); /* opens all lraspi standard library */

	lraspi::dofile(L, "main.lua"); /* start main script */

	lua_close(L); /* closes Lua state */

	lraspi::close(); /* closes lraspi libraries */

	return 0;
}
