#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//FUNCTION TO DISPLAY THE GAME BOARD
<<<<<<< HEAD
void gameBoard(string board[][3]) {

	const int ROWS = 3, COLS = 3;		// Set the number of rows and columns

		//TIC TAC TOE BOARD
=======
void gameBoard() {

	const int ROWS = 3, COLS = 3;		// Set the number of rows and columns
	string board[ROWS][COLS] = { "(1)", "(2)", "(3)",			//2 dimensional array to create tic tac toe board
		"(4)", "(5)", "(6)",
		"(7)", "(8)", "(9)" };

	//TIC TAC TOE BOARD
>>>>>>> master
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
<<<<<<< HEAD

	
}

void position(string board[][3], int pos, string player) {


	switch (pos) {						//switch statement to determine which tile on the board to fill in depending on pos parameter
	case 1:
		if (board[0][0] == "X" || board[0][0] == "O") {				//if statement to make sure the spot isn't already filled
																	//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[0][0] = "[X]";
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[0][0] = "[O]";
			}
		}
		break;
	case 2:
		if (board[0][1] == "X" || board[0][1] == "O") {				//if statement to make sure the spot isn't already filled
																	//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[0][1] = "[X]";
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[0][1] = "[O]";
			}
		}
		break;
	case 3:
		if (board[0][2] == "X" || board[0][2] == "O") {				//if statement to make sure the spot isn't already filled
																	//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[0][2] = "[X]";
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[0][2] = "[O]";
			}
		}
		break;
	case 4:
		if (board[1][0] == "X" || board[1][0] == "O") {				//if statement to make sure the spot isn't already filled
																	//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[1][0] = "[X]";
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[1][0] = "[O]";
			}
		}
		break;
	case 5:
		if (board[1][1] == "X" || board[1][1] == "O") {				//if statement to make sure the spot isn't already filled
																	//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[1][1] = "[X]";
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[1][1] = "[O]";
			}
		}
		break;
	case 6:
		if (board[1][2] == "X" || board[1][2] == "O") {				//if statement to make sure the spot isn't already filled
																	//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[1][2] = "[X]";
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[1][2] = "[O]";
			}
		}
		break;
	case 7:
		if (board[2][0] == "X" || board[2][0] == "O") {				//if statement to make sure the spot isn't already filled
																	//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[2][0] = "[X]";
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[2][0] = "[O]";
			}
		}
		break;
	case 8:
		if (board[2][1] == "X" || board[2][1] == "O") {				//if statement to make sure the spot isn't already filled
																	//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[2][1] = "[X]";
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[2][1] = "[O]";
			}
		}
		break;
	case 9:
		if (board[2][2] == "X" || board[2][2] == "O") {				//if statement to make sure the spot isn't already filled
																	//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[2][2] = "[X]";
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[2][2] = "[X]";
			}
		}
		break;
	}

}
=======
}
>>>>>>> master
