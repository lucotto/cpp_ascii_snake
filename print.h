#ifndef PRINT_H
#define PRINT_H

#include <curses.h>
#include <windows.h>

#include "snake.h"
#include "food.h"
#include "const.h"

class Print{
    public:
        Print()
            : snakeRef(*(new Snake())), foodRef(*(new Food()))
        {
        }
        Print(Snake &snake, Food &food);
        void board();
        void infoBox();
        void pause();
        void gameEnd(Snake &snake);
        
    private:
        Snake &snakeRef;
        Food &foodRef;
};

#endif

// ---- FUNZIONA (stdscr)
//init_pair(1, COLOR_RED, COLOR_BLACK);
//attron(COLOR_PAIR(1));
//attroff(COLOR_PAIR(1));