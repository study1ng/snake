#ifndef SNAKE_HPP
#define SNAKE_HPP
#include <list>
#include "math_expansion/coordinates.hpp"

namespace snake
{
    using namespace math_expansion;
    class Snake : public std::list<Coordinates<>>
    {
    public:
        void init(int HEIGHT, int WIDTH);
        void grow(Direction direction);
        void move(Direction direction);
    }; // class Snake
} // namespace snake
#endif // SNAKE_HPP