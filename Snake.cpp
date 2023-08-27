#include "Snake.hpp"
#include <curses.h>
#include "logger.hpp"
namespace snake
{
    namespace 
    {
        logger::Logger log = logger::Logger();
    }

    void Snake::init(int HEIGHT, int WIDTH)
    {
        this->clear();
        this->push_front(Coordinates<>(WIDTH / 2, HEIGHT / 2));
    }
    void Snake::grow(Direction direction)
    {
        push_front(front().look(direction));
    }
    void Snake::move(Direction direction)
    {
        log << "Snake's head is at " << (std::string)front() << " and is moved for " << (std::string)direction << " finally to " << (std::string)front().look(direction) << '\n';
        push_front(front().look(direction));
        pop_back();
    }
} // namespace snake