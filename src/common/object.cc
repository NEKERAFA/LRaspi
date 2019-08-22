/*
    common/type.cc - NEKERAFA - 1st aug 2019

    See Copyright Notice in lraspi.h
 */

#include "common/object.h"

namespace lraspi
{

Type Object::type(LRASPI_OBJECT_NAME);

Object::Object() {}

Object::~Object() {}

bool Object::isInstanceOf(Type& other)
{
    return type.isInstanceOf(other);
}

const char* Object::name()
{
    return type.name();
}

} // namespace lraspi