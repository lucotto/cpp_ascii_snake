#include <curses.h>
#include <iostream>

#define K 1000.0/255.0

#define BACKGROUND 0

int main() {
    initscr();
    start_color();

    init_color(0, 0*K, 0*K, 0*K);       
    init_color(1, 195*K, 136*K, 144*K); 
    init_color(2, 124*K, 161*K, 192*K); 
    init_color(3, 56*K, 112*K, 128*K);  
    init_color(4, 157*K, 159*K, 127*K);
    init_color(5, 111*K, 103*K, 118*K);
    init_color(6, 165*K, 147*K, 165*K);
    init_color(7, 65*K, 106*K, 163*K);
    init_color(8, 110*K, 105*K, 98*K);
    init_color(9, 126*K, 158*K, 153*K);
    init_color(10, 154*K, 154*K, 151*K);
    init_color(11, 102*K, 96*K, 146*K);
    init_color(12, 141*K, 98*K, 104*K);
    init_color(13, 147*K, 161*K, 103*K);
    init_color(14, 93*K, 104*K, 114*K);
    init_color(15, 197*K, 204*K, 184*K);
    init_color(16, 154*K, 79*K, 80*K);
    init_color(17, 190*K, 149*K, 92*K);
    init_color(18, 110*K, 170*K, 120*K);
    init_color(19, 67*K, 52*K, 85*K);
    init_color(20, 139*K, 85*K, 128*K);
    init_color(21, 194*K, 141*K, 117*K);
    init_color(22, 104*K, 172*K, 169*K);
    init_color(23, 85*K, 112*K, 100*K);

    init_pair(BACKGROUND, 19, 0);
    init_pair(1, 19, COLOR_BLACK);
    init_pair(2, 2, COLOR_BLACK);
    init_pair(3, 3, COLOR_BLACK);
    init_pair(4, 4, COLOR_BLACK);
    init_pair(5, 5, COLOR_BLACK);

    wbkgd(stdscr, COLOR_PAIR(BACKGROUND));

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