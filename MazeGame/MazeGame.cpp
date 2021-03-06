// MazeGame.cpp : Defines the entry point for the console application.
//224 = UP  

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <windows.h>
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define W 119
#define D 100
#define S 115
#define A 97
using namespace std;


class mazeBoard {
	//function that prints the board
	//function that randomizes the board
	//variables for the lines and blocks
	//function that checks the maze and make it possible to win
	//constructor 
	
	char topleft = 218;
	char topright = 191;
	char bottomleft = 192;
	char bottomright = 217;
	char horizontalline = 196;
	char block = 178;
	char space = 32;
	char verticalline = 179;
	char s = 83;
	char e = 69;
	int startX;
	int startY;
	int playerX = 0;
	int playerY = 0;
	
	
    public:
		bool hasSolved = false;
		char player;
		

	int boardArr[50][50] = {

	
	{ 218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191},
    { 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 179,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,179 },
	{ 192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217}
	
	};
	bool visitedArr[50][50];
	
	
	mazeBoard() {


	};

	void boardfiller() {

		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				visitedArr[i][j] = false;
			}
		}
	}

	void printBoard() {
		system("CLS");
		for (int i = 0; i < 50; i++) {
			
			for (int j = 0; j < 50; j++) {
				if (boardArr[i][j] == 218) {
					cout << topleft;
				}
				else if (boardArr[i][j] == 191) {
					cout << topright;
				}
				else if (boardArr[i][j] == 192) {
					cout << bottomleft;
				}
				else if (boardArr[i][j] == 217) {
					cout << bottomright;
				}
				else if (boardArr[i][j] == 196) {
					cout << horizontalline;
				}
				else if (boardArr[i][j] == 178) {
					cout << block;
				}
				else if (boardArr[i][j] == 32) {
					cout << space;
				}
				else if (boardArr[i][j] == 83) {
					cout << s;
				}
				else if (boardArr[i][j] == 69) {
					cout << e;
				}
				else if (boardArr[i][j] == 179) {
					cout << verticalline;
				}
				else if (boardArr[i][j] == player) {
					cout << player;
				}
			}
			cout << '\n';
		}
	
    }
	

	void randomizer() {

		srand(time(NULL));
		

		
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				visitedArr[i][j] = false;
				if (boardArr[i][j] == 32 || boardArr[i][j] == 178 || boardArr[i][j] == player) {
					int randnum = rand() % 10 + 1;
					if (randnum > 6) {
						boardArr[i][j] = 178;
					}
					else if (randnum <= 6) {
						boardArr[i][j] = 32;
					}
				}
				else if (boardArr[i][j] == 83 || boardArr[i][j] == 69) {
					boardArr[i][j] = 196;
					
				}
			}
		}
		int randS = rand() % 48 + 1;
		boardArr[49][randS] = s;
		//boardArr[1][randS] = x;
		playerX = 48;
		playerY = randS;
		startX = 48;
		startY = randS;
		boardArr[48][randS] = player;
		int randE = rand() % 48 + 1;
		boardArr[0][randE] = e;
		boardArr[1][randE] = space;
	}
	void PlayerReset() {
		boardArr[playerX][playerY] = 32;
		boardArr[startX][startY] = player;
		playerX = startX;
		playerY = startY;
	}
	bool possible() {
		return recursiveSolve(playerX, playerY);
	}
	bool recursiveSolve(int x, int y) {
		if (boardArr[x][y] == e) {
			return true;
	     }

		visitedArr[x][y] = true;
		//boardArr[x][y] = player;
		//check left
		if ((boardArr[x][y - 1] == 32 || boardArr[x][y - 1] == e) && visitedArr[x][y-1] == false) {
			if (recursiveSolve(x, y - 1)) {
				return true;
			}
		 }
		 
		//check up
		if ((boardArr[x - 1][y] == 32 || boardArr[x - 1][y] == e) && visitedArr[x-1][y] == false) {
			if (recursiveSolve(x - 1, y)) {
				return true;
			}
		}
		//check right
		if ((boardArr[x][y + 1] == 32 || boardArr[x][y + 1] == e) && visitedArr[x][y + 1] == false) {
			if (recursiveSolve(x, y + 1)) {
				return true;
			}
		}
		//check down
		if ((boardArr[x+1][y] == 32 || boardArr[x + 1][y] == e) && visitedArr[x+1][y] == false) {
			if (recursiveSolve(x + 1, y)) {
				return true;
			}
		}

		return false;
	}
	
	void checkMove(int direction) {
		if (direction == UP || direction == W) {
			
			if (boardArr[playerX - 1][playerY] == 32) {
				//remove old x
				boardArr[playerX][playerY] = 32;
				playerX = playerX - 1;
				//add new x
				boardArr[playerX][playerY] = player;
				printBoard();
			}
			else if (boardArr[playerX - 1][playerY] == e) {
				hasSolved = true;
				cout << "You Solved The Maze!";
				}
		}
		else if (direction == LEFT || direction == A) {
			
			if (boardArr[playerX][playerY - 1] == 32) {
				//remove old y
				boardArr[playerX][playerY] = 32;
				playerY = playerY - 1;
				//add new y
				boardArr[playerX][playerY] = player;
				printBoard();
			}
		}
		else if (direction == RIGHT || direction == D) {
			
			if (boardArr[playerX][playerY + 1] == 32) {

				//remove old y
				boardArr[playerX][playerY] = 32;
				playerY = playerY + 1;
				//add new y
				boardArr[playerX][playerY] = player;
				printBoard();
			}
		}
				else if (direction == DOWN || direction == S) {
					
					if (boardArr[playerX + 1][playerY] == 32) {
						//remove old x
						boardArr[playerX][playerY] = 32;
						playerX = playerX + 1;
						//add new x
						boardArr[playerX][playerY] = player;
						printBoard();
					}
					
				}
			
		
	}
	

};






