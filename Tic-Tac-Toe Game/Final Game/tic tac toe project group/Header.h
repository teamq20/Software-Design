#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

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

void position(string board[][3], int pos, string player, int counter) {


	switch (pos) {						//switch statement to determine which tile on the board to fill in depending on pos parameter
	case 1:
		if (board[0][0] == "[X]" || board[0][0] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[0][0] = "[X]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[0][0] = "[O]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	case 2:
		if (board[0][1] == "[X]" || board[0][1] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[0][1] = "[X]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[0][1] = "[O]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	case 3:
		if (board[0][2] == "[X]" || board[0][2] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[0][2] = "[X]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[0][2] = "[O]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	case 4:
		if (board[1][0] == "[X]" || board[1][0] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[1][0] = "[X]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[1][0] = "[O]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	case 5:
		if (board[1][1] == "[X]" || board[1][1] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[1][1] = "[X]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[1][1] = "[O]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	case 6:
		if (board[1][2] == "[X]" || board[1][2] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[1][2] = "[X]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[1][2] = "[O]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	case 7:
		if (board[2][0] == "[X]" || board[2][0] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[2][0] = "[X]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[2][0] = "[O]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	case 8:
		if (board[2][1] == "[X]" || board[2][1] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[2][1] = "[X]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[2][1] = "[O]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	case 9:
		if (board[2][2] == "[X]" || board[2][2] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			cout << "This spot is already filled. Please choose an available spot" << endl;
			cin >> pos;

			position(board, pos, player, counter);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			if (player == "X") {			//If player X chose the spot, fill in 'X'
				board[2][2] = "[X]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
			else if (player == "O") {		//If player O chose the spot, fill in 'O'
				board[2][2] = "[O]";
				counter--;					//subtract one from counter because a place on the board has been filled
			}
		}
		break;
	}

}

void comPosition(string board[][3], int pos, string player) {
	switch (pos) {						//switch statement to determine which tile on the board to fill in depending on pos parameter
	case 1:
		if (board[0][0] == "[X]" || board[0][0] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[0][0] = "[O]";
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	case 2:
		if (board[0][1] == "[X]" || board[0][1] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[0][1] = "[O]";
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	case 3:
		if (board[0][2] == "[X]" || board[0][2] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[0][2] = "[O]";
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	case 4:
		if (board[1][0] == "[X]" || board[1][0] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[1][0] = "[O]";
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	case 5:
		if (board[1][1] == "[X]" || board[1][1] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[1][1] = "[O]";
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	case 6:
		if (board[1][2] == "[X]" || board[1][2] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[1][2] = "[O]";
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	case 7:
		if (board[2][0] == "[X]" || board[2][0] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[2][0] = "[O]";
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	case 8:
		if (board[2][1] == "[X]" || board[2][1] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[2][1] = "[O]";
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	case 9:
		if (board[2][2] == "[X]" || board[2][2] == "[O]") {				//if statement to make sure the spot isn't already filled
																		//Spot is filled
			pos = rand() % 9 + 1;	//Make computer choose a new number

			comPosition(board, pos, player);		//Call the position function again with the new choice
		}
		else {
			//Spot is available
			board[2][2] = "[O]";
			cout << "The computer chose spot " << pos << endl;
		}
		break;
	}
}

bool checkWinner(string board[][3], string player) {

	string p = "[" + player + "]";		//variable used so that the if statements can recognize the filled positions

	if (board[0][0] == p && board[0][1] == p && board[0][2] == p) {		//if/else statements to check if the winning combinations are met by current player
		cout << "Player " << player << " has won!" << endl;
		return true;					//return true and assign to gameOver variable
	}
	else if (board[0][0] == p && board[1][0] == p && board[2][0] == p) {
		cout << "Player " << player << " has won!" << endl;
		return true;
	}
	else if (board[0][0] == p && board[1][1] == p && board[2][2] == p) {
		cout << "Player " << player << " has won!" << endl;
		return true;
	}
	else if (board[0][1] == p && board[1][1] == p && board[2][1] == p) {
		cout << "Player " << player << " has won!" << endl;
		return true;
	}
	else if (board[0][2] == p && board[1][1] == p && board[2][0] == p) {
		cout << "Player " << player << " has won!" << endl;
		return true;
	}
	else if (board[0][2] == p && board[1][2] == p && board[2][2] == p) {
		cout << "Player " << player << " has won!" << endl;
		return true;
	}
	else if (board[1][0] == p && board[1][1] == p && board[1][2] == p) {
		cout << "Player " << player << " has won!" << endl;
		return true;
	}
	else if (board[2][0] == p && board[2][1] == p && board[2][2] == p) {
		cout << "Player " << player << " has won!" << endl;
		return true;
	}
	else {		//If there is no winner, switch players (next player's turn)
		return false;		//return false and assign to gameOver variable

	}
}