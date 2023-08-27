#include "MapElement.hpp"
#include "SnakeErrors.hpp"

namespace snake
{
    MapElement::MapElement(MAP_ELEMENT element) : element(element) {}
    MapElement::operator Direction()
    {
        switch (element)
        {
        case UP_HEAD:
            return Direction::UP;
        case DOWN_HEAD:
            return Direction::DOWN;
        case LEFT_HEAD:
            return Direction::LEFT;
        case RIGHT_HEAD:
            return Direction::RIGHT;
        default:
            std::string message = "Element % not match any Direction.";
            auto replace_position = message.find("%");
            message.replace(replace_position, 1, getName());
            throw EnumNoMatchException(message);
        }
    }
    std::string MapElement::getName()
    {
        switch (element)
        {
        case ROAD:
            return "ROAD";
        case BAIT:
            return "BAIT";
        case SNAKE_BODY:
            return "SNAKE_BODY";
        case UP_HEAD:
            return "UP_HEAD";
        case DOWN_HEAD:
            return "DOWN_HEAD";
        case LEFT_HEAD:
            return "LEFT_HEAD";
        case RIGHT_HEAD:
            return "RIGHT_HEAD";
        default:
            throw EnumNoMatchException("Happened at MapElement::getName");
        }
    }
    MapElement::MapElement(Direction d)
    {
        switch ((Direction::DIRECTION)d)
        {
        case Direction::UP:
            element = UP_HEAD;
            break;
        case Direction::DOWN:
            element = DOWN_HEAD;
            break;
        case Direction::LEFT:
            element = LEFT_HEAD;
            break;
        case Direction::RIGHT:
            element = RIGHT_HEAD;
            break;
        default:
            std::string message = "Direction not match any head.";
            throw EnumNoMatchException(message);
        }
    }
    MapElement::MapElement() : element(ROAD) {}
    MapElement::operator MAP_ELEMENT()
    {
        return element;
    }
    MapElement::operator char()
    {
        return (char)element;
    }
    MapElement::operator std::string()
    {
        return std::string{(char)(*this)};
    }
}