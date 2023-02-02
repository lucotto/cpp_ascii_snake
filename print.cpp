#include "print.h"

void Print::board(Snake &snake, Food &food){    // def terminal is 120x30
    COORD snakeHeadPos = snake.getHeadPos();
    COORD foodPos = food.getPos();
    
    // in mvaddch i is i+5, j is j+30 (board origin is [30,5])
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            if (i == 0){
                if (j == 0) mvaddch(i+5, j+30, ACS_ULCORNER);
                else if (j == WIDTH-1) mvaddch(i+5, j+30, ACS_URCORNER);
                else mvaddch(i+5, j+30, ACS_HLINE);
            }
            else if (i == HEIGHT-1){
                if (j == 0) mvaddch(i+5, j+30, ACS_LLCORNER);
                else if (j == WIDTH-1) mvaddch(i+5, j+30, ACS_LRCORNER);
                else mvaddch(i+5, j+30, ACS_HLINE);
            }
            else if (j == 0 || j == WIDTH-1) mvaddch(i+5, j+30, ACS_VLINE);
            else if (j == snakeHeadPos.X && i == snakeHeadPos.Y) mvaddch(i+5, j+30, '0');
            else if (snake.isBody(j, i)) mvaddch(i+5, j+30, 'o');
            else if (j == foodPos.X && i == foodPos.Y) mvaddch(i+5, j+30, 'F');
            else mvaddch(i+5, j+30, '.');
        }
    }
}

void Print::infoBox(){

}

void Print::gameEnd(Snake &snake){
    clear();
    printw("Game Over\n");
    printw("Score: %d", snake.getLen()-1);
    printw("\nPress ESC to quit...");
    while(getch() != ESC){;};
}

void Print::pause(){
    halfdelay(-1);
    while(getch() != ESC || getch() != 'p'){
        attron(A_BOLD);
        mvprintw(HEIGHT+1, WIDTH/2-5, "Pause");
        attroff(A_BOLD);
        mvprintw(HEIGHT+2, 1, "Press ESC or P to unpause...");
    }
}