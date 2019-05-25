
#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h> // For using _getch();
//#include <targetver>
#include <windows.h>

using namespace std;


#define ESC 27
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SPACE 32

void drawmap(char maze[][10])
{
	for (int row = 0; row<10; row++)
	{
		for (int col = 0; col<10; col++)
		{
			cout << maze[col][row];
		}
		cout << endl;
	}
}

int main()
{
	char maze[10][10] = { 'o' };
	int row, col;
	for (row = 0; row<10; row++)
		for (col = 0; col<10; col++)
			maze[col][row] = 'o';

	maze[5][5] = 'X';
	int health = 15;
	int mana = 15;
	int partylimit = 1;
	string move;
	string character = "*";
	string party;
	string weapon;
	cout << "Welcome to Dungeon Explorers!\n";
	cout << "In Dungeon Explorers, you have a two basic objectives.\n";
	cout << "The first of those objectives is to survive.\n";
	cout << "The second is to escape the dimension you're in.\n";
	cout << "An evil witch sent you to this dimension, so you must escape and kill her.\n";
	Sleep(4000);
	system("CLS");
	cout << "You wake up to see that you are in a valley. You have only a dagger.\n";
	cout << "You soon see a small baby demon not far from you\n";
	cout << "You should attack it.\n";
	Sleep(3000);
	system("CLS");
	cout << "HOW TO PLAY:\n";
	cout << "* Use the arrow keys to move around the world.\n";
	cout << "* Press the space bar to attack.\n";
	cout << "* Press I to open your inventory\n";
	cout << "* Press Esc. to pause the game.\n";
	Sleep(3000);
	system("CLS");
	int x = 5, y = 5;
	drawmap(maze);
	for (;; )
	{
		int ch = 0;
		ch = _getch();
		switch (ch)
		{
		case EOF:
		case ESC:
			cout << "Pause program..." << endl;
			break;
		case SPACE:
			cout << "We attack..  ( we die.....)" << endl;
			break;
		case UP:
			if (y - 1 >= 0)
			{
				system("CLS");
				maze[x][y] = 'o';
				y--;
				maze[x][y] = 'X';
				drawmap(maze);
				cout << "You're moving UP" << endl;
			}
			else
				cout << "Can't move in that direction!!" << endl;
			break;
		case LEFT:
			if (x - 1 >= 0)
			{
				system("CLS");
				maze[x][y] = 'o';
				x--;
				maze[x][y] = 'X';
				drawmap(maze);
				cout << "You're moving LEFT" << endl;
			}
			else
				cout << "Can't move in that direction!!" << endl;
			break;
		case RIGHT:
			if (x + 1<10)
			{
				system("CLS");
				maze[x][y] = 'o';
				x++;
				maze[x][y] = 'X';
				drawmap(maze);
				cout << "You're moving RIGHT" << endl;
			}
			else
				cout << "Can't move in that direction!!" << endl;
			break;
		case DOWN:
			if (y + 1<10)
			{
				system("CLS");
				maze[x][y] = 'o';
				y++;
				maze[x][y] = 'X';
				drawmap(maze);
				cout << "You're moving DOWN" << endl;
			}
			else
				cout << "Can't move in that direction!!" << endl;
			break;
		case  73: // Uppercase I or use case 69: for Uppercase E 
		case 105: // Lowercase i or use case 101: for Lowercase e
			cout << "Open Inventory.." << endl;
			break;
		default:
			if (isprint(ch))
			{
				cout << "Use arrow keys, ESC or I (for Inventory) only" << endl;
			}
		}

	}
	return 0;
}