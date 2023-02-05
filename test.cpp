#include <curses.h>
#include <iostream>

#define CONV 1000/255

void torgb(int hex){
    
}

int main() {
    initscr();
    start_color();

    init_color(9, 0*CONV, 0*CONV, 0*CONV);
    init_color(1, 0*CONV, 3*CONV, 199*CONV);
    init_color(2, 250*CONV, 91*CONV, 15*CONV);
    init_color(3, 69*CONV, 191*CONV, 85*CONV);
    init_color(4, 123*CONV, 31*CONV, 162*CONV);
    init_color(5, 255*CONV, 234*CONV, 0*CONV);

    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, 1, COLOR_BLACK);
    init_pair(2, 2, COLOR_BLACK);
    init_pair(3, 3, COLOR_BLACK);
    init_pair(4, 4, COLOR_BLACK);
    init_pair(5, 5, COLOR_BLACK);

    wbkgd(stdscr, COLOR_PAIR(6));

    attron(COLOR_PAIR(1));
    mvprintw(10, 10, "COLORE #1\n");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(11, 11, "COLORE #2\n");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(3));
    mvprintw(12, 12, "COLORE #3\n");
    attroff(COLOR_PAIR(3));
    
    attron(COLOR_PAIR(4));
    mvprintw(13, 13, "COLORE #4\n");
    attroff(COLOR_PAIR(4));
    
    attron(COLOR_PAIR(5));
    mvprintw(14, 14, "COLORE #5\n");
    attroff(COLOR_PAIR(5));

    /*
    attron(A_BOLD);
    attron(COLOR_PAIR(1));
    mvprintw(15, 15, "COLORE #1\n");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(16, 16, "COLORE #2\n");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(3));
    mvprintw(17, 17, "COLORE #3\n");
    attroff(COLOR_PAIR(3));
    
    attron(COLOR_PAIR(4));
    mvprintw(18, 18, "COLORE #4\n");
    attroff(COLOR_PAIR(4));
    
    attron(COLOR_PAIR(5));
    mvprintw(19, 19, "COLORE #5\n");
    attroff(COLOR_PAIR(5));
    attroff(A_BOLD);
    */

    refresh();
    while(true){};
    endwin();
    return 0;
}