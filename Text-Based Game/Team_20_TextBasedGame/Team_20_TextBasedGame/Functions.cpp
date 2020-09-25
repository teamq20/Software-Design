#include "Game_Classes.h"
#include <iostream>
#include <string>
using namespace std;

void Inventory::Set_Item_1(string item) {
	Item_1 = item;
}

void Inventory::Set_Item_2(string item) {
	Item_2 = item;
}

void Inventory::Set_Item_3(string item) {
	Item_3 = item;
}

void Inventory::Set_Item_4(string item) {
	Item_4 = item;
}

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
		cout << "exit" << endl;
	}
}

void singlePlayer() {
	cout << "Single Player Mode" << endl;
}

void multiPlayer() {
	cout << "Multiplayer mode" << endl;
}

int convertToInt(string input) {
	int integer = stoi(input);

	return integer;
}

void inputValidation(int input) {
	string menuChoice;

	while (input < 0 || input > 2) {
		cout << "This is an invalid input. Please enter a 0, 1, or 2" << endl;
		cin >> menuChoice;

		input = convertToInt(menuChoice);
	}
}