class Player {

	
	//int x = 0, y = 0;
	int playerNum;
public:

	Player(int playerID) {
		playerNum = playerID;

	}
	Player() {
		playerNum = 1;
	}
	void move(mazeBoard * board) {
		int input = 0;
		input = _getch();
	  if(playerNum == 2){ 
		  switch (input)
		  {
		  case 224:
			  break;
		  case UP:
			  board->checkMove(UP);

			  break;
		  case DOWN:

			  board->checkMove(DOWN);
			  break;

		  case RIGHT:

			  board->checkMove(RIGHT);
			  break;



		  case LEFT:

			  board->checkMove(LEFT);
			  break;

		  default: {
			  cout << input;
			  cout << "Use only arrow keys!";
		  }
		  }
				 



		}
	   if (playerNum == 1) {
		   switch (input) {
		   case W:
			   board->checkMove(W);

			   break;
		   case S:
			   board->checkMove(S);

			   break;
		   case D:
			   board->checkMove(D);
			   break;
		   case A:
			   board->checkMove(A);

			   break;
		   default: {
			 
		   }
		   }
	   }
	}
		/*void move(int moveX, int moveY) {
			if (GetAsyncKeyState(VK_UP)) {
				move(x - 1, y);
				cout << "Up";
				
			}
			if (GetAsyncKeyState(VK_DOWN)) {
				
				move(x + 1, y);
				cout << "Down";
				
			}
			if (GetAsyncKeyState(VK_LEFT)) {
				move(x, y - 1);
				cout << "Left";
				
			}
			if (GetAsyncKeyState(VK_RIGHT)) {
				move(x, y + 1);
				cout << "Right";
				
			}
			

		}
	
	*/
};


 void timer() {
	int sec = 0;
	int min = 0;
	int hour = 0;
	bool timer = true;
	while (timer) {

		Sleep(1000);
		sec = sec + 1;
		if (sec == 60) {
			min = min + 1;
			sec = 0;
		}
		if (min == 60) {
			hour = hour + 1;
			min = 0;

		}
		//system("CLS");
		//cout << hour << " Hours " << min << " minutes " << "and " << sec << " seconds. " << endl;
	

	}
}



