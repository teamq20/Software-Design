#include "Game_Classes.h"
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <Windows.h>

using namespace std;

string version = "1.2.0";

Inventory* P1_Inventory;				//Player 1 personal inventory
Player* P1;								//Player 1 object
//Player *P2;							//Player 2 object
Ship_inventory* The_Ship;				//The ship's inventory, so the player can input their materials.
Minerva north, south, east, west;		//Minerva locations
DemeterStatus* shipStatus;				//Status of parts of ship (damaged/repaired)
bool continueGame;						//Changes to true as a way to resume game
static int oxygen;						//Oxygen level variable

void setGame() {
	/* Set all values to start of gameplay */
	
	//set Minerva locations & materials
	north.setSetting("Minerva Volcanoes");
	north.setItem("Uranium");
	south.setSetting("Liquid Streams");
	south.setItem("Hydrazine");
	east.setSetting("Caves");
	east.setItem("Copper");
	west.setSetting("Clusters of Rocks");
	west.setItem("Fluorine");

	//set oxygen level
	oxygen = 100;

	//set Player 1 personal inventory to empty
	P1_Inventory = new Inventory;

	//set Player 1 new object
	P1 = new Player;

	/*set Player 2 new object
	P2 = new Player;	*/

	//set Ship Inventory to empty/false
	The_Ship = new Ship_inventory(false, false, false, false);

	//set Ship status all to damaged
	shipStatus = new DemeterStatus;
	shipStatus->setDemeterStatus();

	//set game continuer to false
	bool continueGame = false;
}

void mainMenu(int oxygen) {
	/* start of game */
	
	string menuChoice;

	cout << "\t\t\t\t\t-----------------------------" << endl;
	cout << "\t\t\t\t\t     ESCAPE FROM MINERVA" << endl;
	cout << "\t\t\t\t\t        version " + version << endl;
	cout << "\t\t\t\t\t-----------------------------\n" << endl;
	cout << "\t\t\t\t\t      (1) Start New Game" << endl;					//Changed from "Single Player"
	//cout << "\t\t\t\t\t      (2) Multiplayer" << endl;
	if(continueGame == true) {
		cout << "\t\t\t\t\t      (2) Continue Game" << endl;
	}
	cout << "\t\t\t\t\t      (0) Quit" << endl;

	cin >> menuChoice;
	cin.ignore();

	int input = convertToInt(menuChoice);		//input validation
	if (continueGame == true) {
		input = inputValidation(input, 0, 2);
	}
	else {
		input = inputValidation(input, 0, 1);
	}

	if (input == 1) {
		setGame();			//set the starting values of game
		singlePlayer();		//go to single player version
	}
	else if (input == 2 && continueGame == true) {
		locationDemeter(oxygen);
	}
	/*else if (input == 2) {
		multiPlayer();		//go to multiplayer version
	}*/
	else if (input == 0) {
		cout << "Exit" << endl;		//end game
		system("pause");
		_Exit(10);
	}
}

