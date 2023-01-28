#include <cstdlib>
#include <ctime>

#include "snake.h"
#include "food.h"

#define WIDTH 50
#define HEIGHT 30
#define ESC 27
std::ofstream out;

COORD startingPos = {WIDTH/2, HEIGHT/2};
Snake snake(startingPos, 1);
Food food(out);


void board(){
    COORD snakeHeadPos = snake.getHeadPos();
    COORD foodPos = food.getPos();

    for (int i = 0; i < HEIGHT; i++){
        std::cout << "\t\t\t\t\t\t" << "#";
        for (int j = 0; j < WIDTH - 2; j++){
            if (i == 0 || i == HEIGHT - 1) std::cout << "#";
            else if (i == snakeHeadPos.Y && j == snakeHeadPos.X){
                std::cout << "0";
            }
            else if (snake.isBody(j, i)){
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
    std::cout << "\t\t" << R"(
   _____                         ____                 _ 
  / ____|                       / __ \               | |
 | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __| |
 | | |_ |/ _` | '_ ` _ \ / _ \ | |  | \ \ / / _ \ '__| |
 | |__| | (_| | | | | | |  __/ | |__| |\ V /  __/ |  |_|
  \_____|\__,_|_| |_| |_|\___|  \____/  \_/ \___|_|  (_|
                                                          
                                                          
    )";
    std::cout << "\n\nScore: " << snake.getLen()-1 << "\n\n";
    std::cout << "Press ESC to quit...\n";
}

int main(){
    int isQuit;
    std::srand(std::time(NULL));
    bool gameOver = false;
    CONSOLE_CURSOR_INFO cursor;
    out.open("output.txt");

    cursor.bVisible = FALSE;
    cursor.dwSize = 1;

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

    system("cls");

    while (!gameOver){
        board();
        
        if (snake.isColliding()) gameOver = true;

        if (kbhit()){
            snake.playerInput();
        }

        snake.move();

        if (snake.eaten(food.getPos())){
            food.genFood(out);
            snake.grow();
        }

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }

    gameEnd();

    while (getch() != ESC){
    }

    return 0;
}