#include "food.h"

Food::Food(){
    Food::genFood();
}

COORD Food::getPos(){
    return this->pos; 
}

void Food::genFood(){
    this->pos.X = rand() % WIDTH + 1;
    this->pos.Y = rand() % HEIGHT + 1;
}