void Beginning_stage()
{
	/* tool selection */

	string Starting_Items[8] = { "Pickaxe","Drill","Bucket","Flask","Knife","Gun","Flashlight","Lantern" };

	int player_choice;	//player input when converted to int
	string choice;		//player input
	cout << "\nWhen selecting the tools needed, the dispensery can only operate to an extent that it can only dispense one item of each category." << endl
		<< "\nFor exploration, the categories are:\n" << "-Excavation\n" << "-Liquid containment\n" << "-Weaponry\n" << "-Illumination\n" << endl;
	Sleep(1500);
	cout << "\nIn the field of Excavation, would you prefer:\n" << "(1) Pickaxe\n" << "or\n" << "(2) Drill" << endl << endl;

	cout << "Please select your tool: ";

	cin >> choice;
	player_choice = convertToInt(choice);
	player_choice = inputValidation(player_choice, 1, 2);

	if (player_choice == 1)		//select pickaxe
	{
		cout << "\n>> Upon your selection, the dispensery produced a standard issue, P1K-4X Pickaxe. It has a wooden handle attached to a two-headed, steel pick. It looks pretty sharp." << endl << endl;
		P1_Inventory->Add_to_Inventory("Pickaxe");
	}
	else if (player_choice == 2)		//select drill
	{
		cout << "\n>> Upon making your selection, the dispensery produced a standard issue, DR111 handheld Drilling device. When inspected, the grip is rubberized and ergonomic." << endl
			<< "The pointed end is sharpened to a point, and when activated, the sounding of the drill bounces around the entire room." << endl << endl;
		P1_Inventory->Add_to_Inventory("Drill");
	}

	Sleep(1500);
	cout << "\nIn the field of Liquid containment, would you prefer: \n" << "(1) Bucket\n" << "or\n" << "(2) Flask" << endl << endl;
	cout << "Please select your tool: ";
	cin >> choice;
	player_choice = convertToInt(choice);
	player_choice = inputValidation(player_choice, 1, 2);

	if (player_choice == 1)		//select bucket
	{
		cout << "\n>> Upon your selection, the dispensery produced a standard issue, BUK37T Exploration Bucket. Upon inspection, it looks like a regular metal bucket." << endl << endl;
		P1_Inventory->Add_to_Inventory("Bucket");
	}
	else if (player_choice == 2)		//select flask
	{
		cout << "\n>> Upon making your selection, the dispensery produced a standard issue, F14SK Exploration Flask. When inspected, it seems to be a small, round container. There is a lining found inside of the flask." << endl << endl;
		P1_Inventory->Add_to_Inventory("Flask");
	}

	Sleep(1500);
	cout << "\nIn the field of Weaponry, would you prefer: \n" << "(1) Knife (Deals 3 damage)\n" << "or \n" << "(2) Gun (Deals 5 damage)\n" << endl;
	cout << "Please select your weapon: ";
	cin >> choice;
	player_choice = convertToInt(choice);
	player_choice = inputValidation(player_choice, 1, 2);

	if (player_choice == 1)		//select knife
	{
		cout << "\n>> Upon making your selection, the dispensery produced for you an explorer's Combat Knife. The knife is extremely sharp, with a easy to grip handle. " << endl << endl;
		P1_Inventory->Add_to_Inventory("Knife");
	}
	else if (player_choice == 2)		//select gun
	{
		cout << "\n>> Upon making your selection, the dispensery produced for you an explorer's Balistic Handgun. It is a fairly old fashioned firearm; you can assume that it packs a punch." << endl << endl;
		P1_Inventory->Add_to_Inventory("Gun");
	}
	
	Sleep(1500);
	cout << "\nFinally, in the field of Illumination, would you prefer: \n" << "(1) Flashlight\n" << "or\n" << "(2) Lantern\n" << endl;
	cout << "Please select your tool: ";
	cin >> choice;
	player_choice = convertToInt(choice);
	player_choice = inputValidation(player_choice, 1, 2);

	if (player_choice == 1)		//select flashlight
	{
		cout << "\n>> When selecting your tool, the dispensery produced for you a standard issue explorer's Light Stick. The light is exceptionally bright for a standard issue, but it doesn't really illuminate much." << endl << endl;
		P1_Inventory->Add_to_Inventory("Flashlight");
	}
	else if (player_choice == 2)		//select lantern
	{
		cout << "\n>> When selecting your tool, the dispensery produced for you an explorer's Lantern. Upon activation, the flame in the lantern coats the room in a warm, yet dull light." << endl << endl;
		P1_Inventory->Add_to_Inventory("Lantern");
	}

	Sleep(1500);
	cout << "\nAfter your selection of an Illumination tool, the dispensery shuts down. It doesn't seem to be able to be reactivated." << endl << endl;
	P1_Inventory->Print();			//print current inventory
}

void Check_Oxygen(int Oxygen) 	//checks the oxygen level of the player after every scenery change, and input they provide.
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
		continueGame = false;
		mainMenu();
	}
}

