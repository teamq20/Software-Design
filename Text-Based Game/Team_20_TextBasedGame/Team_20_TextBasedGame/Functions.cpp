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

void gameIntro(int playerMode) {
	if (playerMode == 1) {
		cout << "Greetings VST - 7426. You are one of two brave astronauts, the core members of Operation" <<
			"\nVesta, that have voyaged to examine the distant planet of Minerva, which shows great promise" <<
			"\nas a potential new home for the inhabitants of Earth.Unfortunately, due to a miscalculation in" <<
			"\nthe navigation system of the Demeter(your ship), you have crash landed in an inhospitable" <<
			"\nregion of Minerva, roughly 400 kilometers south of your initial destination.After running a" <<
			"\nsystems check, you have found that there are four crucial systems on the Demeter that have" <<
			"\nbeen damaged by the crash.Your crewmate, VST - 7427, has also suffered fatal injuries, leaving" <<
			"\nyou completely alone.Given the current circumstances of your predicament, you have" <<
			"\napproximately 3 days to fix these systems before running out of oxygen.Luckily, however, this" <<
			"\nregion of Minerva contains valuable minerals that may aid your fixing of these parts. Choose" <<
			"\nyour path wisely, VST - 7426, and good luck" << endl << endl;
	}
	else {
		cout << "Greetings VST-7426 and VST-7427. You are the two core members of Operation Vesta that" <<
			"\nhave voyaged to examine the distant planet of Minerva, which shows great promise as a" <<
			"\npotential new home for the inhabitants of Earth.Unfortunately, due to a miscalculation in the" <<
			"\nnavigation system of the Demeter(your ship), you have crash landed in an inhospitable region" <<
			"\nof Minerva, roughly 400 kilometers south of your initial destination.After running a systems" <<
			"\ncheck, you have found that there are four crucial systems on the Demeter that have been" <<
			"\ndamaged by the crash.Given the current circumstances of your predicament, you have" <<
			"\napproximately 3 days to fix these systems before running out of oxygen.Luckily, however, this" <<
			"\nregion of Minerva contains valuable minerals that may aid your fixing of these parts. Choose" <<
			"\nyour path wisely, and good luck." << endl << endl;
	}

	cout << "While looking through the wreckage of the Demeter, you found out that the exploration dispensery was damaged, but still operational." <<
		"\nFour systems need repair:" <<
		"\n-Reactor Core\n-Navigation System\n-Left Thruster\n-Oxidizer";

	gameRules();
}

void singlePlayer() {
	cout << "SINGLE PLAYER MODE" << endl;

	gameIntro(1);

}

void multiPlayer() {
	cout << "MULTIPLAYER MODE" << endl;

	gameIntro(2);

}

void options(int playerMode) {
	string menuChoice;

	cout << "OPTIONS MENU" << endl;
	cout << "(1) Go to main menu" << endl;
	cout << "(2) Reset Game" << endl;
	cout << "(0) Quit" << endl;
	cin >> menuChoice;

	int input = convertToInt(menuChoice);
	inputValidation(input);

	if (input == 1) {
		mainMenu();
	}
	else if (input == 2) {
		if (playerMode == 1) {
			singlePlayer();
		}
		else if (playerMode == 2) {
			multiPlayer();
		}
	}
	else if (input == 0) {

	}
}

void gameRules() {

	cout << "Objective: Repair the ship so you can get off the planet. You will be given two or more options at each stage./nYour choices impact your survival." << endl;
	cout << "Collect 4 specific items to repair your ship" << endl;
	cout << "Input '1' at any time to open your inventory or '2' to open your ship's inventory" << endl;
	cout << "Input '3' at any time to see the Demeter's repair status" << endl;
	cout << "Input '4' at any time to open the HUD" << endl;
	cout << "Input '0' at any time to open the options menu." << endl;
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