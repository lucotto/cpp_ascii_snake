#ifndef FOOD_H
#define FOOD_H

#include <windows.h>

#define WIDTH 50
#define HEIGHT 30

class Food{
    public:
        Food();
        void genFood();
        COORD getPos();

    private:
        COORD pos;
};

#endif