/*
    lraspi/lauxlib.h - NEKERAFA - 10st aug 2019

    See Copyright Notice in lraspi.h
 */

#include <iostream>

#include <lua.hpp>

#include "lraspi/lauxlib.h"

namespace lraspi
{

namespace lua
{

/**
 * @brief Internal representation of lraspi reference
 */
struct ref_Object
{
    Type* type; /**< The type of the object */
    Object* object; /**< A pointer to the object */
};

static int printtraceback(lua_State* L)
{
    const char* msg = lua_tostring(L, 1);
    luaL_traceback(L, L, msg, 0);
    std::cerr << "error: " << lua_tostring(L, -1) << std::endl;
    return EXIT_FAILURE;
}

void call(lua_State* L, int narg, int nres)
{
    int base = lua_gettop(L) - narg;
    lua_pushcfunction(L, printtraceback);
    lua_insert(L, base);
    lua_pcall(L, narg, nres, base);
}

void registerobject(lua_State* L, lraspi::Type& type, const luaL_Reg* methods)
{
    // Checks if the metatable is created
    if (luaL_newmetatable(L, type.name())) {
        // stack = {meta, meta}
        lua_pushvalue(L, -1);
        // stack = {meta = {__index = meta}}
        lua_setfield(L, -2, "__index");
        // stack = {meta = {__index = meta, methods}}
        luaL_setfuncs(L, methods, 0);
    }
}

void push(lua_State* L, lraspi::Type& type, lraspi::Object* object)
{
    // Creates a userdata with the ref_Object struct
    ref_Object* ref = (ref_Object*) lua_newuserdata(L, sizeof(ref_Object));
    // Defines the struct
    ref->type = &type;
    ref->object = object;
    // Sets the metatable of the userdata
    // stack = {userdata, meta}
    luaL_getmetatable(L, type.name());
    // stack = {userdata = {meta}}
    lua_setmetatable(L, -2);
}

bool istype(lua_State* L, lraspi::Type& type, int index)
{
    // Gets the userdata
    ref_Object* ref = (ref_Object*) lua_touserdata(L, index);
    // If the conversion could do, checks the type
    if (ref != nullptr)
        return ref->object->isInstanceOf(type);
    
    return false;
}

lraspi::Object* totype(lua_State* L, lraspi::Type& type, int index)
{
    // Gets the userdata
    ref_Object* ref = (ref_Object*) lua_touserdata(L, index);
    // Checks the conversion and the type and return the object
    if (ref != nullptr)
        if (ref->object->isInstanceOf(type))
            return ref->object;
    
    return nullptr;
}

lraspi::Object* check(lua_State* L, lraspi::Type& type, int arg)
{
    // Gets the userdata
    ref_Object* ref = (ref_Object*) lua_touserdata(L, arg);
    // Checks the conversion and the type and return the object
    if (ref != nullptr)
        if (ref->object->isInstanceOf(type))
            return ref->object;
    
    // If the object cannot convert or is not the type, raise an error
    const char* msg = lua_pushfstring(L, "expected %s, got %s", type.name(), luaL_typename(L, arg));
    luaL_argerror(L, arg, msg);
    return nullptr;
}

} // namespace lua

} // namespace lraspis