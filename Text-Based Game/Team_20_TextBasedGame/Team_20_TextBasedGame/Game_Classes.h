#pragma once
#include <iostream>
#include <string>
#include <random>

using namespace std;

class Player
{
protected:
	int health = 30;
public:
	void damage()
	{
		health--;
	}
};

class Minerva {
private:
	string neededItem;
	string setting;

public:
	void setItem(string item) {
		neededItem = item;
	}

	void setSetting(string location) {
		setting = location;
	}

	string getItem() {
		return neededItem;
	}

	string getSetting() {
		return setting;
	}
};

class DemeterStatus {
private:
	string reactorCore;
	string navSystem;
	string leftThruster;
	string oxidizer;

public:
	DemeterStatus() {
		reactorCore = "Damaged";
		navSystem = "Damaged";
		leftThruster = "Damaged";
		oxidizer = "Damaged";
	}

	string getReactorCore() {
		return reactorCore;
	}

	string getNavSystem() {
		return navSystem;
	}

	string getLeftThruster() {
		return leftThruster;
	}

	string getOxidizer() {
		return oxidizer;
	}
};

class Items
{
public:
	string data;
	Items *next;
	Items() {}
	Items(string tools)
	{
		data = tools;
		next = nullptr;
	}
};

class Inventory :public Player
{
public:
	Items * head;
	Inventory() : Player()
	{
		head = nullptr;
	}

	void Add_to_Inventory(string Tool)
	{
		Items *X = new Items(Tool);

		if (head == nullptr)
		{
			head = X;
			return;
		}

		Items *Selected_Item = head;
		while (Selected_Item->next != nullptr)
		{
			Selected_Item = Selected_Item->next;
		}
		Selected_Item->next = X;
	}

	int Find_Item(string Item)
	{
		Items *Selected_Item = head;
		int location_of_item = -1;

		while (Selected_Item != nullptr)
		{
			if (Selected_Item->data == Item)
			{
				return location_of_item;
			}
			else
			{
				Selected_Item = Selected_Item->next;
				location_of_item++;
			}
		}
		return location_of_item;
	}

	void Destroy_Item_position(int position)
	{
		Items * Selected_Item = head;

		for (int count = 1; count < position - 1; count++)
			Selected_Item = Selected_Item->next;
		Items * Destroy = Selected_Item->next;
		Selected_Item->next = Destroy->next;
		delete Destroy;
	}

	void Item_Destroyed(string Tool)
	{
		Items *Selected_Item = head;
		while (Selected_Item != nullptr)
		{
			int position = Find_Item(Tool);
			if (position != -1)
				Destroy_Item_position(position);
			Selected_Item = Selected_Item->next;
		}
	}

	void Destroy_First_Item()
	{
		Items *Selected_Item = head;

		head = head->next;
		delete Selected_Item;
	}

	void Print()
	{
		Items* Selected_Item = head;
		cout << "\t[Current Inventory]" << endl;
		cout << "| ";
		while (Selected_Item)
		{
			cout << Selected_Item->data << " | ";
			Selected_Item = Selected_Item->next;
		}
		cout << endl << endl;
	}
};

class Enemy
{
private:
	string Name;
	int Health;
	int Damage;
	int Sight;
	bool Alive = true;
	int Chance;
	int small;
	int medium;
	int large;

public:
	Enemy() {}
	Enemy(string N, int H, int D, int S, int C)
	{
		Name = N;
		Health = H;
		Damage = D;
		Sight = S;
		Chance = C;
	}

	void Increase_Sight()
	{
		Sight = Sight + 2;
	}

	void Decrease_Sight()
	{
		if (Sight != 0 || Sight != 1)
		{
			Sight = Sight - 2;
		}
	}

	bool Died()
	{
		Alive = false;
		return Alive;
	}

	void Enemy_Hit_Player()
	{
		const int Player_Chance = 12;
		int Hit_Chance;
		Hit_Chance = rand() % 20 + 1;
		if (Hit_Chance >= Player_Chance)
		{

		}
	}
	
	void determineSpawn(int s, int m, int l)
	{
		small = s;
		medium = m;
		large = l;
		
		int number;
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distr(0, 100);
		number = distr(gen);

		//return number;

		//if (number <= small) {
			//small enemy
		//}
		//else if (number > small && <= medium) {
			//medium enemy
		//}
		//else if (number > medium && <= large) {
			//large enemy
		//}
		//else {
			//no enemy
			//cout << "\nThe path is empty!" << endl;
		//}




	}
};

class Path : public Enemy
{
private:
	int oxygen;
	int matProb;
	int hazard;
	string location;
	int oxygenLevel;
	int smallEnemy;
	int medEnemy;
	int lgEnemy;
	string material;

public:
	Path() {}
	void setPath(int o, int m, int h, int sm, int med, int lg)
	{
		oxygen = o;
		matProb = m;
		hazard = h;
		smallEnemy = sm;
		medEnemy = med;
		lgEnemy = lg;
	}

	int goPath(string l, int ox, string mat)
	{
		location = l;
		oxygenLevel = ox;
		material = mat;
		oxygenLevel = oxygenLevel - oxygen;

		cout << "\nUpon entering this path, ";

		//determine hazard or enemy (or both)
		int randNum = (rand() % 3) + 1;
		if (randNum == 1) {
			//hazard(prob);
		}
		else if (randNum == 2) {
			determineSpawn(smallEnemy, medEnemy, lgEnemy);
		}
		else {
			//hazard(prob);
			determineSpawn(smallEnemy, medEnemy, lgEnemy);
		}
		
		// if player survived
		cout << "\nThat was a close one! You continue down the path in hopes of finding the " << material << "." << endl;

		//material probability
		//material(matProb);

		return oxygenLevel;
	}
};






void mainMenu();
void singlePlayer();
void multiPlayer();
void singlePlayer();
void multiPlayer();
void inputValidation(int, int);
void options(int, int, string);
void gameRules();
void locationSelection(int);
void currentLocation(string, int);
void locationDemeter(int);
void locationIntro(string, int);
void paths(string, int);

int convertToInt(string);
