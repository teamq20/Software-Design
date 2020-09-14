#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//A structure that assigns (x,y) positions	
//on the game board to a numbered position	
//from 1 to 9								
static struct boardPositions {
	int pos;
	int boardX;
	int boardY;
};

//function prototypes
int inputValidate(int, int, int);
void singlePlayer(string[], bool, bool, boardPositions position[]);
void multiPlayer(string[], bool, bool, boardPositions position[]);
void displayMenu(boardPositions position[]);
void gameBoard(string[][3]);
void fillPosition(string[][3], int, string, boardPositions position[]);
bool positionAvailable(boardPositions position[], int, string[], string[][3]);
bool checkWinner(string[][3], string);
void endScreen(boardPositions position[]);

