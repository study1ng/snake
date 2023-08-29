#ifndef GAME_HPP
#define GAME_HPP
#include "Snake.hpp"
#include "SnakeMap.hpp"
#include "Screen.hpp"
#include <memory>
namespace snake
{
    class Screen;
    class SnakeGame
    {
    public:
        /// @brief Construct a new Snake Game object
        SnakeGame(Screen &screen, SnakeMap &map, double speed);

        void init();
        void end();

        void mainloop();
        void gameExecution();
        void controlExecution();

        bool isDead();
        bool isEatingBait();

        void newBait();
        void draw();
        void sleep();
        void acceptKey();

        void ChangeDirection(Direction direction);

    private:
        Snake snake;
        SnakeMap &map;
        std::unique_ptr<Screen> screen;
        Coordinates<> bait;
        const double speed;
        Direction direction = Direction::RIGHT;
        double sleep_time;
    };
} // namespace snake
#endif // GAME_HPP