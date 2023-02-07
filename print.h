#ifndef PRINT_H
#define PRINT_H

#include <curses.h>
#include <windows.h>
#include <vector>

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

        void setObstacles();
        std::vector<COORD> getObstacles();
        bool isObstacle(int &i, int &j);

    private:
        Snake &snakeRef;
        Food &foodRef;
        std::vector<COORD> obstacles;
};

#endif
