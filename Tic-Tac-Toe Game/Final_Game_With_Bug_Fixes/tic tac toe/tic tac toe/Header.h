#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//function prototypes
int inputValidate(int, int, int);
void singlePlayer(string[], bool, bool);
void multiPlayer(string[], bool, bool);
void displayMenu();
void gameBoard(string[][3]);
void position(string[][3], int, string, int);
bool checkWinner(string[][3], string);
void comPosition(string[][3], int, string);
void endScreen();

