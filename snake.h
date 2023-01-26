#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <conio.h>

class Snake{
    public:
        Snake(COORD pos, int vel);
        void playerInput();
        void turn(char dir);
        void move();
        COORD getPos();
        int getLen();
        bool eaten(COORD foodPos);
        void grow();

    private:
        COORD pos;
        int len;
        int vel;
        char dir;
};

#endif