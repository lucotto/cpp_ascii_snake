#include <curses.h>
#include <iostream>

#define K 1000.0/255.0

int main() {
    initscr();
    start_color();
    int count = COLOR_PAIRS;

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

    init_pair(1, 0, COLOR_BLACK);
    init_pair(2, 1, COLOR_BLACK);
    init_pair(3, 2, COLOR_BLACK);
    init_pair(4, 3, COLOR_BLACK);
    init_pair(5, 4, COLOR_BLACK);
    init_pair(6, 5, COLOR_BLACK);
    init_pair(7, 6, COLOR_BLACK);
    init_pair(8, 7, COLOR_BLACK);
    init_pair(9, 8, COLOR_BLACK);
    init_pair(10, 9, COLOR_BLACK);
    init_pair(11, 10, COLOR_BLACK);
    init_pair(12, 11, COLOR_BLACK);
    init_pair(13, 12, COLOR_BLACK);
    init_pair(14, 13, COLOR_BLACK);
    init_pair(15, 14, COLOR_BLACK);
    init_pair(16, 15, COLOR_BLACK);
    init_pair(17, 16, COLOR_BLACK);
    init_pair(18, 17, COLOR_BLACK);
    init_pair(19, 18, COLOR_BLACK);
    init_pair(20, 19, COLOR_BLACK);
    init_pair(21, 20, COLOR_BLACK);
    init_pair(22, 21, COLOR_BLACK);
    init_pair(23, 22, COLOR_BLACK);
    init_pair(24, 23, COLOR_BLACK);

    WINDOW *win = newwin(0, 0, 0, 0);
    wbkgd(win, COLOR_PAIR(20));
    wrefresh(win);
    refresh();

    attron(COLOR_PAIR(1));
    mvprintw(11, 11, "COLORE #2\n");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(12, 12, "COLORE #3\n");
    attroff(COLOR_PAIR(2));
    
    attron(COLOR_PAIR(3));
    mvprintw(13, 13, "COLORE #4\n");
    attroff(COLOR_PAIR(3));
    
    attron(COLOR_PAIR(4));
    mvprintw(14, 14, "COLORE #5\n");
    attroff(COLOR_PAIR(4));
    
    attron(COLOR_PAIR(5));
    mvprintw(15, 15, "COLORE #6\n");
    attroff(COLOR_PAIR(5));
    
    attron(COLOR_PAIR(6));
    mvprintw(16, 16, "COLORE #7\n");
    attroff(COLOR_PAIR(6));
    
    attron(COLOR_PAIR(7));
    mvprintw(17, 17, "COLORE #8\n");
    attroff(COLOR_PAIR(7));
    
    attron(COLOR_PAIR(8));
    mvprintw(18, 18, "COLORE #9\n");
    attroff(COLOR_PAIR(8));
    
    attron(COLOR_PAIR(9));
    mvprintw(19, 19, "COLORE #10\n");
    attroff(COLOR_PAIR(9));
    
    attron(COLOR_PAIR(10));
    mvprintw(20, 20, "COLORE #11\n");
    attroff(COLOR_PAIR(10));
    
    attron(COLOR_PAIR(11));
    mvprintw(21, 21, "COLORE #12\n");
    attroff(COLOR_PAIR(11));
    
    attron(COLOR_PAIR(12));
    mvprintw(22, 22, "COLORE #13\n");
    attroff(COLOR_PAIR(12));
    
    attron(COLOR_PAIR(13));
    mvprintw(23, 23, "COLORE #14\n");
    attroff(COLOR_PAIR(13));
    
    attron(COLOR_PAIR(14));
    mvprintw(24, 24, "COLORE #15\n");
    attroff(COLOR_PAIR(14));
    
    attron(COLOR_PAIR(15));
    mvprintw(25, 25, "COLORE #16\n");
    attroff(COLOR_PAIR(15));
    
    attron(COLOR_PAIR(16));
    mvprintw(26, 26, "COLORE #17\n");
    attroff(COLOR_PAIR(16));
    
    attron(COLOR_PAIR(17));
    mvprintw(27, 27, "COLORE #18\n");
    attroff(COLOR_PAIR(17));
    
    attron(COLOR_PAIR(18));
    mvprintw(28, 28, "COLORE #19\n");
    attroff(COLOR_PAIR(18));
    
    attron(COLOR_PAIR(19));
    mvprintw(10, 50, "COLORE #20\n");
    attroff(COLOR_PAIR(19));
    
    attron(COLOR_PAIR(20));
    mvprintw(11, 51, "COLORE #21\n");
    attroff(COLOR_PAIR(20));
    
    attron(COLOR_PAIR(21));
    mvprintw(12, 52, "COLORE #22\n");
    attroff(COLOR_PAIR(21));
    
    attron(COLOR_PAIR(22));
    mvprintw(13, 53, "COLORE #23\n");
    attroff(COLOR_PAIR(22));

    attron(COLOR_PAIR(23));
    mvprintw(14, 54, "COLORE #24\n");
    attroff(COLOR_PAIR(23));

    attron(COLOR_PAIR(24));
    mvprintw(15, 55, "COLORE #25\n");
    attroff(COLOR_PAIR(24));

    refresh();
    while(true){};
    endwin();
    return 0;
}