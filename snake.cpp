#include "snake.h"

#define WIDTH 50
#define HEIGHT 30

Snake::Snake(COORD pos, int vel){
    this->pos = {pos};
    this->vel = vel;
    this->len = 1;
    this->dir = 'r';
}

void Snake::playerInput(){
    halfdelay(1);
    int ch = getch();

    if (ch != ERR){
        switch(ch){
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
            default:
                break;
        }
    }
}

void Snake::turn(char dir){
    this->dir = dir;
}

void Snake::move(){
    std::vector<COORD> oldPos = this->pos;

    switch(this->dir){
        case 'u': this->pos.front().Y -= vel; break;
        case 'r': this->pos.front().X += vel; break; 
        case 'd': this->pos.front().Y += vel; break;
        case 'l': this->pos.front().X -= vel; break;
    }

    if (this->len > 1){
        int i = 0;
        for (auto it = this->pos.begin()+1; it != this->pos.end(); it++){
            *it = oldPos[i++];
        }
    }
}

std::vector<COORD> Snake::getCoords(){
    return this->pos;
}

COORD Snake::getHeadPos(){
    return this->pos.front();
}

int Snake::getLen(){
    return this->len;
}

bool Snake::eaten(COORD foodPos){
    if (foodPos.X == this->pos.front().X && foodPos.Y == this->pos.front().Y) return true;
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

bool Snake::isBody(const int &i, const int &j){
    for (auto it = this->pos.begin()+1; it != this->pos.end(); it++){
        if (it->X == i && it->Y == j) return true;
    }
    return false;
}

bool Snake::isColliding(){
    if (this->pos.front().X == 0 ||
        this->pos.front().X == (WIDTH - 1) ||
        this->pos.front().Y == 0 ||
        this->pos.front().Y == (HEIGHT - 1)){
        return true;
    }

    if (this->isBody(this->pos.front().X, this->pos.front().Y)){
        return true;
    }

    return false;
};
