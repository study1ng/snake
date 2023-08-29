#ifndef SNAKE_ERROR_HPP
#define SNAKE_ERROR_HPP
#include <stdexcept>

namespace snake
{
    class SnakeError : public std::runtime_error
    {
    public:
        using std::runtime_error::runtime_error;
    };
    class EnumNoMatchException : public SnakeError
    {
    public:
        using SnakeError::SnakeError;
    };
    class InvalidEnvironmentException : public SnakeError
    {
    public:
        using SnakeError::SnakeError;
    };
}
#endif