#include "food.h"
#include "const.h"

Food::Food(){
    this->genFood();
}

COORD Food::getPos(){
    return this->pos; 
}

void Food::genFood(){
    this->pos.X = 1 + rand() % (WIDTH - 2);
    this->pos.Y = 1 + rand() % (HEIGHT - 2);
}
