#include "food.h"
#include "const.h"

Food::Food(){
    this->genFood();
}

COORD Food::getPos(){
    return this->foodPos; 
}

COORD Food::getHalf(){
    return this->halfPos;
}

void Food::genFood(){
    this->foodPos.X = 1 + rand() % (WIDTH - 2);
    this->foodPos.Y = 1 + rand() % (HEIGHT - 2);
}

bool Food::isHalfSpawn(){
    return !(this->halfSpawn) && rand() % 100 == 1;
}

void Food::genHalf(){
    if (isHalfSpawn()){
        this->halfPos.X = 1 + rand() % (WIDTH - 2);
        this->halfPos.Y = 1 + rand() % (HEIGHT - 2);
        this->halfSpawn = true;
        this->halfLifetime = 100;
    }
    else if (this->halfLifetime <= 0) this->popHalf();
    else if (this->halfSpawn){
        this->halfLifetime -= 1;
    }
}

void Food::popHalf(){
    this->halfPos.X = this->halfPos.Y = -1;
    this->halfSpawn = false;
}