void gameIntro(int playerMode) {
	/* display intros for single player or multiplayer mode */
	
	if (playerMode == 1) {		//single player intro
		cout << "Greetings VST - 7426. ";
		Sleep(1000);
		cout << "You are one of two brave astronauts, the core members of Operation\nVesta, that have voyaged to examine the distant planet of Minerva,";
		Sleep(1000);
		cout << " which shows great promise\nas a potential new home for the inhabitants of Earth. ";
		Sleep(1000);
		cout << "Unfortunately, due to a miscalculation in\nthe navigation system of the Demeter (your ship),";
		Sleep(1000);
		cout << " you have crash landed in an inhospitable\nregion of Minerva, roughly 400 kilometers south of your initial destination.";
		Sleep(1000);
		cout << " After running a\nsystems check, you have found that there are four crucial systems on the Demeter that have\nbeen damaged by the crash.";
		Sleep(1000);
		cout << " Your crewmate, VST - 7427, has also suffered fatal injuries, leaving\nyou completely alone.";
		Sleep(1000);
		cout << " Given the current circumstances of your predicament, you have\napproximately 3 days to fix these systems before running out of oxygen.";
		Sleep(1000);
		cout << " Luckily, however, this\nregion of Minerva contains valuable minerals that may aid your fixing of these parts.";
		Sleep(1000);
		cout << "\nChoose your path wisely, VST - 7426, and good luck." << endl << endl;
		system("pause");
	}
	/*else {			//multiplayer intro
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
	}*/

	cout << "\nWhile looking through the wreckage of the Demeter, you found out that the exploration dispensery was damaged, but still operational.";
	Sleep(1000);
	cout << "\n\nFour systems need repairing:" <<
		"\n-Reactor Core\n-Navigation System\n-Left Thruster\n-Oxidizer";
	Sleep(1500);

	gameRules();
}

