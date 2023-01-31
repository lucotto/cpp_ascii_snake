#include <ncurses/ncurses.h>

int main(){
    initscr();
    printw("Hello");
    refresh();
    getch();
    endwin();
    return 0;
}