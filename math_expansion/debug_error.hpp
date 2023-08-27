#pragma once


#ifndef MATH_EXPANSION_DEBUG_ERROR_HPP
#define MATH_EXPANSION_DEBUG_ERROR_HPP 1
#include <exception>

namespace math_expansion
{
    class SameElementError : public std::exception
    {
    public:
        SameElementError() {}
        const char *what() const throw()
        {
            return "The element is already in the vector";
        }

    };
}

#endif