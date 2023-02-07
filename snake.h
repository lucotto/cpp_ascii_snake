#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <curses.h>

enum Direction{
    up = 1,
    down = -1,
    left = 2,
    right = -2
};

class Snake{
    public:
        Snake() = default;
        Snake(COORD pos, int vel);
        void playerInput();
        void turn(Direction d);
        void move();
        std::vector<COORD> getCoords();
        COORD getHeadPos();
        int getLen();

        bool eaten(COORD foodPos);
        void grow();
        bool isColliding(std::vector<COORD> obs);
        bool isBody(const int &i, const int &j);

        void halve();
        
    private:
        std::vector<COORD> pos;
        int len;
        int vel;
        int dir;
};

#endif