/**
 * laux.h - NEKERAFA - 28th february 2021
 * Defines auxiliary lua functions
 * 
 * Under MIT License
 * Copyright (c) 2019 - Rafael Alcalde Azpiazu (NEKERAFA)
 */

#ifndef LRASPI_AUXILIARY_H
#define LRASPI_AUXILIARY_H

#include <string>
#include <cstdint>
#include "lua.hpp"
#include "lraspi.h"

#define LRASPI_COLORLIBNAME "color"
#define LRASPI_FILESLIBNAME "files"
#define LRASPI_FONTLIBNAME "font"
#define LRASPI_SCREENLIBNAME "screen"
#define LRASPI_USBLIBNAME "usb"

namespace lraspi {
	/**
	 * @brief Open all lua libraries
	 *
	 * @param L A Lua state
	 */
	void open_libraries(lua_State* L);

	/**
	 * @brief Loads the file and runs
	 *
	 * @param L A lua_State object
	 * @param path The path of the file
 	*/
	void dofile(lua_State* L, const char* path);

	/**
	 * @brief Defines a new object as a userdata and save into the stack
	 *
	 * @param L A Lua state
	 * @param type The name type of the object
	 * @param methods A Lua registy with the methods of the object
	 */
	void new_object(lua_State* L, std::string type, const luaL_Reg methods[]);

	/**
	 * @brief Checks if the index value in the stack is a defined userdata
	 *
	 * @param L A Lua state
	 * @param index The position in the stack
	 */
	template <class T>
	bool is_object(lua_State* L, int index) {
		void* ud = luaL_testudata(L, index, T::type().c_str());
		return ud != NULL;
	}

	/**
	 * @brief Pushes a object into the stack
	 *
	 * @param L A Lua state
	 * @param obj The object to push
	 */
	template <class T>
	void push_object(lua_State* L, T* obj) {
		lua_pushlightuserdata(L, obj);
		luaL_getmetatable(L, T::type().c_str());
		lua_setmetatable(L, -2);
	}

	/**
	 * @brief Gets the object into the stack and return it cast to T object
	 *
	 * @param L A Lua state
	 * @param index The position in the stack
	 * @param type The name type of the object
	 */
	template <class T>
	T* to_object(lua_State* L, int index) {
		T* ud = (T*)luaL_testudata(L, index, T::type().c_str());
		return ud;
	}

	/**
	 * @brief Checks whether the function argument narg is an object and return this, cast to a T object
	 *
	 * @param L A Lua state
	 * @param narg The function argument
	 */
	template <class T>
	T* check_object(lua_State* L, int narg) {
		T* ud = (T*)luaL_checkudata(L, narg, T::type().c_str());
		return ud;
	}

	/**
	 * @brief If the function argument narg is an object, return this. If this argument is absent or is nil, return opt. Otherwise, raises an error.
	 *
	 * @param L A Lua state
	 * @param narg The function argument
	 * @param opt The default value
	 */
	template <class T>
	T* opt_object(lua_State* L, int index, T* opt) {
		T* ud = (T*)luaL_testudata(L, index, T::type().c_str());
		return ud != NULL ? ud : opt;
	}
}

#endif // LRASPI_AUX_LIBRARY_H
