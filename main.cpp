#include <cstdlib>
#include <ctime>
#include <ncurses/ncurses.h>

#include "snake.h"
#include "food.h"

#define WIDTH 50
#define HEIGHT 30
#define ESC 27
std::ofstream out;

COORD startingPos = {1, 1};
Snake snake(startingPos, 1);
Food food(out);

void board(){
    COORD snakeHeadPos = snake.getHeadPos();
    COORD foodPos = food.getPos();

    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            if (i == 0 || i == HEIGHT-1 || j == 0 || j == WIDTH-1){
                mvprintw(i, j, "#");
            }
            else if (j == snakeHeadPos.X && i == snakeHeadPos.Y){
                mvprintw(i, j, "0");
            }
            else if (snake.isBody(j, i)){
                mvprintw(i, j, "o");
            }
            else if (j == foodPos.X && i == foodPos.Y){
                mvprintw(i, j, "F");
            }
            else mvprintw(i, j, ".");
        }
    }
}

void gameEnd(){
    clear();
    printw("Game Over\n");
    printw("Score: %d", snake.getLen()-1);
    printw("\nPress ESC to quit...");
    getch();
}

int main(){
    std::srand(std::time(NULL));
    bool gameOver = false;
    out.open("output.txt");

    initscr();
    noecho();
    curs_set(0);
    cbreak();

    nodelay(stdscr, true);
    while (!gameOver){
        board();
        snake.move();
        refresh();

        snake.playerInput();

        if (snake.eaten(food.getPos())){
            food.genFood(out);
            snake.grow();
            refresh();
        }

        if (snake.isColliding()) gameOver = true;
    }
    
    gameEnd();
    refresh();
    getch();
    endwin();
    return 0;
}