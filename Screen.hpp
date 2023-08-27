#ifndef SCREEN_HPP
#define SCREEN_HPP
#include "SnakeMap.hpp"

namespace snake
{
    class Screen
    {
    public:
        virtual void init() = 0;

        virtual void end() = 0;

        virtual void draw(SnakeMap map) = 0;

        virtual int getMapWidth() = 0;

        virtual int getMapHeight() = 0;
    }; // class Screen

} // namespace snake

#endif