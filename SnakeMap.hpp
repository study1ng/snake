#ifndef SNAKE_MAP_HPP
#define SNAKE_MAP_HPP
#include <vector>
#include "math_expansion/coordinates.hpp"
#include "Snake.hpp"
#include "MapElement.hpp"

namespace snake
{
    class SnakeMap : public std::vector<std::vector<MapElement>>
    {
        int HEIGHT;
        int WIDTH;

    public:
        void init(int HEIGHT, int WIDTH);

        void update(Coordinates<> pos, MapElement e);

        void update(Snake snake, Direction head_direction);

        bool isOutOfRange(const Snake& snake);

    public:
        bool isHitSelf(Snake snake);

        int getHeight();

        int getWidth();

    private:
        bool isOutOfRange(Coordinates<> c);
    }; // class SnakeMap
} // namespace snake
#endif // SNAKE_MAP_HPP