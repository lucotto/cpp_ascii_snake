#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <algorithm>

class Snake{
    public:
        Snake(COORD pos, int vel);
        void playerInput();
        void turn(char dir);
        void move();
        std::vector<COORD> getCoords();
        COORD getHeadPos();
        int getLen();
        bool eaten(COORD foodPos);
        void grow();
        bool isColliding();
        bool isBody(const int &i, const int &j);

    private:
        std::vector<COORD> pos;
        int len;
        int vel;
        char dir;
};

#endif