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
        void score();

        
    private:
        Snake &snakeRef;
        Food &foodRef;
};

#endif
