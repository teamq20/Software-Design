#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//FUNCTION TO DISPLAY THE GAME BOARD
void gameBoard() {

	const int ROWS = 3, COLS = 3;		// Set the number of rows and columns
	string board[ROWS][COLS] = { "(1)", "(2)", "(3)",			//2 dimensional array to create tic tac toe board
		"(4)", "(5)", "(6)",
		"(7)", "(8)", "(9)" };

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