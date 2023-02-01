#ifndef FOOD_H
#define FOOD_H

#include <windows.h>
#include <fstream>

class Food{
    public:
        Food(std::ofstream &out);
        void genFood(std::ofstream &out);
        COORD getPos();

    private:
        COORD pos;
};

#endif