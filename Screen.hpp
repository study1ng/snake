#ifndef SCREEN_HPP
#define SCREEN_HPP
#include "SnakeMap.hpp"
#include "SnakeGame.hpp"

namespace snake
{
    class SnakeGame;
    class Screen
    {
    public:
        Screen(int height=-1, int width=-1) {}
        virtual void end() = 0;
        virtual void draw(SnakeMap &map) = 0;
        virtual int getMapWidth() = 0;
        virtual int getMapHeight() = 0;
        virtual void init() = 0;
        virtual void show_information(SnakeGame &game) = 0;
    }; // class Screen

} // namespace snake

#endif