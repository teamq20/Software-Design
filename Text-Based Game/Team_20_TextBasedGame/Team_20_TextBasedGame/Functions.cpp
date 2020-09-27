#include "Game_Classes.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

<<<<<<< Updated upstream
void mainMenu() {
	string menuChoice;
=======
void mainMenu() 
{
	int menuChoice;
>>>>>>> Stashed changes

	cout << "ESCAPE FROM MINERVA" << endl;
	cout << "(1) Single Player" << endl;
	cout << "(2) Multiplayer" << endl;
	cout << "(0) Quit" << endl;

	cin >> menuChoice;

	int input = convertToInt(menuChoice);
	inputValidation(input);

<<<<<<< Updated upstream
	if (input == 1) {
		singlePlayer();
	}
	else if (input == 2) {
		multiPlayer();
	}
	else if (input == 0) {
=======
	if (menuChoice == 1) 
	{
		singlePlayer();
	}
	else if (menuChoice == 2) 
	{
		multiPlayer();
	}
	else if (menuChoice == 0)
	{
>>>>>>> Stashed changes
		cout << "Exit" << endl;
		_Exit(10);
	}
}

void singlePlayer() {
	cout << "SINGLE PLAYER MODE" << endl;

	Story *story = new Story();
	story->setIntro();

<<<<<<< Updated upstream
	string intro = story.getIntro(1);
=======
	string intro = story->getIntro(1);
	cout << intro << endl <<endl <<endl;
>>>>>>> Stashed changes
}

void multiPlayer() {
	cout << "MULTIPLAYER MODE" << endl;

	Story *story2 = new Story();
	story2->setIntro();

<<<<<<< Updated upstream
	string intro = story.getIntro(1);
=======
	string intro = story2->getIntro(2);
	cout << intro << endl <<endl <<endl;
>>>>>>> Stashed changes
}

int convertToInt(string input) {
	int choice = stoi(input);
	return choice;
}

<<<<<<< Updated upstream
void inputValidation(int input) {
	while (input < 0 || input > 2) {
=======
void inputValidation(int input) 
{
	while (input < 0 || input > 2) 
	{
>>>>>>> Stashed changes
		string menuChoice;

		cout << "This is an invalid input" << endl;
		cout << "Please enter either 0, 1, or 2" << endl;

		cin >> menuChoice;
		input = convertToInt(menuChoice);
	}
}

