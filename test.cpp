#include <curses.h>
#include <iostream>

int main() {
    initscr();
    noecho();
    cbreak();
    refresh();

    // Crea la prima finestra
    WINDOW *win1 = newwin(5, 20, 1, 1);
    box(win1, 0, 0);
    mvwprintw(win1, 2, 5, "Finestra 1");
    wrefresh(win1);
    refresh();

    // Crea la seconda finestra
    WINDOW *win2 = newwin(5, 20, 7, 1);
    box(win2, 0, 0);
    mvwprintw(win2, 2, 5, "Finestra 2");
    wrefresh(win2);
    refresh();

    // Attendi l'input dell'utente prima di terminare
    getch();
    endwin();
    return 0;
}