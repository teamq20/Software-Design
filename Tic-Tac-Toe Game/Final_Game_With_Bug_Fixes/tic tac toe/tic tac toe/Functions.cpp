#include "Header.h";
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//Input Validation
int inputValidate(int input, int min, int max) {
	while (input < min || input > max || cin.fail()) {
		if (cin.fail()) {		//If the input is not a number, clear the error
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "This is an invalid input!" << endl;
		cin >> input;
	}

	return input;
}

//FUNCTION TO DISPLAY THE GAME BOARD
void gameBoard(string board[][3]) {

	const int ROWS = 3, COLS = 3;		// Set the number of rows and columns

										//TIC TAC TOE BOARD
	for (int r = 0; r < ROWS; r++) {							//For loop to create the rows of the board (3 rows)

		for (int c = 0; c < COLS; c++) {						//For loop to create the columns for each row (3 columns per row)
			cout << setw(3) << " " << board[r][c] << " ";		//Out put the numbers from the board array onto the location specified

			if (c != 2) {
				cout << "|";									//Divide the columns with a "|"
			}
		}

		if (r != 2) {
			cout << endl << setw(3) << "_________________________" << endl;			//Divide the rows with an underscore
		}
	}


}

void displayMenu() {		//display the main menu
	string player[2] = { "[X]", "[O]" };			//array that holds player letter
	bool p1Turn = true;								//Boolean variables used to switch between player turns
	bool p2Turn = false;								//

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
	cout << "0 - Quit" << endl << endl;			//

	cout << "(Enter 1 to play single player, 2 for multiplayer, or 0 to quit the program)" << endl;
	cin >> menuChoice;

	//Input Validation
	menuChoice = inputValidate(menuChoice, 0, 2);

	if (menuChoice == 1) {

		singlePlayer(player, p1Turn, p2Turn);
	}
	else if (menuChoice == 2) {

		multiPlayer(player, p1Turn, p2Turn);
	}
	else if (menuChoice == 0) {
		exit(0);		//if player input is 0, close the program
	}

	cout << endl;
}

void singlePlayer(string player[], bool p1Turn, bool comTurn) {		//begin single player mode
	cout << "SINGLE PLAYER" << endl;

	bool gameOver = false;	//determines if the game is over

	int counter = 9;		//counter to keep track of how many spaces left (9 at the beginning)

	int p1Choice, comChoice;			//variables to hold the player's choice and the computer's choice

	const int ROWS = 3, COLS = 3;		// Set the number of rows and columns
	string board[ROWS][COLS] = { " 1 ", " 2 ", " 3 ",			//2 dimensional array to create tic tac toe board
		" 4 ", " 5 ", " 6 ",
		" 7 ", " 8 ", " 9 " };

	p1Turn = true;				//Set p1turn to true to begin the game

	do {
		if (p1Turn == true) {
			gameBoard(board);			//Call gameBoard function to display tic tac toe board
			cout << endl;

			cout << "Player " << player[0] << " choose an available spot on the board" << endl;
			cin >> p1Choice;			//Player 1 inputs desired spot on board

			p1Choice = inputValidate(p1Choice, 1, (ROWS * COLS));

			position(board, p1Choice, player[0], player, counter);		//Call the position function to place the player on the desired position on the board

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

			comPosition(board, comChoice, player[1], player);		//call the comPosition function to place the computer on the desired position

			gameOver = checkWinner(board, player[1]);	//Call the checkWinner function to see if there is a winner

			if (!gameOver) {
				p1Turn = true;
				comTurn = false;
			}
		}
	} while (gameOver == false);

	cout << endl << endl;
	endScreen();
}

void multiPlayer(string player[], bool p1Turn, bool p2Turn) {		//begin multiplayer mode
	int p1Choice, p2Choice;								//

	bool gameOver = false;	//determines if the game is over

	cout << "MULTIPLAYER" << endl;
	int counter = 9;		//counter to keep track of how many spaces left (9 at the beginning)

	const int ROWS = 3, COLS = 3;		// Set the number of rows and columns
	string board[ROWS][COLS] = { " 1 ", " 2 ", " 3 ",			//2 dimensional array to create tic tac toe board
		" 4 ", " 5 ", " 6 ",
		" 7 ", " 8 ", " 9 " };

	p1Turn = true;				//Set p1turn to true to begin the game

	do {			//while loop to keep the game in session

		if (p1Turn == true) {		//if/else statement to switch between players during the game

			gameBoard(board);			//Call gameBoard function to display tic tac toe board
			cout << endl;

			cout << "Player " << player[0] << " choose an available spot on the board" << endl;
			cin >> p1Choice;			//Player 1 inputs desired spot on board

			p1Choice = inputValidate(p1Choice, 0, (ROWS * COLS));

			position(board, p1Choice, player[0], player, counter);		//Call the position function to place the player on the desired position on the board

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

			p1Choice = inputValidate(p1Choice, 0, (ROWS * COLS));

			position(board, p2Choice, player[1], player, counter);		//Call the position function to place the player on the desired position on the board

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

	endScreen();
}

void position(string board[][3], int pos, string player, string playerArray[], int counter) {
	string player1 = playerArray[0];
	string player2 = playerArray[1];

	switch (pos) {						//switch statement to determine which tile on the board to fill in depending on pos parameter
	case 1:
		if (board[0][0] == player1 || board[0][0] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, playerArray, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == player1) {			//If player X chose the spot, fill in 'X'
				board[0][0] = player1;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == player2) {		//If player O chose the spot, fill in 'O'
				board[0][0] = player2;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	case 2:
		if (board[0][1] == player1 || board[0][1] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, playerArray, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == player1) {			//If player X chose the spot, fill in 'X'
				board[0][1] = player1;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == player2) {		//If player O chose the spot, fill in 'O'
				board[0][1] = player2;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	case 3:
		if (board[0][2] == player1 || board[0][2] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, playerArray, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == player1) {			//If player X chose the spot, fill in 'X'
				board[0][2] = player1;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == player2) {		//If player O chose the spot, fill in 'O'
				board[0][2] = player2;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	case 4:
		if (board[1][0] == player1 || board[1][0] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, playerArray, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == player1) {			//If player X chose the spot, fill in 'X'
				board[1][0] = player1;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == player2) {		//If player O chose the spot, fill in 'O'
				board[1][0] = player2;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	case 5:
		if (board[1][1] == player1 || board[1][1] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, playerArray, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == player1) {			//If player X chose the spot, fill in 'X'
				board[1][1] = player1;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == player2) {		//If player O chose the spot, fill in 'O'
				board[1][1] = player2;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	case 6:
		if (board[1][2] == player1 || board[1][2] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, playerArray, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == player1) {			//If player X chose the spot, fill in 'X'
				board[1][2] = player1;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == player2) {		//If player O chose the spot, fill in 'O'
				board[1][2] = player2;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	case 7:
		if (board[2][0] == player1 || board[2][0] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, playerArray, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == player1) {			//If player X chose the spot, fill in 'X'
				board[2][0] = player1;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == player2) {		//If player O chose the spot, fill in 'O'
				board[2][0] = player2;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	case 8:
		if (board[2][1] == player1 || board[2][1] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, playerArray, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == player1) {			//If player X chose the spot, fill in 'X'
				board[2][1] = player1;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == player2) {		//If player O chose the spot, fill in 'O'
				board[2][1] = player2;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	case 9:
		if (board[2][2] == player1 || board[2][2] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, playerArray, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == player1) {			//If player X chose the spot, fill in 'X'
				board[2][2] = player1;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == player2) {		//If player O chose the spot, fill in 'O'
				board[2][2] = player2;
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	default:
		pos = inputValidate(pos, 0, sizeof(board));
	}

}

void comPosition(string board[][3], int pos, string player, string playerArray[]) {
	string player1 = playerArray[0];
	string player2 = playerArray[1];

	switch (pos) {						//switch statement to determine which tile on the board to fill in depending on pos parameter
	case 1:
		if (board[0][0] == player1 || board[0][0] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player, playerArray);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[0][0] = player2;
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	case 2:
		if (board[0][1] == player1 || board[0][1] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player, playerArray);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[0][1] = player2;
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	case 3:
		if (board[0][2] == player1 || board[0][2] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player, playerArray);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[0][2] = player2;
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	case 4:
		if (board[1][0] == player1 || board[1][0] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player, playerArray);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[1][0] = player2;
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	case 5:
		if (board[1][1] == player1 || board[1][1] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player, playerArray);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[1][1] = player2;
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	case 6:
		if (board[1][2] == player1 || board[1][2] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player, playerArray);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[1][2] = player2;
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	case 7:
		if (board[2][0] == player1 || board[2][0] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player, playerArray);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[2][0] = player2;
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	case 8:
		if (board[2][1] == player1 || board[2][1] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player, playerArray);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[2][1] = player2;
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	case 9:
		if (board[2][2] == player1 || board[2][2] == player2) {				//if statement to make sure the spot isn't already filled
																			//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player, playerArray);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[2][2] = player2;
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	}
}

bool checkWinner(string board[][3], string player) {


	if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {		//if/else statements to check if the winning combinations are met by current player
		cout << "Player " << player << " has won!" << endl;
		gameBoard(board);
		return true;					//return true and assign to gameOver variable
	}
	else if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
		cout << "Player " << player << " has won!" << endl;
		gameBoard(board);
		return true;
	}
	else if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
		cout << "Player " << player << " has won!" << endl;
		gameBoard(board);
		return true;
	}
	else if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
		cout << "Player " << player << " has won!" << endl;
		gameBoard(board);
		return true;
	}
	else if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
		cout << "Player " << player << " has won!" << endl;
		gameBoard(board);
		return true;
	}
	else if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
		cout << "Player " << player << " has won!" << endl;
		gameBoard(board);
		return true;
	}
	else if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
		cout << "Player " << player << " has won!" << endl;
		gameBoard(board);
		return true;
	}
	else if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
		cout << "Player " << player << " has won!" << endl;
		gameBoard(board);
		return true;
	}
	else {		//If there is no winner, switch players (next player's turn)
		return false;		//return false and assign to gameOver variable

	}
}

void endScreen() {
	int choice;

	cout << "Enter 1 to go to the main menu or 0 to quit the program" << endl;
	cin >> choice;

	//INPUT VALIDATION
	inputValidate(choice, 0, 1);

	if (choice == 1) {
		displayMenu();	//display the menu if the player input is 1
	}
	else {
		exit(0);		//close the program if player input is 2
	}
}