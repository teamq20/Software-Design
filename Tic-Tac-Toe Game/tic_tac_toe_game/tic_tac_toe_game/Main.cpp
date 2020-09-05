#include "Header.h";
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main() {

<<<<<<< HEAD
	string player[2] = { "X", "O" };			//array that holds player letter

	bool p1Turn;								//Boolean variables used to switch between player turns
	bool p2Turn;								//
	bool gameOver = false;	//determines if the game is over

	const int ROWS = 3, COLS = 3;		// Set the number of rows and columns
	string board[ROWS][COLS] = { "(1)", "(2)", "(3)",			//2 dimensional array to create tic tac toe board
		"(4)", "(5)", "(6)",
		"(7)", "(8)", "(9)" };

=======
>>>>>>> master
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

<<<<<<< HEAD
	//GAME
	if (menuChoice == 1) {									//If player chooses 1, start SINGLE PLAYER game
		cout << "SINGLE PLAYER" << endl;

		gameBoard(board);			//Call gameBoard function to display tic tac toe board

	}
	else if (menuChoice == 2) {								//If player chooses 2, start MULTIPLAYER game
		int p1Choice, p2Choice;
		cout << "MULTIPLAYER" << endl;

		p1Turn = true;				//Set p1turn to true to begin the game

		while (!gameOver) {			//while loop to keep the game in session

			if (p1Turn == true) {		//if/else statement to switch between players during the game

				gameBoard(board);			//Call gameBoard function to display tic tac toe board
				cout << endl;

				cout << "Player " << player[0] << " choose an available spot on the board" << endl;	
				cin >> p1Choice;			//Player 1 inputs desired spot on board

				while (p1Choice < 1 || p1Choice > 9) {		//Input validation (make sure player chooses a spot on the board
					cout << "This is not a valid spot. Please input a number from 1-9.";
					cin >> p1Choice;
				}

				position(board, p1Choice, player[0]);		//Call the position function to place the player on the desired position on the board

				p1Turn = false;
				p2Turn = true;

			}
			else if (p2Turn == true) {

				gameBoard(board);			//Call gameBoard function to display tic tac toe board
				cout << endl;

				cout << "Player " << player[1] << " choose an available spot on the board" << endl;
				cin >> p2Choice;			//Player 1 inputs desired spot on board

				while (p2Choice < 1 || p2Choice > 9) {		//Input validation (make sure player chooses a spot on the board
					cout << "This is not a valid spot. Please input a number from 1-9.";
					cin >> p2Choice;
				}

				position(board, p2Choice, player[1]);		//Call the position function to place the player on the desired position on the board

				p1Turn = true;
				p2Turn = false;

			}
		}

		position(board, p1Choice, player[0]);
=======
	if (menuChoice == 1) {									//If player chooses 1, start single player game
		cout << "SINGLE PLAYER" << endl;

		gameBoard();			//Call gameBoard function to display tic tac toe board

	}
	else if (menuChoice == 2) {								//If player chooses 2, start multiplayer game
		cout << "MULTIPLAYER" << endl;

		gameBoard();			//Call gameBoard function to display tic tac toe board
>>>>>>> master
	}
	else if (menuChoice == 3) {								//If player chooses 3, exit the program
		cout << "QUIT" << endl;
	}

	system("pause");
	return 0;
}