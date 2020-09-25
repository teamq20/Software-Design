#include "Game_Classes.h"
#include <iostream>
#include <string>
using namespace std;

void mainMenu() {
	string menuChoice;

	cout << "ESCAPE FROM MINERVA" << endl;
	cout << "(1) Single Player" << endl;
	cout << "(2) Multiplayer" << endl;
	cout << "(0) Quit" << endl;

	cin >> menuChoice;

	int input = convertToInt(menuChoice);
	inputValidation(input);

	if (input == 1) {
		singlePlayer();
	}
	else if (input == 2) {
		multiPlayer();
	}
	else if (input == 0) {
		cout << "Exit" << endl;
	}
}

void singlePlayer() {
	cout << "SINGLE PLAYER MODE" << endl;

	Story story;

	string intro = story.getIntro(1);
}

void multiPlayer() {
	cout << "MULTIPLAYER MODE" << endl;

	Story story;

	string intro = story.getIntro(1);
}

int convertToInt(string input) {
	int choice = stoi(input);
	return choice;
}

void inputValidation(int input) {
	while (input < 0 || input > 2) {
		string menuChoice;

		cout << "This is an invalid input" << endl;
		cout << "Please enter either 0, 1, or 2" << endl;

		cin >> menuChoice;
		input = convertToInt(menuChoice);
	}
}