#include <curses.h>

int main(){
    initscr();
    start_color();

    init_pair(1, COLOR_BLUE, COLOR_BLUE);

    wbkgd(stdscr, COLOR_PAIR(1));
    refresh();

    getch();

    return 0;
}