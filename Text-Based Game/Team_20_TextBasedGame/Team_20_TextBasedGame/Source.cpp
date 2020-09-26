#include "Game_Classes.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

	mainMenu();
	string Starting_Items[8] = { "Pickaxe","Drill","Bucket","Flask","Knife","Gun","Flashlight","Lantern" };

	cout << "While looking through the wreckage of the Demeter, you found out that the exploration dispensery was damaged, but still operational." << endl
		<< "When you selected the tools needed, the dispensery can only operate to an extent that it can only dispense one item of each catagory." << endl
		<< "for exploration, the catagories are:" << endl << "Excavation" << endl << "Liquid contaiment" << "Weaponry" << "Illumination" << endl << endl
		<< "In the feild of Excavation, would you prefer:" << endl << "Pickaxe" << endl << "or" << endl << "Drill" << endl;
	
}