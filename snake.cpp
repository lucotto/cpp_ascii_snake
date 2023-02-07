#include "snake.h"
#include "print.h"
#include "const.h"

Snake::Snake(COORD pos, int vel){
    this->pos = {pos};
    this->vel = vel;
    this->len = 1;
    this->dir = right;
}

void Snake::playerInput(){
    halfdelay(1);
    int ch = getch();
    Print print;

    if (ch != ERR){
        switch(ch){
            case 'w':
            case KEY_UP:{
                if(this->dir != 'd') Snake::turn(up);
                break;
            }
            case 's':
            case KEY_DOWN:{
                if(this->dir != 'u') Snake::turn(down);
                break;
            }
            case 'd':
            case KEY_RIGHT:{
                if(this->dir != 'l') Snake::turn(right);
                break;
            }
            case 'a':
            case KEY_LEFT:{
                if(this->dir != 'r') Snake::turn(left);
                break;
            }
            case 'p':
            case 27:
                print.pause();
                break;
            case 'q':{
                endwin();
                exit(0);
                break;
            }

            default:
                break;
        }
    }
}

void Snake::turn(Direction d){
    if (this->dir + d != 0){
        this->dir = d;
    }
}

void Snake::move(){
    std::vector<COORD> oldPos = this->pos;

    switch(this->dir){
        case up: this->pos.front().Y -= vel; break;
        case right: this->pos.front().X += vel; break; 
        case down: this->pos.front().Y += vel; break;
        case left: this->pos.front().X -= vel; break;
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

bool Snake::isColliding(std::vector<COORD> obs){
    if (this->pos.front().X == 0 ||
        this->pos.front().X == (WIDTH - 1) ||
        this->pos.front().Y == 0 ||
        this->pos.front().Y == (HEIGHT - 1)){
        return true;
    }

    if (this->isBody(this->pos.front().X, this->pos.front().Y)){
        return true;
    }

    for (auto it = obs.begin(); it != obs.end(); it++){
        if (this->pos.front().X == it->X && this->pos.front().Y == it->Y) return true;
    }   

    return false;
};
