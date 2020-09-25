#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
	int health = 3;
	int moves = 30;
	string choice;
public:
	void damage()
	{
		health--;
	}

	void moveMade() {
		moves--;
	}
};

class Inventory 
{
private:
	string Item_1;
	string Item_2;
	string Item_3;
	string Item_4;
	  
public:
	void Set_Item_1(string);
	void Set_Item_2(string);
	void Set_Item_3(string);
	void Set_Item_4(string);

	void Destroy_item(string X)
	{
		string Item = X;
		Item = "";
		cout << "the item was destroyed in use";
	}
};

void mainMenu();
void inputValidation(int);
void singlePlayer();
void multiPlayer();

int convertToInt(string);