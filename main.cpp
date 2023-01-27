#include <cstdlib>
#include <ctime>

#include "snake.h"
#include "food.h"

#define WIDTH 50
#define HEIGHT 30

COORD startingPos = {WIDTH/2, HEIGHT/2};
Snake snake(startingPos, 1);
Food food;

void board(){
    COORD snakeHeadPos = snake.getHeadPos();
    COORD foodPos = food.getPos();

    for (int i = 0; i < HEIGHT; i++){
        std::cout << "\t\t\t\t\t\t#";
        for (int j = 0; j < WIDTH - 2; j++){
            if (i == 0 || i == HEIGHT - 1) std::cout << "#";
            else if (i == snakeHeadPos.Y && j == snakeHeadPos.X){
                std::cout << "0";
            }
            else if (snake.isBody(i, j)){
                std::cout << "o";
            }
            else if (i == foodPos.Y && j == foodPos.X) std::cout << "F";
            else std::cout << ".";
        }
        std::cout << "#\n";
    }
}

void gameEnd(){
    system("cls");
    std::cout << R"(
   _____                         ____                 _ _ 
  / ____|                       / __ \               | | |
 | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __| | |
 | | |_ |/ _` | '_ ` _ \ / _ \ | |  | \ \ / / _ \ '__| | |
 | |__| | (_| | | | | | |  __/ | |__| |\ V /  __/ |  |_|_|
  \_____|\__,_|_| |_| |_|\___|  \____/  \_/ \___|_|  (_|_)
                                                          
                                                          
    )";
}

int main(){
    std::srand(std::time(NULL));
    bool gameOver = false;

    while (!gameOver){
        board();
        
        if (snake.isColliding()) gameOver = true;

        if (kbhit()){
            snake.playerInput();
        }

        snake.move();

        if (snake.eaten(food.getPos())){
            food.genFood();
            snake.grow();
        }

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }

    gameEnd();

    return 0;
}