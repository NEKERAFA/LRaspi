/*
    include/modules/common/type.h - NEKERAFA - 1st aug 2019

    See Copyright Notice in lraspi.h
 */

#ifndef LRASPI_COMMON_TYPE_H
#define LRASPI_COMMON_TYPE_H

namespace lraspi
{

/**
 * @brief Represent a object type
 */
class Type
{
private:
    const char* const _name;
    Type* const _parent;

public:
    /**
     * @brief Construct a new object type
     * 
     * @param name Name of the type
     */
    Type(const char* name);

    /**
     * @brief Construct a new object type
     * 
     * @param name Name of the type
     * @param parent Parent type
     */
    Type(const char* name, Type* parent);

    /**
     * @brief Destroy the object object
     */
    ~Type();

    /**
     * @brief Check if an type is an instance of this type
     * 
     * @param other The other type
     * @return true if the type is an instance of
     */
    bool isInstanceOf(Type& other);
    
    /**
     * @brief Get the name of the object type
     * 
     * @return The name of the type
     */
    const char* name();
};

} // namespace lraspi

#endif // LRASPI_COMMON_TYPE_H