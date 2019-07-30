/*
    include/common/exception.h - NEKERAFA - 28th july 2019

    See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_COMMON_EXCEPTION_H
#define LRASPI_COMMON_EXCEPTION_H

#include <exception>
#include <string>

namespace lraspi
{
namespace common
{

/**
 * @brief Represents a exception with a printf format error
 * 
 */
class exceptionf : public std::exception
{
private:
    std::string _message;
public:
    /**
     * @brief Construct a new exceptionf object.
     * 
     * See: http://www.cplusplus.com/reference/clibrary/cstdio/printf/
     * 
     * @param fmt The format string (see printf).
     */
    exceptionf(const char* fmt, ...);

    /**
     * @brief Returns a string containing reason for the exception.
     * 
     * @return The description of the exception
     */
    virtual const char* what() const throw()
    {
        return _message.c_str();
    }
};

} // namespace common
} // namespace lraspi

#endif // LRASPI_COMMON_EXCEPTION_H