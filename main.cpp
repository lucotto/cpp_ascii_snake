#include <ctime> // std::time

#include "snake.h"
#include "food.h"
#include "const.h"
#include "print.h"

std::ofstream out;

COORD startingPos = {1, 1};
Snake snake(startingPos, 1);
Food food(out);
Print print;

void gameEnd(){
    
}

int main(){
    std::srand(std::time(NULL));
    bool gameOver = false;
    out.open("output.txt");

    initscr();
    noecho();
    curs_set(0);
    cbreak();
    keypad(stdscr, true);
    start_color();

    print.infoBox();

    while (!gameOver){
        print.board(snake, food);

        snake.move();
        snake.playerInput();
        refresh();

        if (snake.eaten(food.getPos())){
            food.genFood(out);
            snake.grow();
            refresh();
        }

        if (snake.isColliding()) gameOver = true;
    }
    
    print.gameEnd(snake);
    refresh();
    endwin();
    return 0;
}