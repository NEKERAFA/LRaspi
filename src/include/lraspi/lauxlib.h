/*
    include/lraspi/lauxlib.h - NEKERAFA - 8st aug 2019

    See Copyright Notice in lraspi.h
 */

#include <lua.hpp>

#include "common/type.h"
#include "common/object.h"

namespace lraspi
{

namespace lua
{

/**
 * @brief Call and function and print the stack traceback if there are an error
 * 
 * @param L A lua_State object
 * @param narg The number of arguments
 * @param nres The number of results
 */
void call(lua_State* L, int narg, int nres);

/**
 * @brief Register a new type of object in Lua
 * 
 * @param L A lua_State object
 * @param type The type of the object to register
 * @param methods The methods to register
 */
void registerobject(lua_State* L, lraspi::Type& type, const luaL_Reg* methods);

/**
 * @brief Pushes an object in the Lua stack
 * 
 * @param L A lua_State object
 * @param T The type of the object to push
 * @param object The object to push
 */
void push(lua_State* L, lraspi::Type& type, lraspi::Object* object);

/**
 * @brief Checks if the object in the Lua stack is a type
 * 
 * @param L A lua_State object
 * @param T The type of the object to check
 * @param index The index in the stack
 * @return true If the object is the type especified, false otherwise
 */
bool istype(lua_State* L, lraspi::Type& type, int index);

/**
 * @brief Converts the Lua value at the given index to the T type
 * 
 * @param L A lua_State object 
 * @param T The type of the object to convert
 * @param index The index in the stack
 * @return If the value at the given index in the stack is a T type, return its pointer. Otherwise return nullptr
 */
lraspi::Object* totype(lua_State* L, lraspi::Type& type, int index);

/**
 * @brief Checks whether the function argument arg is a T type and returns the pointer to a T type object
 * 
 * @param L A lua_State object
 * @param T The type of the object to check
 * @param arg The function argument 
 * @return The pointer to a T type object
 */
lraspi::Object* check(lua_State* L, lraspi::Type& type, int arg);

} // namespace lua

} // namespace lraspi