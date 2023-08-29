#include "curses.h"
#include "SnakeErrors.hpp"
#include "ConsoleScreen.hpp"

namespace snake
{
    ConsoleScreen::ConsoleScreen(int width, int height): 
        width(width), 
        height(height) {}
    void ConsoleScreen::init()
    {
        initscr();
        noecho();
        curs_set(0);
        keypad(stdscr, TRUE);
        if (COLS < 11 + 15)
        {
            throw *new InvalidEnvironmentException("Too small screen width");
        }
        if (LINES < 11)
        {
            throw *new InvalidEnvironmentException("Too small screen height");
        }
        if (width == -1)
        {
            width = COLS / 2;
        }
        else if (width > COLS - 15) // 15 is the width of information area
        {
            width = COLS - 15;
        }
        
        if (height == -1)
        {
            height = LINES / 2;
        }
        else if (height > LINES)
        {
            height = LINES;
        }
    }
    void ConsoleScreen::end()
    {
        echo();
        keypad(stdscr, FALSE);
        endwin();
    }
    void ConsoleScreen::draw(SnakeMap &map)
    {
        for (int i = 0; i < map.getHeight(); i++)
        {
            for (int j = 0; j < map.getWidth(); j++)
            {
                mvaddch(i, j, (char)map[i][j]);
            }
        }
        refresh();
    }
    void ConsoleScreen::show_information(SnakeGame &game){}
    
    int ConsoleScreen::getMapWidth()
    {
        return this->width;
    }
    int ConsoleScreen::getMapHeight()
    {
        return this->height;
    }
}
