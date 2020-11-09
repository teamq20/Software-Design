#include "Game_Classes.h"
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <cctype>
using namespace std;

string version = "1.0.0";

void mainMenu() {
	string menuChoice;

	cout << "\t\t\t\t\t-----------------------------" << endl;
	cout << "\t\t\t\t\t     ESCAPE FROM MINERVA" << endl;
	cout << "\t\t\t\t\t        version " + version << endl;
	cout << "\t\t\t\t\t-----------------------------\n" << endl;
	cout << "\t\t\t\t\t      (1) Single Player" << endl;
	cout << "\t\t\t\t\t      (2) Multiplayer" << endl;
	cout << "\t\t\t\t\t      (0) Quit" << endl;

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

Inventory *P1_Inventory = new Inventory;
Player *P1 = new Player;
Player *P2 = new Player;
void Beginning_stage()
{
	string Starting_Items[8] = { "Pickaxe","Drill","Bucket","Flask","Knife","Gun","Flashlight","Lantern" };



	

	int player_choice = 0;
	cout << "\nWhen selecting the tools needed, the dispensery can only operate to an extent that it can only dispense one item of each category." << endl
		<< "\nFor exploration, the categories are:\n" << "-Excavation\n" << "-Liquid containment\n" << "-Weaponry\n" << "-Illumination\n" << endl
		<< "\nIn the field of Excavation, would you prefer:\n" << "(1) Pickaxe\n" << "or\n" << "(2) Drill" << endl << endl;

	cout << "Please select your tool: ";

	cin >> player_choice;
	inputValidation(player_choice, 2);

	if (player_choice == 1)
	{
		cout << "\nUpon your selection, the dispensery produced a standard issue, P1K-4X Pickaxe. It has a wooden handle attached to a two-headed, steel pick. It looks pretty sharp." << endl << endl;
		P1_Inventory->Add_to_Inventory("Pickaxe");
	}
	else if (player_choice == 2)
	{
		cout << "\nUpon making your selection, the dispensery produced a standard issue, DR111 handheld Drilling device. When inspected, the grip is rubberized and ergonomic." << endl
			<< "The pointed end is sharpened to a point, and when activated, the sounding of the drill bounces around the entire room." << endl << endl;
		P1_Inventory->Add_to_Inventory("Drill");
	}

	cout << "\nIn the field of Liquid containment, would you prefer: \n" << "(1) Bucket\n" << "or\n" << "(2) Flask" << endl << endl;
	cout << "Please select your tool: ";
	cin >> player_choice;
	inputValidation(player_choice, 2);

	if (player_choice == 1)
	{
		cout << "\nUpon your selection, the dispensery produced a standard issue, BUK37T Exploration Bucket. Upon inspection, it looks like a regular metal bucket." << endl << endl;
		P1_Inventory->Add_to_Inventory("Bucket");
	}
	else if (player_choice == 2)
	{
		cout << "\nUpon making your selection, the dispensery produced a standard issue, F14SK Exploration Flask. When inspected, it seems to be a small, round container. There is a lining found inside of the flask." << endl << endl;
		P1_Inventory->Add_to_Inventory("Flask");
	}

	cout << "\nIn the field of Weaponry, would you prefer: \n" << "(1) Knife \n" << "or \n" << "(2) Gun \n" << endl;
	cout << "Please select your weapon: ";
	cin >> player_choice;
	inputValidation(player_choice, 2);

	if (player_choice == 1)
	{
		cout << "\nUpon making your selection, the dispensery produced for you an explorer's Combat Knife. The knife is extremely sharp, with a easy to grip handle. " << endl << endl;
		P1_Inventory->Add_to_Inventory("Knife");
	}
	else if (player_choice == 2)
	{
		cout << "\nUpon making your selection, the dispensery produced for you an explorer's Balistic Handgun. It is a fairly old fashioned firearm; you can assume that it packs a punch." << endl << endl;
		P1_Inventory->Add_to_Inventory("Gun");
	}

	cout << "\nFinally, in the field of Illumination, would you prefer: \n" << "(1) Flashlight\n" << "or\n" << "(2) Lantern\n" << endl;
	cout << "Please select your tool: ";
	cin >> player_choice;
	inputValidation(player_choice, 2);

	if (player_choice == 1)
	{
		cout << "\nWhen selecting your tool, the dispensery produced for you a standard issue explorer's Light Stick. The light is exceptionally bright for a standard issue, but it doesn't really illuminate much." << endl << endl;
		P1_Inventory->Add_to_Inventory("Flashlight");
	}
	else if (player_choice == 2)
	{
		cout << "\nAfter your selection, the dispensery produced for you an explorer's Lantern. Upon activation, the flame in the lantern coats the room in a warm, yet dull light." << endl << endl;
		P1_Inventory->Add_to_Inventory("Lantern");
	}

	cout << "\nAfter your selection of an Illumination tool, the dispensery shuts down. It doesn't seem to be able to be reactivated." << endl << endl;
	P1_Inventory->Print();
}

void Check_Oxygen(int Oxygen) //will check the oxygen lavel of the player after every scenery change, and input they provide.
{
	if (Oxygen <= 20)
	{
		cout << "CAUTION!!! CAUTION!!! CAUTION!!!" << endl << "OXYGEN LEVEL CRITICAL !!!" << endl << endl;
	}
	if (Oxygen <= 0) 
	{
		cout << "\n\n*GAME OVER* VST-7426, your Oxygen Levels have been depleted, and you have perished on Minerva "<< endl;
		cout << "Play again if you wish to redeem yourself..." << endl;
		system("pause");
		mainMenu();
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
		"\n\nFour systems need repair:" <<
		"\n-Reactor Core\n-Navigation System\n-Left Thruster\n-Oxidizer";

	gameRules();
}

void locationIntro(string location, int oxygen) {
	if (location == "Minerva Volcanoes") {
		cout << "\nAs you walk over fields of rock, the clouds dissolve into a black overcast overhead." <<
			"\nAhead, you see the formidable peak, lava flowing down its slopes and smoke pluming from its" <<
			"\nsummit. The heat becomes more intense as you approach. Eventually, you reach the mouth of the" <<
			"\ncave system that leads inside the volcanic mass. The environment is hostile, but luckily," <<
			"\nyour systems detect high quantities of Uranium." << endl << endl;
	}
	else if (location == "Caves") {
		cout << "\nYou don't have to walk long before you see the looming entrance of an expansive cave system," <<
			"\ncarved out of a sheer rock face. The darkness is all-consuming; you won�t be able to navigate" <<
			"\nwithout an illumination device. Standing at the entrance, you can hear distant echoes of creatures" <<
			"\nmoving throughout the vast cave. Your systems detect high quantities of Copper." << endl << endl;
	}
	else if (location == "Liquid Streams") {
		cout << "\nAfter trekking over rolling expanses of rock, you finally come upon a system of streams." <<
			"\nPale blue liquid flows over the rocks and for a brief moment, you feel a sense of peace as you" <<
			"\nrecall sitting by the stream behind your childhood home. Your memories of Earth are soon overtaken," <<
			"\nhowever, as these streams are not water. Life forms weave their way amongst the flowing liquid," <<
			"\nwhich your systems detect is a mixture of various compounds, including Hydrazine. You may utilize" <<
			"\nthe Demeter's liquid filtration system to extract the Hydrazine once the liquid is collected." << endl << endl;
	}
	else if (location == "Clusters of Rocks") {
		cout << "\nTraveling over endless rock, you spot, in the distance, more rock. Except these rocks are large" <<
			"\nand staggered, creating a forest of spires, a biome unlike that which you've ever seen before." <<
			"\nThe closer you get, the more you realize how tremendously large this environment of pure rock is." <<
			"\nGlobular creatures float towards the tops of the spires, while smaller creatures scuttle on the ground." <<
			"\nYour systems detect many minerals embedded in this rock forest, including Fluorine." << endl << endl;
	}

	currentLocation(location, oxygen);
}

void locationSelection(int oxygen) {
	string choice;
	Check_Oxygen(oxygen);
	cout << "[OXYGEN LEVEL: " << oxygen << "]" << endl << endl;
 
	cout << "\nWhat region of Minerva do you want to explore?" << endl;
	cout << "(1) North: Minerva Volcanoes" << endl;
	cout << "(2) East: Caves" << endl;
	cout << "(3) South: Liquid Streams" << endl;
	cout << "(4) West: Clusters of Rocks" << endl;
	cout << "(0) Options menu" << endl << endl;
	
	P1_Inventory->Print();

	cin >> choice;
	int input = convertToInt(choice);
	inputValidation(input, 4);

	if (input == 0) {
		options(1, oxygen, "Select");		//current player mode is 1 here until we figure out multiplayer
	}
	else if (input == 1) {
		oxygen = oxygen - 4;
		locationIntro("Minerva Volcanoes", oxygen);
	}
	else if (input == 2) {
		oxygen = oxygen - 3;
		locationIntro("Caves", oxygen);
	}
	else if (input == 3) {
		oxygen = oxygen - 6;
		locationIntro("Liquid Streams", oxygen);
	}
	else if (input == 4) {
		oxygen = oxygen - 5;
		locationIntro("Clusters of Rocks", oxygen);
	}
}

void currentLocation(string location, int oxygen) {
	cout << "\nLOCATION: " + location << endl;
	Check_Oxygen(oxygen);


	cout << "[OXYGEN LEVEL: " << oxygen << "]" << endl << endl;

	//bool goToShip;

	//do {
		//Exploration/Combat code goes here
	paths(location, oxygen);

		/*string choice;
		cout << "\nWhat is your next move?" << endl;
		cout << "(1) Keep exploring " + location << endl;
		cout << "(2) Go To Ship" << endl;
		cout << "('I') to reveal your inventory" << endl;
		cin >> choice;

		if (choice == "I" || choice == "i")
		{
			P1_Inventory->Print();
			currentLocation(location, oxygen);
		}

		int input = convertToInt(choice);
		inputValidation(input, 2);

		if (input == 0) {
			options(1, oxygen, location);
			//goToShip = false;
		}
		else if (input == 1) {
				//oxygen--;
			paths(location, oxygen);
				//goToShip = false;
		}
		else if (input == 2) {
			oxygen--;
			locationDemeter(oxygen);
			//goToShip = true;
		}*/
	//} while (goToShip == false);

	//locationDemeter(oxygen);
}


void paths(string location, int oxygen) {
	Path pathA, pathB, pathC, pathD;
	//pathA.setPath(3, 0, 7, 40, 60, 70);		//70% chance enemy - 40% small, 20% medium, 10% large
	//pathB.setPath(1, 30, 12, 20, 35, 40);	//40% chance enemy - 20% small, 15% medium, 5% large
	//pathC.setPath(2, 50, 10, 25, 40, 50);	//50% chance enemy - 25% small, 15% medium, 10% large
	//pathD.setPath(2, 100, 15, 35, 50, 60);	//60% chance enemy - 35% small, 15% medium, 10% large

	pathA.setPath(3, 0, 7, 40, 20, 10);		//70% chance enemy - 40% small, 20% medium, 10% large
	pathB.setPath(1, 30, 12, 20, 15, 5);	//40% chance enemy - 20% small, 15% medium, 5% large
	pathC.setPath(2, 50, 10, 25, 15, 10);	//50% chance enemy - 25% small, 15% medium, 10% large
	pathD.setPath(2, 100, 15, 35, 15, 10);	//60% chance enemy - 35% small, 15% medium, 10% large

	string material1 = "Uranium", material2 = "Copper", material3 = "Hydrazine", material4 = "Fluorine";
	string choice;
	int newInput = 1;

	cout << "\nYou are able to go down one of four paths.";

	do
	{
		Check_Oxygen(oxygen);

		cout << "[OXYGEN LEVEL: " << oxygen << "]" << endl << endl;

		cout << "\nWhich path do you choose to take? Please enter a number 1-4:" << endl;
		cin >> choice;

		int input = convertToInt(choice);
		inputValidation(input, 4);
		
		
		if (input == 0) {
			options(1, oxygen, location);
		}
		else if (input == 1) {
			if (location == "Minerva Volcanoes") {
				pathC.goPath(location, oxygen, material1);
			}
			else if (location == "Caves") {
				pathB.goPath(location, oxygen, material2);
			}
			else if (location == "Liquid Streams") {
				pathD.goPath(location, oxygen, material3);
			}
			else if (location == "Clusters of Rocks") {
				pathA.goPath(location, oxygen, material4);
			}
		}
		else if (input == 2) {
			if (location == "Minerva Volcanoes") {
				pathB.goPath(location, oxygen, material1);
			}
			else if (location == "Caves") {
				pathC.goPath(location, oxygen, material2);
			}
			else if (location == "Liquid Streams") {
				pathB.goPath(location, oxygen, material3);
			}
			else if (location == "Clusters of Rocks") {
				pathC.goPath(location, oxygen, material4);
			}
		}
		else if (input == 3) {
			if (location == "Minerva Volcanoes") {
				pathA.goPath(location, oxygen, material1);
			}
			else if (location == "Caves") {
				pathD.goPath(location, oxygen, material2);
			}
			else if (location == "Liquid Streams") {
				pathC.goPath(location, oxygen, material3);
			}
			else if (location == "Clusters of Rocks") {
				pathB.goPath(location, oxygen, material4);
			}
		}
		else if (input == 4) {
			if (location == "Minerva Volcanoes") {
				pathD.goPath(location, oxygen, material1);
			}
			else if (location == "Caves") {
				pathA.goPath(location, oxygen, material2);
			}
			else if (location == "Liquid Streams") {
				pathA.goPath(location, oxygen, material3);
			}
			else if (location == "Clusters of Rocks") {
				pathD.goPath(location, oxygen, material4);
			}
		}
		cout << "\nDo you wish to:" << endl;
		cout << "(1) Continue exploring other paths in this location" << endl;
		cout << "(2) Leave the " << location << " and go back to the ship" << endl;
		cin >> choice;

		newInput = convertToInt(choice);
		inputValidation(newInput, 2);
		if (newInput == 0) {
			options(1, oxygen, location);
		}
	} while (newInput == 1);

	locationDemeter(oxygen);
}

Inventory *Ship_Inventory = new Inventory; //The ship's inventory, so the player can input thier materials.
void locationDemeter(int oxygen) {
	string choice;
	cout << "\nLOCATION: Demeter" << endl << endl;
	cout << "What is your next move?" << endl;
	cout << "(1) Explore Minerva" << endl;
	cout << "(2) Repair Ship" << endl;
	Check_Oxygen(oxygen);

	cout << "[OXYGEN LEVEL: " << oxygen << "]" << endl << endl;

	cin >> choice;

	int input = convertToInt(choice);
	inputValidation(input, 2);

	if (input == 0) {
		options(1, oxygen, "Demeter");
	}
	if (input == 1) {
		locationSelection(oxygen);
	}
	else if (input == 2) {
		oxygen--;
		locationDemeter(oxygen);	//keep this for now so game doesn't break until this is created
		//this is where the personal inventory can empty the material into the ship's inventory

	}
}

void singlePlayer() {
	cout << "\n-----------------------------" << endl;
	cout << "    SINGLE PLAYER MODE" << endl;
	cout << "-----------------------------\n" << endl;

	gameIntro(1);
	static int oxygen = 100;
	bool ship = "";
	cout << "[OXYGEN LEVEL: " << oxygen << "]" << endl << endl;
	system("pause");

	Beginning_stage();

	locationDemeter(oxygen);
}

void multiPlayer() {
	cout << "\n-----------------------------" << endl;
	cout << "      MULTIPLAYER MODE" << endl;
	cout << "-----------------------------\n" << endl;

	gameIntro(2);
	Player *P1 = new Player();
	Player *P2 = new Player();

	Beginning_stage();
}

void options(int playerMode, int oxygen, string optionLocation) {
	string menuChoice;
	DemeterStatus status;
	int width = 20;
	cout << "\nOPTIONS MENU" << endl << endl;
	Check_Oxygen(oxygen);


	cout << "[OXYGEN LEVEL: " << oxygen << "]" << endl << endl;
	cout << left << setw(width) << "Reactor Core" << setw(width) << "Navigation System" << setw(width) << "Left Thruster" << setw(width) << "Oxidizer" << endl;
	cout << left << setw(width) << status.getReactorCore() << setw(width) << status.getNavSystem() << setw(width) << status.getLeftThruster() << setw(width) << status.getOxidizer() << endl;

	cout << endl << "(1) Go to main menu" << endl;
	cout << "(2) Reset Game" << endl;
	cout << "(3) Close Options Menu" << endl;
	cout << "(0) Quit" << endl;
	cin >> menuChoice;

	int input = convertToInt(menuChoice);
	inputValidation(input, 3);

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
	else if (input == 3) {
		if (optionLocation == "Demeter") {
			locationDemeter(oxygen);
		}
		else if (optionLocation == "Select") {
			locationSelection(oxygen);
		}
		else {
			currentLocation(optionLocation, oxygen);
		}
	}
	else if (input == 0) {
		_Exit(10);
	}
}

void gameRules() {

	cout << "\n\nObjective: Repair the ship so you can get off the planet. You will be given two or more options at each stage.\nYour choices impact your survival." << endl;
	cout << "Collect 4 specific items to repair your ship" << endl;
	cout << "Input '0' at any time to open the options menu. Here you will be able to see your inventory, repair status, and oxygen level." << endl;
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
		cout << "Please enter a number between 0 and " << max << endl;

		cin >> menuChoice;
		input = convertToInt(menuChoice);
	}
}





