/*
    common/exception.cc - NEKERAFA - 28th july 2019

    See Copyright Notice in lraspi.h 
 */

#include <vector>
#include <cstdio>
#include <cstdarg>

#include "common/exception.h"

namespace lraspi
{

Exception::Exception(const char* fmt, ...)
{
    /*
        See https://en.cppreference.com/w/cpp/io/c/vfprintf
     */
    va_list args1;
    va_list args2;
    size_t size_buffer;
    char* buffer;

    va_start(args1, fmt);
    va_copy(args2, args1);
    size_buffer = 1 + std::vsnprintf(nullptr, 0, fmt, args1);
    va_end(args1);
    buffer = new char[size_buffer];
    vsnprintf(buffer, size_buffer, fmt, args2);
    va_end(args2);
    _message = std::string(buffer);

    delete[] buffer;
}

} // namespace lraspi
