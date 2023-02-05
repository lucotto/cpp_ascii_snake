#ifndef FOOD_H
#define FOOD_H

#include <windows.h>

class Food{
    public:
        Food();
        void genFood();
        COORD getPos();

    private:
        COORD pos;
};

#endif