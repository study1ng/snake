#ifndef CONSOLE_SCREEN_HPP
#define CONSOLE_SCREEN_HPP
#include "Screen.hpp"
namespace snake
{
    class ConsoleScreen : public Screen
    {
    private:
        int width;
        int height;

    public:
        ConsoleScreen(int width, int height);
        void init() override;
        void end() override;
        void draw(SnakeMap &map) override;
        int getMapWidth() override;
        int getMapHeight() override;
        void show_information(SnakeGame &game) override;
    };
} // namespace snake
#endif // CONSOLE_SCREEN_HPP