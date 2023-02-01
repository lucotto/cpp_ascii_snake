#include "food.h"
#include "const.h"

Food::Food(std::ofstream &out){
    Food::genFood(out);
}

COORD Food::getPos(){
    return this->pos; 
}

void Food::genFood(std::ofstream &out){
    this->pos.X = 1 + rand() % (WIDTH - 2);
    this->pos.Y = 1 + rand() % (HEIGHT - 2);
    out << "[" << this->pos.X << "," << this->pos.Y << "]\n";
}
