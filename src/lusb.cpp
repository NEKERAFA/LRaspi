/**
 * lusb.cpp - NEKERAFA - 10th April 2021
 * Implements usb module
 *
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#include <iostream>
#include "lua.hpp"
#include "lraspi.h"
#include "laux.h"
#include "lusb.h"

static int usb_list(lua_State* L) {
	auto devices = lraspi::usb::list();
	lua_newtable(L);

	for (int i = 1; i <= devices.size(); i++) {
		lua_pushstring(L, devices[i - 1].c_str());
		lua_rawseti(L, -2, i);
	}

	return 1;
}

static const luaL_Reg usb[] = {
	{"list", usb_list},
	{NULL, NULL}
};

int luaopen_usb(lua_State* L) {
	luaL_newlib(L, usb);
	return 1;
}
