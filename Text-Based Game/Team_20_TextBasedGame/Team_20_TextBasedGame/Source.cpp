#include "Game_Classes.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Minerva north, south, east, west;

	north.setSetting("Volcano");
	north.setItem("Uranium");

	south.setSetting("Liquid Streams");
	south.setItem("Hydrazine");

	east.setSetting("Cave");
	east.setItem("Copper");

	west.setSetting("Clusters of Rock");
	west.setItem("Fluorine");

	string Starting_Items[8] = { "Pickaxe","Drill","Bucket","Flask","Knife","Gun","Flashlight","Lantern" };

	mainMenu();



	system("pause");
	return 0;
}