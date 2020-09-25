#pragma once
#include <iostream>

using namespace std;

class Player
{
protected:
	int health = 3;
	string Name;
public:
	Player()
	{

	}
	void damage()
	{
		health--;
	}

	bool Is_Dead(Player)
	{
		if (health == 0)
		{
			cout << "You have unfourtanatly Perished";
			return true;
		}
	}
};

class Invintory: public Player
{
private:
	string Item_1;
	string Item_2;
	string Item_3;
	string Item_4;

public:

	void Destroy_item(string X)
	{
		string Item = X;
		Item = "";
		cout << "the item was destroyed in use";
	}

		Invintory(string Excavation, string Liquid, string Weapon, string Illumination, Player) : Player()
		{
			Item_1 = Excavation;
			Item_2 = Liquid;
			Item_3 = Weapon;
			Item_4 = Illumination;
		}

};




