#include "Game_Classes.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void mainMenu() {
	string menuChoice;

	cout << "ESCAPE FROM MINERVA" << endl;
	cout << "(1) Single Player" << endl;
	cout << "(2) Multiplayer" << endl;
	cout << "(0) Quit" << endl;

	cin >> menuChoice;

	int input = convertToInt(menuChoice);
	inputValidation(input, 2);

	if (input == 1) {
		singlePlayer();
	}
	else if (input == 2) {
		multiPlayer();
	}
	else if (input == 0) {
		cout << "Exit" << endl;
		_Exit(10);
	}
}

void Beginning_stage()
{
	string Starting_Items[8] = { "Pickaxe","Drill","Bucket","Flask","Knife","Gun","Flashlight","Lantern" };

	Player *P1 = new Player;

	Inventory *P1_Inventory = new Inventory;

	int player_choice = 0;
	cout << "While looking through the wreckage of the Demeter, you found out that the exploration dispensery was damaged, but still operational." << endl
		<< "When you selected the tools needed, the dispensery can only operate to an extent that it can only dispense one item of each catagory." << endl
		<< "\nFor exploration, the categories are:\n" << "Excavation\n" << "Liquid containment\n" << "Weaponry\n" << "Illumination\n" << endl
		<< "In the field of Excavation, would you prefer:\n" << "(1) Pickaxe\n" << "or\n" << "(2) Drill" << endl << endl;

	cout << "Please Select your tool: ";

	cin >> player_choice;
	inputValidation(player_choice, 2);

	if (player_choice == 1)
	{
		cout << "Upon your selection, the dispensery produced a standard issue, P1K-4X Pickaxe. it has a wooden handle attaged to a two-headed, steel pick. it looks pretty sharp" << endl << endl;
		P1_Inventory->Add_to_Inventory("Pickaxe");
	}
	else if (player_choice == 2)
	{
		cout << "Upon making your selection, the dispensery produced a standard issue, DR111 handheld Drilling device. when inspected, the grip is rubberized and ergonomic." << endl
			<< "The pointed end is sharpened to a point. And when activated the sounding of the drill bounces around the entire room." << endl << endl;
		P1_Inventory->Add_to_Inventory("Drill");
	}

	cout << "In the field of Liquid containment, would you perfer: \n" << "(1) Bucket\n" << "or\n" << "(2) Flask" << endl << endl;
	cout << "Please select your tool: ";
	cin >> player_choice;
	inputValidation(player_choice, 2);

	if (player_choice == 1)
	{
		cout << "Upon your selection, the dispensery produced a standard issue, BUK37T Exploration Bucket. Upon inspection, it looks like a regular metal bucket" << endl << endl;
		P1_Inventory->Add_to_Inventory("Bucket");
	}
	else if (player_choice == 2)
	{
		cout << "Upon making your selection, the dispensery produced a standard issue, F14SK Exploration Flask. When inspected, it seems to bee a small, round container. There is a lining found inside of the flask" << endl;
		P1_Inventory->Add_to_Inventory("Flask");
	}

	cout << "In the field of Weaponry, would you perfer: \n" << "(1) Knife \n" << "or \n" << "(2) Gun \n" << endl << endl;
	cin >> player_choice;
	inputValidation(player_choice, 2);

	if (player_choice == 1)
	{
		cout << "Upon making your selection, the dispensery produced for you an explorer's combat knife. The knife is extremely sharp, with a easy to grip handle. " << endl << endl;
		P1_Inventory->Add_to_Inventory("Knife");
	}
	else if (player_choice == 2)
	{
		cout << "Upon making your selection, the dispensery produced for you an explorer's balistic handgun. It is a fairly old fashion firearm, you can assume that it packs a punch." << endl << endl;
		P1_Inventory->Add_to_Inventory("Gun");
	}

	cout << "Finally in the field of Illumination, would you perfer: \n" << "(1) Flashlight\n" << "or\n" << "(2) Lantern\n" << endl << endl;
	cin >> player_choice;
	inputValidation(player_choice, 2);

	if (player_choice == 1)
	{
		cout << "When selecting your tool, the dispensery produced for you a standard issue explorer's light stick. The light is exeptionally bright for a standard issue, but it doesnt really illuminate much." << endl << endl;
		P1_Inventory->Add_to_Inventory("Flashlight");
	}
	else if (player_choice == 2)
	{
		cout << "After your selection, the dispensery produced for you a explorers lantern. Upon activation the flame in the lantern coats the room in a warm, yet dull light" << endl << endl;
		P1_Inventory->Add_to_Inventory("Lantern");
	}

	cout << "After your selection of an Illumination tool, the dispensery shuts down. it doesn't seem to be able to be reactivated. as of right now your invintory includes: " << endl;
	P1_Inventory->Print();
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

void locationSelection() {
	string choice;
	cout << "What region of Minerva do you want to explore?" << endl;
	cout << "(1) North: Minerva Volcanos" << endl;
	cout << "(2) East: Caves" << endl;
	cout << "(3) South: Liquid Streams" << endl;
	cout << "(4) West: Clusters of Rocks" << endl;
	cin >> choice;

	int input = convertToInt(choice);
	inputValidation(input, 4);

	if (input == 1) {
		cout << "LOCATION: Minerva Volcanos" << endl;
	}
	else if (input == 2) {
		cout << "LOCATION: Caves" << endl;
	}
	else if (input == 3) {
		cout << "LOCATION: Liquid Streams" << endl;
	}
	else if (input == 4) {
		cout << "LOCATION: Clusters of Rocks" << endl;
	}
}

void singlePlayer() {
	cout << "SINGLE PLAYER MODE" << endl;

	gameIntro(1);
	static int health = 30;
	bool ship = "";
	

	Beginning_stage();

	do {
		string choice;
		cout << "LOCATION: Demeter" << endl << endl;
		cout << "What is your next move?" << endl;
		cout << "(1) Explore Minerva" << endl;
		cout << "(2) Repair Ship" << endl;
		cin >> choice;

		int input = convertToInt(choice);
		inputValidation(input, 2);

		if (input == 0) {
			options(1, health);
		}
		if (input == 1) {
			health--;
			locationSelection();
		}
		else if (input == 2) {
			health--;

		}
	} while (ship == true);
}

void multiPlayer() {
	cout << "MULTIPLAYER MODE" << endl;

	gameIntro(2);
	Player *P1 = new Player();
	Player *P2 = new Player();

	Beginning_stage();
}

void options(int playerMode, int health) {
	string menuChoice;

	cout << "HEALTH: " << health;

	cout << "OPTIONS MENU" << endl;
	cout << "(1) Go to main menu" << endl;
	cout << "(2) Reset Game" << endl;
	cout << "(0) Quit" << endl;
	cin >> menuChoice;

	int input = convertToInt(menuChoice);
	inputValidation(input, 2);

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
	cout << "Input '0' at any time to open the options menu. Here you will be able to see your inventory, repair status, and health." << endl;
}

int convertToInt(string input) {
	int stringCounter = 1;

	while (stringCounter != 0) {
		stringCounter = 0;
		for (int i = 0; i < input.length(); i++) {
			if (isalpha(input[i])) {
				stringCounter++;
			}
		}

		if (stringCounter != 0) {
			cout << "This is not an valid input. Enter a numeric input." << endl;
			cin >> input;
		}
	}

	int choice = stoi(input);
	return choice;
}

void inputValidation(int input, int max) {
	while (input < 0 || input > max) {
		string menuChoice;

		cout << "This is an invalid input" << endl;
		cout << "Please enter either 0, 1, or 2" << endl;

		cin >> menuChoice;
		input = convertToInt(menuChoice);
	}
}



