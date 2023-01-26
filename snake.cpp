#include "snake.h"

Snake::Snake(COORD pos, int vel){
    this->pos = pos;
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
        case 'u': pos.Y -= vel; break;
        case 'r': pos.X += vel; break; 
        case 'd': pos.Y += vel; break;
        case 'l': pos.X -= vel; break;
    }
}

COORD Snake::getPos(){
    return this->pos;
}

int Snake::getLen(){
    return this->len;
}

bool Snake::eaten(COORD foodPos){
    if (foodPos.X == pos.X && foodPos.Y == pos.Y) return true;
    else return false;
}

void Snake::grow(){
    this->len++;
}