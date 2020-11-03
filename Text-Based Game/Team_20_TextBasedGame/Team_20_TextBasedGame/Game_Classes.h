#pragma once
#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <cctype>

using namespace std;


class Player
{
protected:
	int health = 30;
	int damAmount;
	string causeDeath;
public:
	Player() {}
	void damage(int d)		//applies damage to player's health
	{
		damAmount = d;
		health = health - d;
	}

	bool isAlive()			//checks if player is still alive
	{
		if (health > 0) {
			return true;
		}
		else { 
			return false;
		}
	}

	void dead(string cod)		//applies if player is dead / 0 HP
	{
		causeDeath = cod;
		
		if (isAlive() == false) {
			cout << "\n\n*GAME OVER* VST-7426, you have been terminated by " << causeDeath << "." << endl;
			cout << "Play again if you wish to redeem yourself..." << endl;
			system("pause");
			_Exit(10);
		}
	}
};

class Minerva {
private:
	string neededItem;
	string setting;

public:
	void setItem(string item) {		//sets material per location
		neededItem = item;
	}

	void setSetting(string location) {		//sets location name
		setting = location;
	}

	string getItem() {		//retuns location's material
		return neededItem;
	}

	string getSetting() {		//gets name of location
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
	DemeterStatus() {		//initially sets all ship parts as damaged 
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

	void setReactorCore() {
		reactorCore = "Repaired";
	}

	void setNavSystem() {
		navSystem = "Repaired";
	}

	void setLeftThruster() {
		leftThruster = "Repaired";
	}

	void setOxidizer() {
		oxidizer = "Repaired";
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

class Inventory : public Player
{
public:
	Items * head;
	Inventory() : Player()
	{
		head = nullptr;
	}

	void Add_to_Inventory(string Tool)		//add item to inventory
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

	int Find_Item(string Item)		//finds item in inventory and returns location of it
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

	void Destroy_Item_position(int position)		//removes item from inventory
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

	void Print()			//prints current inventory
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

class Enemy : public Player
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
	string location;

public:
	Enemy() : Player()
	{}
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

	//0 = small enemy
	//1 = medium enemy
	//2 = large enemy
	void Combat(int enemyType) {
		const int playerChance = 50;
		int hitChance;
		hitChance = rand() % 100 + 1;		//hit chance between 1-100
		int enemyHP;
		Inventory inventory_weapon;
		string weapon;
		int knifeDamage = 3;
		int gunDamage = 5;

		//if/else checking to see the player's current weapon
		if (inventory_weapon.Find_Item("Knife") == -1) {
			weapon = "Gun";
		}
		else {
			weapon = "Knife";
		}

		//small enemy combat
		if (enemyType == 0) {
			enemyHP = 5;

			cout << "\nEnemy HP: " << enemyHP << endl << endl;

			while (enemyHP > 0) {
				hitChance = rand() % 100 + 1;	//If hitChance is >1 && <=50, enemy misses; hitChance is >50 inflict damage on player
				if (hitChance <= playerChance) {
					cout << "The enemy left an opening for attack!" << endl;
					cout << "No damage was received" << endl;

					if (weapon == "Knife") {
						cout << "You attack and inflict " << knifeDamage << " damage on your enemy!" << endl;
						enemyHP -= knifeDamage;
						cout << "\nEnemy HP: " << enemyHP << endl << endl;
						system("pause");
					}
					else {
						cout << "You attack and inflict " << gunDamage << " damage on your enemy!" << endl;
						enemyHP -= gunDamage;
						cout << "\nEnemy HP: " << enemyHP << endl << endl;
						system("pause");
					}
				}
				else if (hitChance > playerChance) {
					cout << "You received damage!" << endl;
					Player::damage(2);
					system("pause");
					if (Player::isAlive() == true)
					{
						continue;
					}
					else
					{
						Player::dead("a small enemy");
						break;
					}
				}
			}

			cout << "\nThe enemy has been defeated!" << endl;
			cout << "\n[HEALTH: " << Player::health << "]" << endl;
		}
		//medium enemy combat
		else if (enemyType == 1) {
			enemyHP = 10;
			
			cout << "\nEnemy HP: " << enemyHP << endl << endl;

			while (enemyHP > 0) {
				hitChance = rand() % 90 + 10;	//If hitChance is >10 && <=50, enemy misses; hitChance is >50 inflict damage on player
				if (hitChance <= playerChance) {
					cout << "The enemy left an opening for attack!" << endl;
					cout << "No damage was received" << endl;

					if (weapon == "Knife") {
						cout << "You attack and inflict " << knifeDamage << " damage on your enemy!" << endl;
						enemyHP -= knifeDamage;
						cout << "\nEnemy HP: " << enemyHP << endl << endl;
						system("pause");
					}
					else {
						cout << "You attack and inflict " << gunDamage << " damage on your enemy!" << endl;
						enemyHP -= gunDamage;
						cout << "\nEnemy HP: " << enemyHP << endl << endl;
						system("pause");
					}
				}
				else if (hitChance > playerChance) {
					cout << "You received damage!" << endl;
					Player::damage(4);
					system("pause");
					if (Player::isAlive() == true)
					{
						continue;
					}
					else
					{
						Player::dead("a medium enemy");
						break;
					}
				}
			}
			cout << "\nThe enemy has been defeated!" << endl;
			cout << "\n[HEALTH: " << Player::health << "]" << endl;
		}
		//large enemy combat
		else if (enemyType == 2) {
			enemyHP = 15;
			
			cout << "\nEnemy HP: " << enemyHP << endl << endl;
			
			while (enemyHP > 0) {
				hitChance = rand() % 80 + 20;	//If hitChance is >20 && <=50, enemy misses; hitChance is >50 inflict damage on player
				if (hitChance <= playerChance) {
					cout << "The enemy left an opening for attack!" << endl;
					cout << "No damage was received" << endl;

					if (weapon == "Knife") {
						cout << "You attack and inflict " << knifeDamage << " damage on your enemy!" << endl;
						enemyHP -= knifeDamage;
						cout << "\nEnemy HP: " << enemyHP << endl << endl;
						system("pause");
					}
					else {
						cout << "You attack and inflict " << gunDamage << " damage on your enemy!" << endl;;
						enemyHP -= gunDamage;
						cout << "\nEnemy HP: " << enemyHP << endl << endl;
						system("pause");
					}
				}
				else if (hitChance > playerChance) {
					cout << "You received damage!" << endl;
					Player::damage(6);
					system("pause");
					if (Player::isAlive() == true)
					{
						continue;
					}
					else
					{
						Player::dead("a large enemy");
						break;
					}
				}
			}
			cout << "\nThe enemy has been defeated!" << endl;
			cout << "\n[HEALTH: " << Player::health << "]" << endl;
		}
	}
	
	void determineSpawn(int s, int m, int l, string loc)
	{
		Enemy enemy;

		small = s;
		medium = m;
		large = l;
		location = loc;
		
		int number;
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distr(0, 100);
		number = distr(gen);

		if (number <= small) {
			cout << "you encounter a small enemy!" << endl;
			Combat(0);
		}
		else if (number > small && number <= medium) {
			cout << "you encounter a medium enemy!" << endl;
			Combat(1);
		}
		else if (number > medium && number <= large) {
			cout << "you encounter a large enemy!" << endl;
			Combat(2);
		}
		else {
			cout << "no enemies are found nearby." << endl;
		}
	}
};

class Hazards : public Player
{
private:
	int prob;
	int health;
	string location;
	string hazard;

public:
	Hazards() : Player()
	{}
	void setHazard(string loc)
	{
		location = loc;

		if (location == "Minerva Volcanoes") {
			hazard = "flowing lava";
		}
		else if (location == "Caves") {
			hazard = "a falling rock";
		}
		else if (location == "Liquid Streams") {
			hazard = "a strong current";
		}
		else if (location == "Clusters of Rocks") {
			hazard = "a falling rock";
		}
	}

	void determineProb(int p)
	{
		prob = p;

		int number1;
		random_device rd1;
		mt19937 gen1(rd1());
		uniform_int_distribution<> distr(0, 100);
		number1 = distr(gen1);

		if (number1 <= prob) {
			deployHazard();
		}
		else {
			cout << "you notice there doesn't seem to be any hazards down this way." << endl;
			cout << "You continue on exploring this path." << endl;
		}
	}

	void deployHazard()
	{
		cout << "you get hurt by " << hazard << "!" << endl;

		Player::damage(3);

		if (Player::isAlive() == true) {
			cout << "\nThe damage wasn't too bad, so you continue on exploring." << endl;
		}
		else {
			Player::dead(hazard);
		}
	}
};

class Materials
{
private:
	string material;
	int materialProbability;
	string location;
	int oxygen;

public:
	void setMaterial(string loc)
	{
		location = loc;

		if (location == "Minerva Volcanoes") {
			material = "Uranium";
		}
		else if (location == "Caves") {
			material = "Copper";
		}
		else if (location == "Liquid Streams") {
			material = "Hydrazine";
		}
		else if (location == "Clusters of Rocks") {
			material = "Fluorine";
		}
	}

	int determineAmount(int prob, int oxygenLevel)
	{
		materialProbability = prob;
		oxygen = oxygenLevel;

		int number2;
		random_device rd2;
		mt19937 gen2(rd2());
		uniform_int_distribution<> distr(0, 100);
		number2 = distr(gen2);

		if (number2 <= materialProbability) {		//collect material
			oxygen = collectMaterial();
		}
		else {										//no material
			cout << "\nUnfortunately, there doesn't seem to be any " << material << " down this path." << endl;
			cout << "Maybe you should try another one...\n" << endl;
		}

		return oxygen;
	}

	int collectMaterial()
	{
		//set tools to their oxygen amount
		Inventory inventoryTool, inventoryStreamsTool;
		string tool, streamsTool;
		int toolAmnt = 0;
		int streamsToolAmnt = 0;

		//check to see the player's current tool
		if (inventoryTool.Find_Item("Drill") == -1) {
			tool = "Pickaxe";
			toolAmnt = 4;
		}
		else {
			tool = "Drill";
			toolAmnt = 2;
		}

		//check to see the player's current water tool
		if (inventoryStreamsTool.Find_Item("Flask") == -1) {
			streamsTool = "Bucket";
			streamsToolAmnt = 2;
		}
		else {
			streamsTool = "Flask";
			streamsToolAmnt = 3;
		}
		
		//separate dialogue for the Liquid Streams
		if (material == "Hydrazine") {
			cout << "You have found the water containing the " << material << "! You use your " << streamsTool << " to collect it!" << endl;
			oxygen = oxygen - streamsToolAmnt;
			int contaminationChance = rand() % 100 + 1;
			if (streamsTool == "Bucket" && contaminationChance <= 30) {
				cout << "Oh no! Using your " << streamsTool << " resulted in contamination of the liquid!" << endl;
				cout << "You are forced to recollect it, using up more of your oxygen." << endl;
				oxygen = oxygen - streamsToolAmnt;
			}
		}
		else {
			cout << "You have found the " << material << "! You mine for it using your " << tool << "!" << endl;
			oxygen = oxygen - toolAmnt;
		}

		//print message of successful collection
		cout << "\nNow that you have successfully collected the " << material << ", it's time to go back to Demeter!" << endl;

		return oxygen;
	}
};

class Path : public Enemy, public Hazards, public Materials
{
private:
	int oxygen;			//amount of oxgen depleted per path
	int matProb;		//probability of materials per path
	int hazardProb;		//probability of hazards per path
	string location;	//current location name
	int oxygenLevel;	//current oxygen level
	int smallEnemy;		//probability of a small enemy
	int medEnemy;		//probability of a medium enemy
	int lgEnemy;		//probability of a large enemy
	string material;	//name of material per location

public:
	Path() : Hazards(), Enemy(), Materials()
	{}
	void setPath(int o, int m, int h, int sm, int med, int lg)
	{
		oxygen = o;
		matProb = m;
		hazardProb = h;
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
		int randNum = (rand() % 3) + 1;			//chooses random number 1-3
		if (randNum == 1) {
			Hazards::setHazard(location);
			Hazards::determineProb(hazardProb);		//hazards
		}
		else if (randNum == 2) {
			Enemy::determineSpawn(smallEnemy, medEnemy, lgEnemy, location);
		}
		else {
			Hazards::setHazard(location);
			Hazards::determineProb(hazardProb);		//hazards
			cout << "Continuing down the path, ";
			Enemy::determineSpawn(smallEnemy, medEnemy, lgEnemy, location);
		}
		
		// if player survived (put this in enemy with bool isAlive from Player)
		//cout << "\nThat was a close one! You continue down the path in hopes of finding the " << material << "." << endl;

		//material collection
		Materials::setMaterial(location);
		oxygenLevel = Materials::determineAmount(matProb, oxygenLevel);



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