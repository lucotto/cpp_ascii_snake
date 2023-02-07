#ifndef FOOD_H
#define FOOD_H

#include <windows.h>

class Food{
    public:
        Food();
        void genFood();
        void genHalf();
        COORD getPos();
        COORD getHalf();
        bool isHalfSpawn();
        void popHalf();

    private:
        COORD foodPos;
        COORD halfPos;
        bool halfSpawn = false;
        int halfLifetime = 0;
};

#endif