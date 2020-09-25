#pragma once
#include <iostream>

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
private:
	int health = 3;
public:
	void damage()
	{
		health--;
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
void singlePlayer();
void multiPlayer();
void inputValidation(int);

int convertToInt(string);