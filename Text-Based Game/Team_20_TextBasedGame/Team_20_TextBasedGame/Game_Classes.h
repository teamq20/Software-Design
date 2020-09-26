#pragma once
#include <iostream>
#include <string>

using namespace std;

class Story {
private:
	char *singlePlayerIntro;
	char *multiPlayerIntro;

public:
	void setIntro() {
		singlePlayerIntro = "Greetings VST - 7426. You are one of two brave astronauts, the core members of Operation"
			" Vesta, that have voyaged to examine the distant planet of Minerva, which shows great promise"
			" as a potential new home for the inhabitants of Earth.Unfortunately, due to a miscalculation in"
			" the navigation system of the Demeter(your ship), you have crash landed in an inhospitable"
			" region of Minerva, roughly 400 kilometers south of your initial destination.After running a"
			" systems check, you have found that there are four crucial systems on the Demeter that have"
			" been damaged by the crash.Your crewmate, VST - 7427, has also suffered fatal injuries, leaving"
			" you completely alone.Given the current circumstances of your predicament, you have"
			" approximately 3 days to fix these systems before running out of oxygen.Luckily, however, this"
			" region of Minerva contains valuable minerals that may aid your fixing of these parts.Choose"
			" your path wisely, VST - 7426, and good luck";

		multiPlayerIntro = "Greetings VST-7426 and VST-7427. You are the two core members of Operation Vesta that"
			" have voyaged to examine the distant planet of Minerva, which shows great promise as a"
			" potential new home for the inhabitants of Earth.Unfortunately, due to a miscalculation in the"
			" navigation system of the Demeter(your ship), you have crash landed in an inhospitable region"
			" of Minerva, roughly 400 kilometers south of your initial destination.After running a systems"
			" check, you have found that there are four crucial systems on the Demeter that have been"
			" damaged by the crash.Given the current circumstances of your predicament, you have"
			" approximately 3 days to fix these systems before running out of oxygen.Luckily, however, this"
			" region of Minerva contains valuable minerals that may aid your fixing of these parts. Choose"
			" your path wisely, and good luck.";
	}

	string getIntro(int i) {
		if (i == 1) {
			return singlePlayerIntro;
		}
		else if (i == 2) {
			return multiPlayerIntro;
		}
	}
};

class Player
{
protected:
	int health = 3;
public:
	void damage()
	{
		health--;
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

class Inventory:public Player
{
public:
	Items *head;
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

		for (int count =1 ; count < position-1; count++)
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
		while (Selected_Item)
		{
			cout << Selected_Item->data << " ";
			Selected_Item = Selected_Item->next;
		}
		cout << endl;
	}
};

void mainMenu();
void singlePlayer();
void multiPlayer();
void inputValidation(int);

int convertToInt(string);