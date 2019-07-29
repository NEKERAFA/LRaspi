/**
 * include/common/exception.h - NEKERAFA - 28th july 2019
 * 
 * See Copyright Notice in lraspi.h 
 */

#ifndef LRASPI_COMMON_EXCEPTION_H
#define LRASPI_COMMON_EXCEPTION_H

#include <exception>
#include <string>

namespace lraspi
{
namespace common
{

class exceptionf : public std::exception
{
private:
    std::string _message;
public:
    exceptionf(const char* fmt, ...);

    virtual const char* what() const throw()
    {
        return _message.c_str();
    }
};

} // namespace common
} // namespace lraspi

#endif // LRASPI_COMMON_EXCEPTION_H