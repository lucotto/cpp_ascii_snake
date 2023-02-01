#include <cstdlib>
#include <ctime>

#include "snake.h"
#include "food.h"
#include "game.h"
#include "const.h"

std::ofstream out;

COORD startingPos = {1, 1};
Snake snake(startingPos, 1);
Food food(out);

void board(){
    COORD snakeHeadPos = snake.getHeadPos();
    COORD foodPos = food.getPos();

    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            if (i == 0){
                if (j == 0) mvaddch(i, j, ACS_ULCORNER);
                else if (j == WIDTH-1) mvaddch(i, j, ACS_URCORNER);
                else mvaddch(i, j, ACS_HLINE);
            }
            else if (i == HEIGHT-1){
                if (j == 0) mvaddch(i, j, ACS_LLCORNER);
                else if (j == WIDTH-1) mvaddch(i, j, ACS_LRCORNER);
                else mvaddch(i, j, ACS_HLINE);
            }
            else if (j == 0 || j == WIDTH-1) mvaddch(i, j, ACS_VLINE);
            else if (j == snakeHeadPos.X && i == snakeHeadPos.Y) mvprintw(i, j, "0");
            else if (snake.isBody(j, i)) mvprintw(i, j, "o");
            else if (j == foodPos.X && i == foodPos.Y) mvprintw(i, j, "F");
            else mvprintw(i, j, ".");
        }
    }
}

void gameEnd(){
    clear();
    printw("Game Over\n");
    printw("Score: %d", snake.getLen()-1);
    printw("\nPress ESC to quit...");
    while(getch() != ESC){;};
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

    while (!gameOver){
        board();

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
    
    gameEnd();
    refresh();
    endwin();
    return 0;
}