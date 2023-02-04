#ifndef PRINT_H
#define PRINT_H

#include <curses.h>
#include <windows.h>

#include "snake.h"
#include "food.h"
#include "const.h"

class Print{
    public:
        Print() = default;
        void board(Snake &snake, Food &food);
        void infoBox();
        void pause();
        void gameEnd(Snake &snake);
        
    private:


};

#endif