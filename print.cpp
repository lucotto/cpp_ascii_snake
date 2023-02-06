#include "print.h"

Print::Print(Snake &snake, Food &food)
    : snakeRef(snake), foodRef(food){
    }

void Print::board(){    // def terminal is 120x30
    COORD snakeHeadPos = snakeRef.getHeadPos();
    COORD foodPos = foodRef.getPos();
    
    attron(COLOR_PAIR(TITLE));
    mvprintw(3, 20 + (WIDTH-10)/2, "S N A K E");
    attroff(COLOR_PAIR(TITLE));
    
    // in mvaddch i is i+5, j is j+20 (board origin is [20,5])
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            if (i == 0){
                attron(COLOR_PAIR(WALL));
                if (j == 0) mvaddch(i+5, j+20, ACS_ULCORNER);
                else if (j == WIDTH-1) mvaddch(i+5, j+20, ACS_URCORNER);
                else mvaddch(i+5, j+20, ACS_HLINE);
                attroff(COLOR_PAIR(WALL));
            }
            else if (i == HEIGHT-1){
                attron(COLOR_PAIR(WALL));
                if (j == 0) mvaddch(i+5, j+20, ACS_LLCORNER);
                else if (j == WIDTH-1) mvaddch(i+5, j+20, ACS_LRCORNER);
                else mvaddch(i+5, j+20, ACS_HLINE);
                attroff(COLOR_PAIR(WALL));
            }
            else if (j == 0 || j == WIDTH-1){
                attron(COLOR_PAIR(WALL));
                mvaddch(i+5, j+20, ACS_VLINE);
                attroff(COLOR_PAIR(WALL));
            }
            else if (j == snakeHeadPos.X && i == snakeHeadPos.Y){
                attron(COLOR_PAIR(SNAKEH));
                mvaddch(i+5, j+20, '0');
                attroff(COLOR_PAIR(SNAKEH));
            }
            else if (snakeRef.isBody(j, i)){
                attron(COLOR_PAIR(SNAKEB));
                mvaddch(i+5, j+20, 'o');
                attroff(COLOR_PAIR(SNAKEB));
            }
            else if (j == foodPos.X && i == foodPos.Y){
                attron(COLOR_PAIR(FOOD));
                mvaddch(i+5, j+20, 'F');
                attroff(COLOR_PAIR(FOOD));
            }
            else{
                attron(COLOR_PAIR(GRASS));
                mvaddch(i+5, j+20, '.');
                attroff(COLOR_PAIR(GRASS));
            }
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
    wattron(win, COLOR_PAIR(WALL));
    box(win, 0, 0);
    wattroff(win, COLOR_PAIR(WALL));
    wbkgd(win, COLOR_PAIR(BG_AUX));
    wrefresh(win);

    attron(COLOR_PAIR(TITLE_AUX));
    mvprintw(YOFF, XOFF+(COLS-4)/2, "Keys");
    attroff(COLOR_PAIR(TITLE_AUX));
    
    attron(COLOR_PAIR(SUBTITLE));
    mvprintw(YOFF+2, XOFF+2, "Up: ");
    mvprintw(YOFF+3, XOFF+2, "Down: ");
    mvprintw(YOFF+4, XOFF+2, "Left: ");
    mvprintw(YOFF+5, XOFF+2, "Right: ");
    mvprintw(YOFF+7, XOFF+2, "Pause:");
    mvprintw(YOFF+8, XOFF+2, "Quit:");
    attroff(COLOR_PAIR(SUBTITLE));

    attron(COLOR_PAIR(DESC));
    mvprintw(YOFF+2, XOFF+9, "w, up arrow");
    mvprintw(YOFF+3, XOFF+9, "s, down arrow");
    mvprintw(YOFF+4, XOFF+9, "a, left arrow");
    mvprintw(YOFF+5, XOFF+9, "d, right arrow");
    mvprintw(YOFF+7, XOFF+9, "p, ESC");
    mvprintw(YOFF+8, XOFF+9, "q");
    attroff(COLOR_PAIR(DESC));

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
    wattron(pause, COLOR_PAIR(WALL));
    box(pause, 0, 0);
    wattroff(pause, COLOR_PAIR(WALL));
    wbkgd(pause, COLOR_PAIR(BG_AUX));
    wrefresh(pause);

    attron(COLOR_PAIR(TITLE_AUX));
    mvprintw(YOFF+1, XOFF+(COLS-5)/2, "Pause");
    attroff(COLOR_PAIR(TITLE_AUX));
    attron(COLOR_PAIR(DESC));
    mvprintw(YOFF+4, XOFF+3, "Press p,ESC");
    mvprintw(YOFF+5, XOFF+3, " to resume ");
    attroff(COLOR_PAIR(DESC));

    while(true){
        if (getch() == ESC || getch() == 'p'){
            clear();
            this->infoBox();
            refresh();
            break;
        }
    }
}

void Print::score(){
    mvprintw(4, 21, "Score: %d", snakeRef.getLen()-1);
}