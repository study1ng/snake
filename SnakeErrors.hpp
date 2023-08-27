#ifndef SNAKE_ERROR_HPP
#define SNAKE_ERROR_HPP
#include <stdexcept>

namespace snake
{

    class EnumNoMatchException : public std::invalid_argument
    {
    public:
        explicit EnumNoMatchException(const std::string &message) : std::invalid_argument(message) {}
        explicit EnumNoMatchException(const char *message) : std::invalid_argument(message) {}
    };
}
#endif