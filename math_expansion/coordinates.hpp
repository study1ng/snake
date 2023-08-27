#pragma once

#ifndef MATH_EXPANSION_COORDINATES_HPP
#define MATH_EXPANSION_COORDINATES_HPP 1

#include <vector>
#include <climits>
#include <cmath>
#include <sstream>
#include "debug_error.hpp"

namespace math_expansion
{
    class Direction
    {
    public:
        enum DIRECTION
        {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };
        Direction(DIRECTION direction) : direction(direction) {}
        static constexpr DIRECTION opposite(DIRECTION direction)
        {
            switch (direction)
            {
            case UP:
                return DOWN;
            case DOWN:
                return UP;
            case LEFT:
                return RIGHT;
            case RIGHT:
                return LEFT;
            default:
                return UP;
            }
        }
        inline operator DIRECTION() const
        {
            return direction;
        }
        inline operator int() const
        {
            return (int)direction;
        }
        inline operator std::string() const
        {
            switch (direction)
            {
            case UP:
                return "UP";
            case DOWN:
                return "DOWN";
            case LEFT:
                return "LEFT";
            case RIGHT:
                return "RIGHT";
            default:
                return "UNKNOWN";
            }
        }

    private:
        DIRECTION direction;
    };

    template <typename T = int>
    struct Coordinates
    {
    public:
        T x;
        T y;
        Coordinates(T x, T y) : x(x), y(y) {}
        bool inRange(T x_min, T x_max, T y_min, T y_max) const
        {
            return x_min <= x && x <= x_max && y_min <= y && y <= y_max;
        }
        bool inRange(T x_range, T y_range) const
        {
            return inRange(min(0, x_range), max(0, x_range), min(0, x_range), max(0, x_range));
        }
        Coordinates<T> operator=(const Coordinates<T> &other)
        {
            x = other.x;
            y = other.y;
            return *this;
        }
        bool operator==(const Coordinates<T> &other) const
        {
            return x == other.x && y == other.y;
        }
        bool operator!=(const Coordinates<T> &other) const
        {
            return !(*this == other);
        }
        Coordinates<T> operator+(const Coordinates<T> &other) const
        {
            return Coordinates<T>(x + other.x, y + other.y);
        }
        Coordinates<T> operator-(const Coordinates<T> &other) const
        {
            return Coordinates<T>(x - other.x, y - other.y);
        }
        Coordinates<T> operator*(const Coordinates<T> &other) const
        {
            return Coordinates<T>(x * other.x, y * other.y);
        }
        Coordinates<T> operator/(const Coordinates<T> &other) const
        {
            return Coordinates<T>(x / other.x, y / other.y);
        }
        Coordinates<T> operator%(const Coordinates<T> &other) const
        {
            return Coordinates<T>(x % other.x, y % other.y);
        }
        Coordinates<T> operator+=(const Coordinates<T> &other)
        {
            *this = *this + other;
            return *this;
        }
        Coordinates<T> operator-=(const Coordinates<T> &other)
        {
            *this = *this - other;
            return *this;
        }
        Coordinates<T> operator*=(const Coordinates<T> &other)
        {
            *this = *this * other;
            return *this;
        }
        Coordinates<T> operator/=(const Coordinates<T> &other)
        {
            *this = *this / other;
            return *this;
        }
        Coordinates<T> operator%=(const Coordinates<T> &other)
        {
            *this = *this % other;
            return *this;
        }
        Coordinates<T> look(Direction direction) const
        {
            Coordinates<T> result = *this;
            switch ((Direction::DIRECTION)direction)
            {
            case Direction::UP:
                result.y -= 1;
                break;
            case Direction::DOWN:
                result.y += 1;
                break;
            case Direction::LEFT:
                result.x -= 1;
                break;
            case Direction::RIGHT:
                result.x += 1;
                break;
            default:
                break;
            }
            return result;
        }

        /// @brief will return the reference of map[y][x]
        /// @tparam E map element type
        /// @param map the map to be accessed
        /// @return the reference of map[y][x]
        template <typename E>
        E &accessYX(std::vector<std::vector<E>> &map) const
        {
            return map.at(y).at(x);
        }
        template <typename E>
        void changeYX(std::vector<std::vector<E>> &map, E element) const
        {
#ifdef MATH_EXPANSION_DEBUG
            if (map[x][y] == element)
            {
                throw SameElementError();
            }
#endif
            accessYX(map) = element;
        }

        static Coordinates<T> getNULL()
        {
            Coordinates<T> ret = Coordinates<T>(INT_MIN, INT_MIN);
            ret.null = true;
            return ret;
        }
        bool isNULL() const
        {
            return this->null;
        }
        Direction getDirection(const Coordinates<T> &other) const
        {
            Coordinates<T> t = other - *this;
            double angle = t.getAngle();
            if (angle < M_PI / 4)
            {
                return Direction::RIGHT;
            }
            else if (angle < M_PI / 4 * 3)
            {
                if (t.y > 0)
                {
                    return Direction::DOWN;
                }
                else
                {
                    return Direction::UP;
                }
            }
            else
            {
                return Direction::LEFT;
            }
        }

        double getAngle() const
        {
            return std::acos(x * x + y * y);
        }
        T distance(const Coordinates<T> &other) const
        {
            return (T)std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
        }

        operator std::string() const
        {
            return str();
        }

        Coordinates<T> move(Direction direction)
        {
            *this = this->look(direction);
            return *this;
        }

    private:
        bool null = false;

        std::string str() const
        {
            std::stringstream ss;
            ss << std::string("Coordinates(x= ") << x << std::string(", y=") << y << ")";
            std::string s = ss.str();
            return s;
        }
    };

    template <typename T>
    Direction compareDirection(const Coordinates<T> &you, const Coordinates<T> &object)
    {
        if (you.x == object.x)
        {
            if (you.y > object.y)
            {
                return Direction::UP;
            }
            else
            {
                return Direction::DOWN;
            }
        }
        else
        {
            if (you.x > object.x)
            {
                return Direction::LEFT;
            }
            else
            {
                return Direction::RIGHT;
            }
        }
    }
}

#endif