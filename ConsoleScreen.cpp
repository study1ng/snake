#include "curses.h"
#include "ConsoleScreen.hpp"

namespace snake
{
    void ConsoleScreen::init()
    {
        initscr();
        noecho();
        curs_set(0);
        keypad(stdscr, TRUE);
    }
    void ConsoleScreen::end()
    {
        echo();
        keypad(stdscr, FALSE);
        endwin();
    }
    void ConsoleScreen::draw(SnakeMap map)
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
    int ConsoleScreen::getMapWidth()
    {
        return COLS / 2;
    }
    int ConsoleScreen::getMapHeight()
    {
        return LINES / 2;
    }
}
