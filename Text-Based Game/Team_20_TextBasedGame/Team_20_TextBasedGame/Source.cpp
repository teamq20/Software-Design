#include "Game_Classes.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

	mainMenu();
	string Starting_Items[8] = { "Pickaxe","Drill","Bucket","Flask","Knife","Gun","Flashlight","Lantern" };

	cout << "While looking through the wreckage of the Demeter, you found out that the exploration dispensery was damaged, but still operational." << endl
		<< "When you selected the tools needed, the dispensery can only operate to an extent that it can only dispense one item of each catagory." << endl
		<< "\nFor exploration, the categories are:\n" << "Excavation\n" << "Liquid containment\n" << "Weaponry\n" << "Illumination\n" << endl
		<< "In the field of Excavation, would you prefer:\n" << "Pickaxe\n" << "or\n" << "Drill" << endl;
	
	system("pause");
}