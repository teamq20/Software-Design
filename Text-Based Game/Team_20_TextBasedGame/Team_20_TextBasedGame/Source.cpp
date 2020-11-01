#include "Game_Classes.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	srand(time(0));		//seed for random generator
	
	Minerva north, south, east, west;

	north.setSetting("Volcano");
	north.setItem("Uranium");

	south.setSetting("Liquid Streams");
	south.setItem("Hydrazine");

	east.setSetting("Cave");
	east.setItem("Copper");

	west.setSetting("Clusters of Rock");
	west.setItem("Fluorine");

	string Starting_Items[8] = {
	"Pickaxe", "Drill", "Bucket", "Flask", "Knife", "Gun", "Flashlight", "Lantern" };

	mainMenu();

	system("pause");
	return 0;
}