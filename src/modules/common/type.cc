/*
    common/type.cc - NEKERAFA - 1st aug 2019

    See Copyright Notice in lraspi.h
 */

#include <cstring>
#include <typeinfo>

#include "modules/common/type.h"

namespace lraspi
{

Type::Type(const char* name) : _name(name), _parent(nullptr)
{}

Type::Type(const char* name, Type* parent) : _name(name), _parent(parent)
{}

Type::~Type() {}

bool Type::isInstanceOf(Type& other)
{
    if (!strcmp(_name, other._name))
    {
        return true;
    }
    else if (_parent != nullptr)
    {
        return _parent->isInstanceOf(other);
    }

    return false;
}

const char* Type::name()
{
    return _name;
}

} // namespace lraspi