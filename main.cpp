#include <ctime> // std::time

#include "snake.h"
#include "food.h"
#include "const.h"
#include "print.h"

COORD startingPos = {1, 1};
Snake snake(startingPos, 1);
Food food;
Print print(snake, food);

void gameEnd(){
    
}

int main(){
    std::srand(std::time(NULL));
    bool gameOver = false;

    initscr();
    noecho();
    curs_set(0);
    cbreak();
    keypad(stdscr, true);
    start_color();

    print.infoBox();
    print.setObstacles();

    while (!gameOver){
        print.board();
        print.score();

        snake.move();
        snake.playerInput();
        refresh();

        if (snake.eaten(food.getPos())){
            food.genFood();
            snake.grow();
            refresh();
        }

        if (snake.isColliding(print.getObstacles())) gameOver = true;
    }
    
    print.gameEnd(snake);
    refresh();
    endwin();
    return 0;
}