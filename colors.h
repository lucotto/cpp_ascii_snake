#ifndef COLORS_H
#define COLORS_H

#include <curses.h>

#define K 1000.0/255.0

#define BG        1
#define BG_AUX    2
#define TITLE     3
#define TITLE_AUX 4
#define SUBTITLE  5
#define DESC      6
#define SNAKEH    7
#define SNAKEB    8
#define WALL      9
#define GRASS     10
#define FOOD      11

inline void colors(){
    start_color();
    use_default_colors();

    init_color(0, K*26, K*28, K*44);          // #1a1c2c
    init_color(1, K*93, K*39, K*93);          // #5d275d
    init_color(2, K*177, K*62, K*83);         // #b13e53
    init_color(3, K*239, K*125, K*87);        // #ef7d57
    init_color(4, K*255, K*205, K*117);       // #ffcd75
    init_color(5, K*167, K*240, K*112);       // #a7f070
    init_color(6, K*56, K*183, K*100);        // #38b764
    init_color(7, K*37, K*113, K*121);        // #257179
    init_color(8, K*41, K*54, K*111);         // #29366f
    init_color(9, K*59, K*93, K*201);         // #3b5dc9
    init_color(10, K*65, K*166, K*246);       // #41a6f6
    init_color(11, K*115, K*239, K*247);      // #73eff7
    init_color(12, K*244, K*244, K*244);      // #f4f4f4
    init_color(13, K*148, K*176, K*194);      // #94b0c2
    init_color(14, K*86, K*108, K*134);       // #566c86
    init_color(15, K*51, K*60, K*87);         // #333c57

    init_pair(BG, 0, 0);
    init_pair(BG_AUX, 1, 1);
    init_pair(TITLE, 4, 0);
    init_pair(TITLE_AUX, 5, 1);
    init_pair(SUBTITLE, 11, 1);
    init_pair(DESC, 12, 1);
    init_pair(SNAKEH, 0, 5);
    init_pair(SNAKEB, 12, 2);
    init_pair(WALL, 12, 0);
    init_pair(GRASS, 5, 0);
    init_pair(FOOD, 0, 3);
}


#endif