int main()
{
	int c;
	string PlayerSet;
	string mode;
	mazeBoard board;
	
	bool multiplayer;
	cout << "Do you want to play multiplayer or a solo? type multiplayer if you want multiplayer or type solo for solo: ";
	cin >> mode;

	if (mode == "multiplayer") {
		multiplayer = true;
		
		
	}
	else if (mode == "solo") {
		multiplayer = false;
		
	
	}
	else {
		multiplayer = false;
		
		
	}
	cout << "What symbol do you want as your player? if it is a dollar sign, type dollar, if it is a hashtag, type hash,\nif it is an X, type x: ";
	cin >> PlayerSet;
	if (PlayerSet == "dollar") {
		board.player = 36;
		cout << "Generating Random Maze...";
	}
	else if (PlayerSet == "hash") {
		board.player = 35;
		cout << "Generating Random Maze...";
	}
	else if (PlayerSet == "x") {
		board.player = 88;
		cout << "Generating Random Maze...";
	}
	else {
		board.player = 48;
		cout << "Generating Random Maze...";
	}

	int sec2 = 0;
	int min = 0;
	int hour = 0;
	bool timer = true;
	string exit = "yes";
	
	Player player;
	

		board.randomizer();
		while (board.possible() == false) {

			board.randomizer();
			
			//board.printBoard();
			
		}
		
		board.boardfiller();
		board.printBoard();
		
		int sec = 0;
		

		
		cout << "                                                " << "S = Start  " << " E = End  " << " X = Player";
		while (board.hasSolved == false) {
		
				player.move(&board);
				if (sec == 0) {
					sec = time(0);
				}
		}
		int newsec = time(0);
		
		if (board.hasSolved == true) {
		
			if (multiplayer == true) {
				cout << "\nIt took you " << newsec - sec << " seconds to solve the maze " << "Now it is player2's turn! ";
				board.hasSolved = false;
				
				system("pause");
				board.PlayerReset();
				board.printBoard();
				int player2sec = 0;
				while (board.hasSolved == false) {
					player.move(&board);
					if (player2sec == 0) {
						player2sec = time(0);
					}
				}
				int player2newsec = time(0);
				cout << "\nit took you " << player2newsec - player2sec << " seconds to solve the maze! ";
				if (newsec - sec > player2newsec - player2sec) {
					cout << "\nPlayer 1 solved the maze in " << newsec - sec << " seconds and Player 2 solved the maze in " << player2newsec - player2sec << " seconds \nPlayer 2 is the winner!!!";
					cout << "    \nDo you want to play again? if you do, type yes, if you don't then type no: ";

					cin >> exit;
					if (exit == "yes") {
						main();

					}
					else if (exit == "no") {
						return 0;
					}
				}
				else if(player2newsec - player2sec == newsec - sec){
					cout << "\nPlayer 1 solved the maze in " << newsec - sec << " seconds and Player 2 solved the maze in " << player2newsec - player2sec << " seconds \nDRAW!";
					cout << "    \nDo you want to play again? if you do, type yes, if you don't then type no: ";

					cin >> exit;
					if (exit == "yes") {
						main();

					}
					else if (exit == "no") {
						return 0;
					}
				}
				else {
					cout << "\nPlayer 1 solved the maze in " << newsec - sec << " seconds and Player 2 solved the maze in " << player2newsec - player2sec << " seconds \nPlayer 1 is the winner!!!";
					cout << "    \nDo you want to play again? if you do, type yes, if you don't then type no: ";

					cin >> exit;
					if (exit == "yes") {
						main();

					}
					else if (exit == "no") {
						return 0;
					}
				}
			}
			if (multiplayer == false) {
				//timer = false;
				cout << "\nIt took you " << newsec - sec << " seconds to solve the maze \n";
				if (newsec - sec <= 20) {
					cout << "You Got A GOLD MEDAL! ";
				}
				else if (newsec - sec <= 30 && newsec - sec > 20) {
					cout << "You Got A SILVER MEDAL! ";
				}
				else if (newsec - sec < 45 && newsec - sec > 30) {
					cout << "You Got A BRONZE MEDAL! ";
				}
				else {
				
					cout << "You Are Going To Become A Loser! ";
						
				}
		
				cout << "    \nDo you want to play again? if you do, type yes, if you don't then type no: ";
		
				cin >> exit;
				if (exit == "yes") {
					main();

				}
				else if (exit == "no") {
					return 0;
				}
			}
		}


		//player.move(0, 0);

		/*char topleft = 218;
		char topright = 191;
		char bottomleft = 192;
		char bottomright = 217;
		char horizontalline = 196;
		char block = 178;
		cout << topleft <<horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline <<  horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << topright << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';

		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';


		cout << bottomleft<< horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << bottomright;

		*/

		cin >> c;


	}



