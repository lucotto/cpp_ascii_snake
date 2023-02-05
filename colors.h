#ifndef COLORS_H
#define COLORS_H

#include <curses.h>

#define TEXT_1     1   // YELLOW on BLACK
#define TEXT_2     2   // 
#define TEXT_3     3
#define TEXT_4     4
#define WALL       5
#define GRASS      6
#define SNAKEH     7
#define SNAKEB     8
#define BACKGROUND 9

inline void colors(){
    start_color();

    init_color(0, 126, 206, 253);   // BG
    // init_color(0, 0, 75, 141);   // BG

    init_pair(TEXT_1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(SNAKEH, COLOR_WHITE, COLOR_GREEN);
    init_pair(SNAKEB, COLOR_WHITE, COLOR_RED);
    init_pair(BACKGROUND, COLOR_WHITE, COLOR_BLACK);

}

#endif