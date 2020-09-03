#include "Header.h";
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main() {

	int menuChoice;						//int to hold the player's input choice in the main menu

										//MAIN MENU
	cout << "MAIN MENU" << endl;
	cout << "Tic Tac Toe" << endl;
	cout << "Rules:" << endl;
	cout << "-Player 1 is X and Player 2 is O" << endl;
	cout << "-The game will prompt which player's turn it is. The player will choose an available number from the board" << endl;
	cout << "-The game ends when a player gets three in a row or when the board is completely filled" << endl;
	cout << "-The player who gets three in a row wins" << endl << endl;

	cout << "1 - Single Player" << endl;		//These are the player's options
	cout << "2 - Multiplayer" << endl;			//
	cout << "3 - Quit" << endl << endl;			//

	cout << "(Enter 1 to play single player, 2 for multiplayer, or 3 to quit the program)" << endl;
	cin >> menuChoice;

	//Input Validation
	while (menuChoice < 1 || menuChoice > 3) {			//while loop to make sure the player inputs a valid digit
		cout << "This is an invalid input!" << endl;
		cout << "Enter 1 to play single player, 2 for multiplayer, or 3 to quit the program" << endl;
		cin >> menuChoice;
	}

	cout << endl;

	if (menuChoice == 1) {									//If player chooses 1, start single player game
		cout << "SINGLE PLAYER" << endl;

		gameBoard();			//Call gameBoard function to display tic tac toe board

	}
	else if (menuChoice == 2) {								//If player chooses 2, start multiplayer game
		cout << "MULTIPLAYER" << endl;

		gameBoard();			//Call gameBoard function to display tic tac toe board
	}
	else if (menuChoice == 3) {								//If player chooses 3, exit the program
		cout << "QUIT" << endl;
	}

	system("pause");
	return 0;
}