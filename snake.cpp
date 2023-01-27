#include "snake.h"

#define WIDTH 50
#define HEIGHT 30

Snake::Snake(COORD pos, int vel){
    this->pos = {pos};
    this->vel = vel;
    this->len = 1;
    this->dir = 'n';
}

void Snake::playerInput(){
    switch(getch()){
        case 'w':{
            if(this->dir != 'd') Snake::turn('u');
            break;
        }
        case 's':{
            if(this->dir != 'u') Snake::turn('d');
            break;
        }
        case 'd':{
            if(this->dir != 'l') Snake::turn('r');
            break;
        }
        case 'a':{
            if(this->dir != 'r') Snake::turn('l');
            break;
        }
    }
}

void Snake::turn(char dir){
    this->dir = dir;
}

void Snake::move(){
    switch(this->dir){
        case 'u': this->pos[0].Y -= vel; break;
        case 'r': this->pos[0].X += vel; break; 
        case 'd': this->pos[0].Y += vel; break;
        case 'l': this->pos[0].X -= vel; break;
    }
}

std::vector<COORD> Snake::getCoords(){
    return this->pos;
}

COORD Snake::getHeadPos(){
    return this->pos[0];
}

int Snake::getLen(){
    return this->len;
}

bool Snake::eaten(COORD foodPos){
    if (foodPos.X == this->pos[0].X && foodPos.Y == this->pos[0].Y) return true;
    else return false;
}

void Snake::grow(){
    short x = 0, y = 0;
    switch(this->dir){
        case 'u': y++; break;
        case 'r': x--; break;
        case 'd': y--; break;
        case 'l': x++; break;
    }
    COORD newBody = {x, y};

    this->len++;
    this->pos.push_back({newBody});
}

bool Snake::isColliding(){
    if (this->pos[0].X == 0 ||
        this->pos[0].X == (WIDTH - 1) ||
        this->pos[0].Y == 0 ||
        this->pos[0].Y == (HEIGHT - 1))
        return true;
    else return false;
};

bool Snake::isBody(const int &i, const int &j){
    for (auto it = this->pos.begin(); it != this->pos.end(); it++){
        if (it->X == i && it->Y == j) return true;
        else return false;
    }
}