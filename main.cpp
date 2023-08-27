#include "ConsoleScreen.hpp"
#include "SnakeGame.hpp"
int main()
{
    snake::ConsoleScreen screen;
    snake::SnakeGame game(screen);
    game.mainloop();
    return 0;
}
