#include <stdexcept>
#include <list>
#include <thread>
#include <ncurses.h>
#include "math_expansion/coordinates.hpp"
#include "math_expansion/simple_random.hpp"
#include "logger.hpp"
#include "SnakeErrors.hpp"
#include "MapElement.hpp"
#include "SnakeGame.hpp"

namespace snake
{
    using namespace math_expansion;
    SnakeGame::SnakeGame(Screen &screen, SnakeMap &map, double speed) : snake(), map(map), screen(&screen), bait(0, 0), speed(speed), sleep_time(500 / exp(0.5 * speed))
    {
        init();
    }
    void SnakeGame::init()
    {
        screen->init();
        map.init(screen->getMapHeight(), screen->getMapWidth());
        snake.init(screen->getMapHeight(), screen->getMapWidth());
        newBait();
        initscr();
        noecho();
        curs_set(0);
        keypad(stdscr, TRUE);
    }

    void SnakeGame::mainloop()
    {
        math_expansion::seed(0);
        std::thread game_thread([this]()
                                { this->gameExecution(); });
        std::thread control_thread([this]()
                                   { this->controlExecution(); });
        game_thread.join();
        control_thread.join();
        end();
    }

    void SnakeGame::end()
    {
        screen->end();
        exit(0);
    }

    void SnakeGame::gameExecution()
    {
        while (true)
        {
            if (isEatingBait())
            {
                snake.grow(direction);
                newBait();
            }
            /*
            Like below condition, snake will eat bait and then die. So we need to check if snake is dead after eating bait.
            ...ooo.
            ...@.o.
            ...^oo.
               |
               v
            ...ooo.
            ...o.o.
            ...o.o.
            */
            snake.move(direction);
            if (isDead())
            {
                end();
                exit(0);
            }
            map.update(snake, direction);
            draw();
            sleep();
        }
    }

    bool SnakeGame::isDead()
    {
        return map.isOutOfRange(snake) || map.isHitSelf(snake);
    }

    bool SnakeGame::isEatingBait()
    {
        return snake.front() == bait;
    }

    void SnakeGame::newBait()
    {
        do
        {
            bait = Coordinates<>(randRange(0, screen->getMapWidth()), randRange(0, screen->getMapHeight()));
        } while (bait.accessYX(map) != MapElement::ROAD);
        map.update(bait, MapElement::BAIT);
    }

    void SnakeGame::draw()
    {
        screen->draw(map);
        screen->show_information(*this);
    }

    void SnakeGame::sleep()
    {
        // 500 * exp(1.2 * speed)
        std::this_thread::sleep_for(std::chrono::milliseconds((int)sleep_time));
    }

    void SnakeGame::ChangeDirection(Direction direction)
    {
        if (direction != Direction::opposite((Direction)snake.front().accessYX(map)))
        {
            this->direction = direction;
        }
    }
    void SnakeGame::acceptKey()
    {
        int key;
        key = getch();
        switch (key)
        {
        case KEY_UP:
            ChangeDirection(Direction::UP);
            break;
        case KEY_DOWN:
            ChangeDirection(Direction::DOWN);
            break;
        case KEY_LEFT:
            ChangeDirection(Direction::LEFT);
            break;
        case KEY_RIGHT:
            ChangeDirection(Direction::RIGHT);
            break;
        case 'Q':
        case 'q':
            end();
            exit(0);
        default:
            break;
        }
    }

    void SnakeGame::controlExecution()
    {
        while (true)
        {
            acceptKey();
        }
    }
}