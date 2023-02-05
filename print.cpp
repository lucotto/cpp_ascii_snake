#include "print.h"

Print::Print(Snake &snake, Food &food)
    : snakeRef(snake), foodRef(food){
    }

void Print::board(){    // def terminal is 120x30
    COORD snakeHeadPos = snakeRef.getHeadPos();
    COORD foodPos = foodRef.getPos();
    
    attron(A_BOLD);
    mvprintw(3, 20 + (WIDTH-5)/2, "Snake");
    attroff(A_BOLD);
    
    // in mvaddch i is i+5, j is j+20 (board origin is [20,5])
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            if (i == 0){
                if (j == 0) mvaddch(i+5, j+20, ACS_ULCORNER);
                else if (j == WIDTH-1) mvaddch(i+5, j+20, ACS_URCORNER);
                else mvaddch(i+5, j+20, ACS_HLINE);
            }
            else if (i == HEIGHT-1){
                if (j == 0) mvaddch(i+5, j+20, ACS_LLCORNER);
                else if (j == WIDTH-1) mvaddch(i+5, j+20, ACS_LRCORNER);
                else mvaddch(i+5, j+20, ACS_HLINE);
            }
            else if (j == 0 || j == WIDTH-1) mvaddch(i+5, j+20, ACS_VLINE);
            else if (j == snakeHeadPos.X && i == snakeHeadPos.Y) mvaddch(i+5, j+20, '0');
            else if (snakeRef.isBody(j, i)) mvaddch(i+5, j+20, 'o');
            else if (j == foodPos.X && i == foodPos.Y) mvaddch(i+5, j+20, 'F');
            else mvaddch(i+5, j+20, '.');
        }
    }
}

void Print::infoBox(){
    const int ROWS = 11;
    const int YOFF = 10;
    const int COLS = 27;
    const int XOFF = 85;
    WINDOW *win = newwin(ROWS, COLS, YOFF, XOFF);

    refresh();
    box(win, 0, 0);

    attron(A_STANDOUT);
    mvprintw(YOFF, XOFF+(COLS-4)/2, "Keys");
    attroff(A_STANDOUT);
    

    attron(A_BOLD);
    mvprintw(YOFF+2, XOFF+2, "Up: ");
    mvprintw(YOFF+3, XOFF+2, "Down: ");
    mvprintw(YOFF+4, XOFF+2, "Left: ");
    mvprintw(YOFF+5, XOFF+2, "Right: ");
    mvprintw(YOFF+7, XOFF+2, "Pause:");
    mvprintw(YOFF+8, XOFF+2, "Quit:");
    attroff(A_BOLD);

    mvprintw(YOFF+2, XOFF+9, "w, up arrow");
    mvprintw(YOFF+3, XOFF+9, "s, down arrow");
    mvprintw(YOFF+4, XOFF+9, "a, left arrow");
    mvprintw(YOFF+5, XOFF+9, "d, right arrow");
    mvprintw(YOFF+7, XOFF+9, "p, ESC");
    mvprintw(YOFF+8, XOFF+9, "q");
    
    wrefresh(win);
    refresh();
}

void Print::gameEnd(Snake &snake){
    clear();
    printw("Game Over\n");
    printw("Score: %d", snake.getLen()-1);
    printw("\nPress ESC to quit...");
    while(getch() != ESC){;};
}

void Print::pause(){
    const int ROWS = 8;
    const int COLS = 17;
    const int YOFF = (HEIGHT-ROWS)/2 + 5 - 2;
    const int XOFF = (WIDTH-COLS)/2 + 20;

    WINDOW *pause = newwin(ROWS, COLS, YOFF, XOFF);
    refresh();
    box(pause, 0, 0);
    wrefresh(pause);

    attron(A_BOLD);
    mvprintw(YOFF+1, XOFF+(COLS-5)/2, "Pause");
    attroff(A_BOLD);
    mvprintw(YOFF+4, XOFF+3, "Press p,ESC");
    mvprintw(YOFF+5, XOFF+3, " to resume ");

    while(true){
        if (getch() == ESC || getch() == 'p'){
            clear();
            this->infoBox();
            refresh();
            break;
        }
    }
}