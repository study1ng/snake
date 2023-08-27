#ifndef CONSOLE_SCREEN_HPP
#define CONSOLE_SCREEN_HPP
#include "Screen.hpp"
namespace snake
{
    class ConsoleScreen : public Screen
    {
    public:
        void init() override;
        void end() override;
        void draw(SnakeMap map) override;
        int getMapWidth() override;
        int getMapHeight() override;
    };
} // namespace snake
#endif // CONSOLE_SCREEN_HPP