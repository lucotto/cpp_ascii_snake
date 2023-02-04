#include "print.h"

void Print::board(Snake &snake, Food &food){    // def terminal is 120x30
    COORD snakeHeadPos = snake.getHeadPos();
    COORD foodPos = food.getPos();
    
    // in mvaddch i is i+5, j is j+20 (board origin is [30,5])
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
            else if (snake.isBody(j, i)) mvaddch(i+5, j+20, 'o');
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
    halfdelay(-1);
    while(getch() != ESC || getch() != 'p'){
        attron(A_BOLD);
        mvprintw(HEIGHT+1, WIDTH/2-5, "Pause");
        attroff(A_BOLD);
        mvprintw(HEIGHT+2, 1, "Press ESC or P to unpause...");
    }
}