/*
    include/modules/common/object.h - NEKERAFA - 1st aug 2019

    See Copyright Notice in lraspi.h
 */

#ifndef LRASPI_COMMON_OBJECT_H
#define LRASPI_COMMON_OBJECT_H

#include "modules/common/type.h"

#define LRASPI_OBJECT_NAME "object"

namespace lraspi
{

/**
 * @brief Basic object of Lua Raspi userdata
 */
class Object
{
public:
    static Type type;

    /**
     * @brief Construct a new object
     */
    Object();

    /**
     * @brief Destroy the object object
     */
    virtual ~Object() = 0;

    /**
     * @brief Check if an object is an instance of this type
     * 
     * @return true if the object is an instance of
     */
    virtual bool isInstanceOf(Type& other);
    
    /**
     * @brief Get the name of the object type
     * 
     * @return The name of the type
     */
    virtual const char* name();
};

} // namespace lraspi

#endif // LRASPI_COMMON_OBJECT_H
