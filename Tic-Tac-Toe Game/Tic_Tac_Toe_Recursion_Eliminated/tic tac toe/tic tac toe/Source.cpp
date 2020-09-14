#include "Header.h";
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main() {

	const int total = 9;

	static boardPositions position[total];
	int yCounter = 0;

	//assign values to struct position
	for (int i = 0; i < total; i++)
	{

		position[i].pos = i + 1;

		if (i >= 0 && i <= 2) {
			position[i].boardX = 0;
		}
		else if (i >= 3 && i <= 5) {
			position[i].boardX = 1;
		}
		else if (i >= 6 && i <= 8) {
			position[i].boardX = 2;
		}

		position[i].boardY = yCounter;
		yCounter++;

		if (yCounter > 2)
			yCounter = 0;
	}

	displayMenu(position);

	cout << endl;

	//GAME


	system("pause");
	return 0;
}