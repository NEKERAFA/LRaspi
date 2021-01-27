#include "external/lua54/src/lua.hpp"

int main(int argc, char** argv) {  
	lua_State *L = luaL_newstate();
	
	luaL_openlibs(L);

	luaL_dofile(L, "main.lua");

	return 0;
}
