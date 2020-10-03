#include "Game_Classes.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

	mainMenu();
	string Starting_Items[8] = {"Pickaxe","Drill","Bucket","Flask","Knife","Gun","Flashlight","Lantern"};
	string player_choice = "";

	cout << "While looking through the wreckage of the Demeter, you found out that the exploration dispensery was damaged, but still operational." << endl
		<< "When you selected the tools needed, the dispensery can only operate to an extent that it can only dispense one item of each catagory." << endl
		<< "\nFor exploration, the categories are:\n" << "Excavation\n" << "Liquid containment\n" << "Weaponry\n" << "Illumination\n" << endl
		<< "In the field of Excavation, would you prefer:\n" << "Pickaxe\n" << "or\n" << "Drill" << endl << endl;

	cout << "Please Select your tool: ";

	cin >> player_choice; 

	while (player_choice != "Pickaxe" && player_choice != "Drill")
	{
		cout << "You have imputed a wrong input, please input the correct tool" << endl << endl;
		cin >> player_choice;
	}



	
	
	
	system("pause");
}