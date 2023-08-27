/// @file map_element.hpp
/// @brief This file contains the declaration of MapElement class.
/// @author Daisuke KATO
/// @date 2023/08/27
/// COPYRIGHT NOTICE: Look at COPYRIGHT file if it exists. Else then all rights reserved.
#ifndef MAP_ELEMENT_HPP
#define MAP_ELEMENT_HPP
#include "math_expansion/coordinates.hpp"

/// @brief This is the namespace for the snake game.
namespace snake
{

    using namespace math_expansion;

    /// @brief This class represents a element in the map.
    /// @details MapElement is a class that represents a element in the map. This class can be used as if it is a enum class. Plus, it also contains some useful helper functions.

    class MapElement
    {
    public:
        enum MAP_ELEMENT
        {
            ROAD = '.',
            BAIT = 'x',
            SNAKE_BODY = 'o',
            UP_HEAD = '^',
            DOWN_HEAD = 'v',
            LEFT_HEAD = '<',
            RIGHT_HEAD = '>'
        };

    public:
        /// @brief Construct a new Map Element object from a Direction
        /// @param d Direction which will be converted like UP -> UP_HEAD
        /// @throws EnumNoMatchException if d is not a head
        MapElement(Direction d);
        /// @brief Construct a new Map Element object from a MAP_ELEMENT
        /// @param e this will be the element
        MapElement(MAP_ELEMENT e);
        /// @brief default constructor, will be ROAD
        MapElement();

        /// @brief cast to Direction.
        /// @throws EnumNoMatchException if element is not a head
        operator Direction();
        /// @brief cast to MAP_ELEMENT
        operator MAP_ELEMENT();
        /// @brief cast to char.
        /// @return The mark displayed in the screen.
        operator char();
        /// @brief cast to std::string.
        /// @return Name in the code
        operator std::string();

        /// @brief get the name of the element. Same as operator std::string()
        /// @return Name in the code
        std::string getName();

    private:
        /// @brief The content of this
        MAP_ELEMENT element;
    };

}
#endif