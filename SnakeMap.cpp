#include <curses.h>
#include "SnakeMap.hpp"

namespace snake
{
    void SnakeMap::init(int HEIGHT, int WIDTH)
    {
            this->HEIGHT = HEIGHT;
            this->WIDTH = WIDTH;
            this->clear();
            this->resize(HEIGHT);
            for (int i = 0; i < HEIGHT; i++)
            {
                (*this)[i].resize(WIDTH);
                for (int j = 0; j < WIDTH; j++)
                {
                    (*this)[i][j] = MapElement::ROAD;
                }
            }
    }
    void SnakeMap::update(Coordinates<> pos, MapElement e)
    {
        pos.changeYX(*this, e);
    }

    void SnakeMap::update(Snake snake, Direction head_direction)
    {
        // Clear map
        for (auto &line : *this)
        {
            for (auto &e : line)
            {
                if (e != MapElement::BAIT)
                {
                    e = MapElement::ROAD;
                }
            }
        }
        for (const auto &pos : snake)
        {
            update(pos, MapElement::SNAKE_BODY);
        }
        update(snake.front(), MapElement(head_direction));
    }

    bool SnakeMap::isOutOfRange(const Snake& snake)
    {
        return isOutOfRange(snake.front());
    }

    bool SnakeMap::isOutOfRange(Coordinates<> c)
    {
        return !(0 <= c.y && c.y < getHeight() && 0 <= c.x && c.x < getWidth());
    }

    bool SnakeMap::isHitSelf(Snake snake)
    {
        // Only check head
        return snake.front().accessYX(*this) == MapElement::SNAKE_BODY;
    }

    int SnakeMap::getHeight()
    {
        return HEIGHT;
    }
    int SnakeMap::getWidth()
    {
        return WIDTH;
    }
}