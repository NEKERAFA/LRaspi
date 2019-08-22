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

struct ref_Object
{
    Type* type;
    Object* object;
};

void registerobject(lua_State* L, lraspi::Type& type, const luaL_Reg* methods)
{
    if (luaL_newmetatable(L, type.name())) {
        lua_pushvalue(L, -1);
        lua_setfield(L, -2, "__index");
        luaL_setfuncs(L, methods, 0);
    }
}

void push(lua_State* L, lraspi::Type& type, lraspi::Object* object)
{
    ref_Object* ref = (ref_Object*) lua_newuserdata(L, sizeof(ref_Object));
    ref->type = &type;
    ref->object = object;
    luaL_getmetatable(L, type.name());
    lua_setmetatable(L, -2);
}

bool istype(lua_State* L, lraspi::Type& type, int index)
{
    ref_Object* ref = (ref_Object*) lua_touserdata(L, index);
    if (ref != nullptr)
        return ref->object->isInstanceOf(type);
    
    return false;
}

lraspi::Object* totype(lua_State* L, lraspi::Type& type, int index)
{
    ref_Object* ref = (ref_Object*) lua_touserdata(L, index);
    if (ref != nullptr)
        if (ref->object->isInstanceOf(type))
            return ref->object;
    
    return nullptr;
}

lraspi::Object* check(lua_State* L, lraspi::Type& type, int arg)
{
    ref_Object* ref = (ref_Object*) lua_touserdata(L, arg);
    if (ref != nullptr)
        if (ref->object->isInstanceOf(type))
            return ref->object;
    
    const char* msg = lua_pushfstring(L, "expected %s, got %s", type.name(), luaL_typename(L, arg));
    luaL_argerror(L, arg, msg);
    return nullptr;
}

} // namespace lua

} // namespace lraspi