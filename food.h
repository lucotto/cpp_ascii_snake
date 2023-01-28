#ifndef FOOD_H
#define FOOD_H

#include <windows.h>
#include <fstream>

#define WIDTH 50
#define HEIGHT 30

class Food{
    public:
        Food(std::ofstream &out);
        void genFood(std::ofstream &out);
        COORD getPos();

    private:
        COORD pos;
};

#endif