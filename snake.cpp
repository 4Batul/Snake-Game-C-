#include <iostream>   
#include <conio.h>  
#include <windows.h>
#include <cstdlib>  

using namespace std;
bool gameOver;          
const int width = 20;   
const int height = 20;  
int x, y;               
int foodX, foodY;       
int score;      
 
       
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; 
eDirection dir;        


void Setup() {
    gameOver = false;       
    dir = STOP;             
    x = width / 2;          
    y = height / 2;         
    foodX = rand() % width; 
    foodY = rand() % height; 
    score = 0;              
	}


void Draw() {
    system("cls"); 

    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    
    for (int i = 0; i < height; i++) {  
        for (int j = 0; j < width; j++) {  // Loop through each column (width)
            if (j == 0) cout << "#"; 

            
            if (i == y && j == x) {
                cout << "O";  
            }
             
            else if (i == foodY && j == foodX) {
                cout << "*";  
            }
            
            else {
                cout << " "; 
            }

            if (j == width - 1) cout << "#"; 
			}
        cout << endl;  
    }

    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << "\nScore: " << score << endl;  
}

void Input() {
    if (_kbhit()) {  
        switch (_getch()) {  
            case 'a': dir = LEFT; break;    
            case 'd': dir = RIGHT; break;   
            case 'w': dir = UP; break;      
            case 's': dir = DOWN; break;    
            case 'x': gameOver = true; break;  
        }
    }
}

void Logic() {
    int prevX = x, prevY = y;
    switch (dir) {  
        case LEFT: x--; break;   
        case RIGHT: x++; break;  
        case UP: y--; break;     
        case DOWN: y++; break;   
    }
   
    if (x >= width || x < 0 || y >= height || y < 0) gameOver = true;

    if (x == foodX && y == foodY) {
        score += 10;               
        foodX = rand() % width;    
        foodY = rand() % height;   
    }
}

int main() {
    Setup(); 
    while (!gameOver) {  
        Draw();   
        Input();  
        Logic();  
        Sleep(100);  
    }
    cout << "Game Over! Final Score: " << score << endl;  
    return 0;
}