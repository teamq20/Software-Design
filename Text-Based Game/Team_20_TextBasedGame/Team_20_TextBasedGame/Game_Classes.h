#pragma once
#include <iostream>

using namespace std;

class Player
{
private:
	int health = 3;
public:
	void damage()
	{
		health--;
	}
};

class Invintory 
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


