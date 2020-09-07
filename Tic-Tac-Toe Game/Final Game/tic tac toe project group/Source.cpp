#include "Header.h";
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main() {

	string player[2] = { "X", "O" };			//array that holds player letter

	bool p1Turn;								//Boolean variables used to switch between player turns
	bool p2Turn;								//
	bool comTurn;
	bool gameOver = false;	//determines if the game is over

	const int ROWS = 3, COLS = 3;		// Set the number of rows and columns
	string board[ROWS][COLS] = { "(1)", "(2)", "(3)",			//2 dimensional array to create tic tac toe board
		"(4)", "(5)", "(6)",
		"(7)", "(8)", "(9)" };

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
	while (menuChoice < 1 || menuChoice > 3 || cin.fail()) {			//while loop to make sure the player inputs a valid digit
		if (cin.fail()) {		//If the input is not a number, clear the error
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "This is an invalid input!" << endl;
		cout << "Enter 1 to play single player, 2 for multiplayer, or 3 to quit the program" << endl;
		cin >> menuChoice;
	}

	cout << endl;

	//GAME
	if (menuChoice == 1) {									//If player chooses 1, start SINGLE PLAYER game
		cout << "SINGLE PLAYER" << endl;

		int counter = 9;		//counter to keep track of how many spaces left (9 at the beginning)

		int p1Choice, comChoice;			//variables to hold the player's choice and the computer's choice

		p1Turn = true;				//Set p1turn to true to begin the game

		do {
			if (p1Turn == true) {
				gameBoard(board);			//Call gameBoard function to display tic tac toe board
				cout << endl;

				cout << "Player " << player[0] << " choose an available spot on the board" << endl;
				cin >> p1Choice;			//Player 1 inputs desired spot on board

				while (p1Choice < 1 || p1Choice > 9) {		//Input validation (make sure player chooses a spot on the board
					cout << "This is not a valid spot. Please input a number from 1-9.";
					cin >> p1Choice;
				}

				position(board, p1Choice, player[0], counter);		//Call the position function to place the player on the desired position on the board

				gameOver = checkWinner(board, player[0]);	//Call the checkWinner function to see if there is a winner

				if (counter == 0) {
					gameOver = true;
					cout << "It is a tie" << endl;
				}

				if (!gameOver) {							//Check if the game is not over. If it is not, then the game continues
					p1Turn = false;
					comTurn = true;
				}
			}
			else if (comTurn == true && counter != 0) {
				cout << endl;

				comChoice = rand() % 9 + 1;			//computer chooses what number it desires

				comPosition(board, comChoice, player[1]);		//call the comPosition function to place the computer on the desired position

				gameOver = checkWinner(board, player[1]);	//Call the checkWinner function to see if there is a winner

				if (!gameOver) {
					p1Turn = true;
					comTurn = false;
				}
			}
		} while (gameOver == false);

		cout << endl << endl;
		int c;		//int to hold player's choice

		cout << "Enter 1 to go to the main menu or 2 to quit the program" << endl;
		cin >> c;

		//INPUT VALIDATION
		while (c < 1 || c > 2 || cin.fail()) {
			if (cin.fail()) {	//if input is not a number, clear the error
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "This is an invalid input!" << endl;
			cout << "Enter 1 to go to the main menu or 2 to quit the program" << endl;
			cin >> c;

		}

		if (c == 1) {
			displayMenu();	//display the menu if the player input is 1
		}
		else {
			exit(0);		//close the program if player input is 2
		}

	}
	else if (menuChoice == 2) {								//If player chooses 2, start MULTIPLAYER game
		int p1Choice, p2Choice;

		cout << "MULTIPLAYER" << endl;
		int counter = 9;		//counter to keep track of how many spaces left (9 at the beginning)

		p1Turn = true;				//Set p1turn to true to begin the game

		do {			//while loop to keep the game in session

			if (p1Turn == true) {		//if/else statement to switch between players during the game

				gameBoard(board);			//Call gameBoard function to display tic tac toe board
				cout << endl;

				cout << "Player " << player[0] << " choose an available spot on the board" << endl;
				cin >> p1Choice;			//Player 1 inputs desired spot on board

				while (p1Choice < 1 || p1Choice > 9) {		//Input validation (make sure player chooses a spot on the board
					cout << "This is not a valid spot. Please input a number from 1-9.";
					cin >> p1Choice;
				}

				position(board, p1Choice, player[0], counter);		//Call the position function to place the player on the desired position on the board

				gameOver = checkWinner(board, player[0]);	//Call the checkWinner function to see if there is a winner

				if (counter == 0) {
					gameOver = true;
					cout << "It is a tie" << endl;
				}

				if (!gameOver) {							//Check if the game is not over. If it is not, then the game continues
					p1Turn = false;
					p2Turn = true;
				}

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

				position(board, p2Choice, player[1], counter);		//Call the position function to place the player on the desired position on the board

				gameOver = checkWinner(board, player[1]);			//Call the checkWinner function to see if there is a winner

				if (counter == 0) {
					gameOver = true;
					cout << "It is a tie" << endl;
				}

				if (!gameOver) {
					p1Turn = true;
					p2Turn = false;
				}

			}
		} while (gameOver == false);

		cout << endl << endl;
		int c;		//int to hold player's choice

		cout << "Enter 1 to go to the main menu or 2 to quit the program" << endl;
		cin >> c;

		//INPUT VALIDATION
		while (c < 1 || c > 2 || cin.fail()) {
			if (cin.fail()) {	//if input is not a number, clear the error
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "This is an invalid input!" << endl;
			cout << "Enter 1 to go to the main menu or 2 to quit the program" << endl;
			cin >> c;

		}

		if (c == 1) {
			displayMenu();	//display the menu if the player input is 1
		}
		else {
			exit(0);		//close the program if player input is 2
		}
	}
	else if (menuChoice == 3) {								//If player chooses 3, exit the program
		exit(0);
	}

	system("pause");
	return 0;
}}