void locationIntro(string location, int oxygen) {
	/* display intros for the 4 different locations */
	
	if (location == "Minerva Volcanoes") {
		cout << "\nAs you walk over fields of rock, the clouds dissolve into a black overcast overhead." <<
			"\nAhead, you see the formidable peak, lava flowing down its slopes and smoke pluming from its" <<
			"\nsummit. The heat becomes more intense as you approach. Eventually, you reach the mouth of the" <<
			"\ncave system that leads inside the volcanic mass. The environment is hostile, but luckily," <<
			"\nyour systems detect high quantities of Uranium." << endl << endl;
	}
	else if (location == "Caves") {
		cout << "\nYou don't have to walk long before you see the looming entrance of an expansive cave system," <<
			"\ncarved out of a sheer rock face. The darkness is all-consuming; you wont be able to navigate" <<
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
	paths(location, oxygen);
}

void locationSelection(int oxygen) {
	/* user selects which of 4 locations to travel to */
	
	string choice;
	cout << "\n[HEALTH: " << P1->getHealth() << "]" << endl;		//display health
	Check_Oxygen(oxygen);
	cout << "[OXYGEN LEVEL: " << oxygen << "]" << endl << endl;		//display oxygen level
 
	cout << "\nWhat region of Minerva do you want to explore?" << endl;
	cout << "(1) North: Minerva Volcanoes" << endl;
	cout << "(2) East: Caves" << endl;
	cout << "(3) South: Liquid Streams" << endl;
	cout << "(4) West: Clusters of Rocks" << endl;
	cout << "(0) Options menu" << endl << endl;
	
	P1_Inventory->Print();		//print player inventory

	cin >> choice;
	int input = convertToInt(choice);		//input validation
	input = inputValidation(input, 0, 4);

	if (input == 0) {		//options menu
		options(1, oxygen, "Select");		//current player mode is 1 here for single player
	}
	else if (input == 1) {		//volcanoes choice
		oxygen = oxygen - 4;
		locationIntro("Minerva Volcanoes", oxygen);
	}
	else if (input == 2) {		//caves choice
		oxygen = oxygen - 3;
		locationIntro("Caves", oxygen);
	}
	else if (input == 3) {		//streams choice
		oxygen = oxygen - 6;
		locationIntro("Liquid Streams", oxygen);
	}
	else if (input == 4) {		//rocks choice
		oxygen = oxygen - 5;
		locationIntro("Clusters of Rocks", oxygen);
	}
}

void paths(string location, int oxygen) {
	/* send user down path of choice based on current location */
	
	Path pathA, pathB, pathC, pathD;
	//set path objects - (moves, material prob, hazard prob, small enemy prob, med enemy prob, lg enemy prob)
	pathA.setPath(3, 0, 7, 40, 60, 70);			//70% chance enemy - 40% small, 20% medium, 10% large
	pathB.setPath(1, 30, 12, 20, 35, 40);		//40% chance enemy - 20% small, 15% medium, 5% large
	pathC.setPath(2, 50, 10, 25, 40, 50);		//50% chance enemy - 25% small, 15% medium, 10% large
	pathD.setPath(2, 100, 15, 35, 50, 60);		//60% chance enemy - 35% small, 15% medium, 10% large

	//set material probability per path
	int matProbA = 0, matProbB = 30, matProbC = 50, matProbD = 100;

	string choice;
	int newInput = 1;

	//set materials based on location
	string material;
	if (location == "Minerva Volcanoes") {
		material = "Uranium";
	}
	else if (location == "Caves") {
		material = "Copper";
	}
	else if (location == "Liquid Streams") {
		material = "Hydrazine";
	}
	else if (location == "Clusters of Rocks") {
		material = "Fluorine";
	}

	cout << "\nYou are able to go down one of four paths." << endl;

	do
	{
		cout << "\n[HEALTH: " << P1->getHealth() << "]" << endl;			//display health
		Check_Oxygen(oxygen);
		cout << "[OXYGEN LEVEL: " << oxygen << "]" << endl << endl;			//display oxygen level

		cout << "\nWhich path do you choose to take? Please enter a number 1-4:" << endl;
		cin >> choice;

		int input = convertToInt(choice);		//input validation
		input = inputValidation(input, 0, 4);
		
		
		if (input == 0) {		//options
			options(1, oxygen, location);
		}
		else if (input == 1) {				//path 1 that differs per location
			if (location == "Minerva Volcanoes") {
				oxygen = pathC.goPath(*P1_Inventory, location, oxygen, material);
				oxygen = materialCollecting(pathC, location, oxygen, matProbC, material);
			}
			else if (location == "Caves") {
				oxygen = pathB.goPath(*P1_Inventory, location, oxygen, material);
				oxygen = materialCollecting(pathB, location, oxygen, matProbB, material);
			}
			else if (location == "Liquid Streams") {
				oxygen = pathD.goPath(*P1_Inventory, location, oxygen, material);
				oxygen = materialCollecting(pathD, location, oxygen, matProbD, material);
			}
			else if (location == "Clusters of Rocks") {
				oxygen = pathA.goPath(*P1_Inventory, location, oxygen, material);
				oxygen = materialCollecting(pathA, location, oxygen, matProbA, material);
			}
		}
		else if (input == 2) {				//path 2 that differs per location
			if (location == "Minerva Volcanoes") {
				oxygen = pathB.goPath(*P1_Inventory, location, oxygen, material);
				oxygen = materialCollecting(pathB, location, oxygen, matProbB, material);
			}
			else if (location == "Caves") {
				oxygen = pathC.goPath(*P1_Inventory, location, oxygen, material);
				oxygen = materialCollecting(pathC, location, oxygen, matProbC, material);
			}
			else if (location == "Liquid Streams") {
				oxygen = pathB.goPath(*P1_Inventory, location, oxygen, material);
				oxygen = materialCollecting(pathB, location, oxygen, matProbB, material);
			}
			else if (location == "Clusters of Rocks") {
				oxygen = pathC.goPath(*P1_Inventory, location, oxygen, material);
				oxygen = materialCollecting(pathC, location, oxygen, matProbC, material);
			}
		}
		else if (input == 3) {				//path 3 that differs per location
			if (location == "Minerva Volcanoes") {
				oxygen = pathA.goPath(*P1_Inventory, location, oxygen, material);
				oxygen = materialCollecting(pathA, location, oxygen, matProbA, material);
			}
			else if (location == "Caves") {
				oxygen = pathD.goPath(*P1_Inventory, location, oxygen, material);
				oxygen = materialCollecting(pathD, location, oxygen, matProbD, material);
			}
			else if (location == "Liquid Streams") {
				oxygen = pathC.goPath(*P1_Inventory, location, oxygen, material);
				oxygen = materialCollecting(pathC, location, oxygen, matProbC, material);
			}
			else if (location == "Clusters of Rocks") {
				oxygen = pathB.goPath(*P1_Inventory, location, oxygen, material);
				oxygen = materialCollecting(pathB, location, oxygen, matProbB, material);
			}
		}
		else if (input == 4) {				//path 4 that differs per location
			if (location == "Minerva Volcanoes") {
				oxygen = pathD.goPath(*P1_Inventory, location, oxygen, material);
				oxygen = materialCollecting(pathD, location, oxygen, matProbD, material);
			}
			else if (location == "Caves") {
				oxygen = pathA.goPath(*P1_Inventory, location, oxygen, material);
				oxygen = materialCollecting(pathA, location, oxygen, matProbA, material);
			}
			else if (location == "Liquid Streams") {
				oxygen = pathA.goPath(*P1_Inventory, location, oxygen, material);
				oxygen = materialCollecting(pathA, location, oxygen, matProbA, material);
			}
			else if (location == "Clusters of Rocks") {
				oxygen = pathD.goPath(*P1_Inventory, location, oxygen, material);
				oxygen = materialCollecting(pathD, location, oxygen, matProbD, material);
			}
		}
		
		bool found_material = false;
		found_material = P1_Inventory->Find_Item(material);
		if (found_material == true) {			//check if material was collected
			cout << "\nNow that you have successfully collected the " << material << ", it's time to go back to Demeter!\n" << endl;
			break;
		} 

		cout << "\nDo you wish to:" << endl;
		cout << "(1) Continue exploring other paths in this location" << endl;
		cout << "(2) Leave the " << location << " and go back to the ship\n" << endl;
		P1_Inventory->Print();		//print player inventory
		cin >> choice;

		newInput = convertToInt(choice);		//input validation
		newInput = inputValidation(newInput, 0, 2);

		if (newInput == 0) {		//options choice
			options(1, oxygen, location);
		}
	} while (newInput == 1);		//run until user chooses to leave location

	locationDemeter(oxygen);		//return to Demeter
}

int materialCollecting(Path& pathObject, string location, int oxygen, int matProb, string material)
{
	/* Determines probability of materials, and collects if applicable */
	
	Inventory* P1_InventoryPtr = P1_Inventory;
	pathObject.setMaterial(location);		//sets material per location
	bool matCollect = false;				//true to collect material, false if not
	matCollect = pathObject.determineAmount(matProb, oxygen);		//determines if collect materials or not

	if (matCollect == true) {			//add material to inventory if determined true
		oxygen = pathObject.collectMaterial(*P1_InventoryPtr);
		P1_Inventory->Add_to_Inventory(material);
	}

	return oxygen;
}

void locationDemeter(int oxygen) {
  /* ship location - home base/place to deposit materials */

	string refillHealthChoice;

	cout << "\n[HEALTH: " << P1->getHealth() << "]" << endl;				//display health
	Check_Oxygen(oxygen);
	cout << "[OXYGEN LEVEL: " << oxygen << "]" << endl << endl;			//display oxygen level

	if (P1->getHealth() < 30) {
		cout << "\nThe Demeter only has enough health kits to entirely refill your health once, and then partially the second time.\n"
			<< "Do you wish to refill your health?\n"
			<< "(1) Yes \t" << "(2) No" << endl;
		cin >> refillHealthChoice;

		int refillInput = convertToInt(refillHealthChoice);		//input validation
		refillInput = inputValidation(refillInput, 0, 2);

		if (refillInput == 0) {		//options
			options(1, oxygen, "Demeter");
		}
		if (refillInput == 1) {			//refill health
			P1->refillHealth();
			cout << "[HEALTH: " << P1->getHealth() << "]" << endl;
		}
		else if (refillInput == 2) {		//don't refill health
			cout << "\nYou choose not to make use of the health kits just yet.\n"
				<< "[HEALTH: " << P1->getHealth() << "]" << endl;
		}
	}

	string choice;
	//Demeter menu
	cout << "\nLOCATION: Demeter" << endl << endl;
	cout << "What is your next move?" << endl;
	cout << "(1) Explore Minerva" << endl;
	cout << "(2) Repair Ship" << endl;

	cin >> choice;

	int input = convertToInt(choice);		//input validation
	input = inputValidation(input, 0, 2);

	if (input == 0) {		//options
		options(1, oxygen, "Demeter");
	}
	if (input == 1) {		//select location
		locationSelection(oxygen);
	}
	else if (input == 2) {		//repair ship
		oxygen--;
		The_Ship->Deposit_material(*P1_Inventory); //This is where the ship will search the player's inventory for the materials needed, when found they will be deleted and the material will come out as true.
		The_Ship->Win_condition(); //If all four materials are set to true the player wins and is sent to the main menu.
		locationDemeter(oxygen);	//brings the player back to the main menu of Demeter
	}
}

void singlePlayer() {
	cout << "\n-----------------------------" << endl;
	cout << "       SINGLE PLAYER" << endl;
	cout << "-----------------------------\n" << endl;

	gameIntro(1);
	
	cout << "[HEALTH: " << P1->getHealth() << "]" << endl;			//display health
	cout << "[OXYGEN LEVEL: " << oxygen << "]" << endl << endl;		//display oxygen
	system("pause");

	Beginning_stage();

	locationDemeter(oxygen);
}

/*		//Multiplayer option to be included later
void multiPlayer() {
	cout << "\n-----------------------------" << endl;
	cout << "      MULTIPLAYER MODE" << endl;
	cout << "-----------------------------\n" << endl;

	gameIntro(2);
	Player *P1 = new Player();
	Player *P2 = new Player();

	Beginning_stage();
}
*/

void options(int playerMode, int oxygen, string optionLocation) {
	/* options menu that is prompted by entering '0' */
	
	string menuChoice;
	int width = 20;
	cout << "\n- - - - - - - - -" << endl;
	cout << "  OPTIONS MENU" << endl;
	cout << "- - - - - - - - -\n" << endl;

	cout << "[HEALTH: " << P1->getHealth() << "]" << endl;				//display health
	Check_Oxygen(oxygen);
	cout << "[OXYGEN LEVEL: " << oxygen << "]" << endl << endl;			//display oxygen
	P1_Inventory->Print();		//print player inventory

	//show Demeter repair status
	cout << left << setw(width) << "Reactor Core" << setw(width) << "Navigation System" << setw(width) 
		<< "Left Thruster" << setw(width) << "Oxidizer" << endl;
	cout << left << setw(width) << shipStatus->getReactorCore() << setw(width) << shipStatus->getNavSystem() 
		<< setw(width) << shipStatus->getLeftThruster() << setw(width) << shipStatus->getOxidizer() << endl;

	cout << "\n(1) Go to main menu" << endl;
	cout << "(2) Reset Game" << endl;
	cout << "(3) Close Options Menu" << endl;
	cout << "(0) Quit" << endl;
	cin >> menuChoice;

	int input = convertToInt(menuChoice);		//input validation
	input = inputValidation(input, 0, 3);

	if (input == 1) {		//main menu
		continueGame = true;
		cout << "\n\n\n\n\n";
		mainMenu(oxygen);
	}
	else if (input == 2) {		//reset based on game mode
		if (playerMode == 1) {
			setGame();
			singlePlayer();
		}
		/*else if (playerMode == 2) {
			setGame();
			multiPlayer();
		}*/
	}
	else if (input == 3) {
		if (optionLocation == "Demeter") {		//return to Demeter location if there
			locationDemeter(oxygen);
		}
		else if (optionLocation == "Select") {	//return to location selection if there
			locationSelection(oxygen);
		}
		else {
			paths(optionLocation, oxygen);
		}
	}
	else if (input == 0) {		//quit
		_Exit(10);
	}
}

void gameRules() {
	/* overall rules that display at start of game */

	cout << "\n\nObjective: Repair the ship so you can get off the planet. You will be given two or more options at each stage.\n"
		<< "Your choices impact your survival." << endl;
	cout << "Collect 4 specific items to repair your ship." << endl;
	cout << "Input '0' at any time to open the options menu. Here you will be able to see your inventory, repair status, and oxygen level.\n" << endl;
}

int convertToInt(string input) {
	/* checks if input is a number, and converts it to an int */
	
	int stringCounter = 1;

	while (stringCounter != 0) {
		stringCounter = 0;
		for (int i = 0; i < input.length(); i++) {
			if (!isdigit(input[i])) {
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

int inputValidation(int input, int min, int max) {
	/* checks if input is within valid range */

	while (input < min || input > max) {
		string menuChoice;

		cout << "This is an invalid input" << endl;
		cout << "Please enter a number between " << min << " and " << max << endl;

		cin >> menuChoice;
		input = convertToInt(menuChoice);
	}
	return input;
}
