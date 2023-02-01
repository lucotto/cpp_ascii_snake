#include "game.h"
#include "const.h"

void Game::pause(){
    halfdelay(-1);
    while(getch() != ESC || getch() != 'p'){
        attron(A_BOLD);
        mvprintw(HEIGHT+1, WIDTH/2-5, "Pause");
        attroff(A_BOLD);
        mvprintw(HEIGHT+2, 1, "Press ESC or P to unpause...");
    }
}