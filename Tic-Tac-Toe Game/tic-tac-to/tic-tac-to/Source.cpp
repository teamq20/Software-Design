#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;

// how both the computer and the player will select a square
int select(int Board[][3], int pos, int x)
{
	int first;
	int second;
	int second_pos = pos;
	//begin sifting through the array for the chosen position.
	for (first = 0; first < pos; first++)
		for (second = 0; second < second_pos; second++)
			if (Board[first][second] == x)
				break;
			else
				return NULL;

	if (second < second_pos && first < pos)
	{
		int jump = second_pos - 1;
		for (int index = second; index < jump; index++)
			Board[first][second] = Board[first][second + 1];
	}
	return x;

}

bool Check_Win(int list[])
{
	if (list[0] == 1 && list[1] == 2 && list[2] == 3)
		return true;
	if (list[0] == 4 && list[1] == 5 && list[2] == 6)
		return true;
	if (list[0] == 7 && list[1] == 8 && list[2] == 9)
		return true;

	if (list[0] == 1 && list[1] == 4 && list[2] == 7)
		return true;
	if (list[0] == 2 && list[1] == 5 && list[2] == 8)
		return true;
	if (list[0] == 3 && list[1] == 6 && list[2] == 9)
		return true;

	if (list[0] == 1 && list[1] == 5 && list[2] == 9)
		return true;
	if (list[0] == 3 && list[1] == 5 && list[2] == 7)
		return true;

	if (sizeof(list) == 5)
	{
		cout << " sadly the game has ended in a tie " << endl;
	}

	return false;
}

int main()
{
	int board[3][3] = { { 1,2,3 },{ 4,5,6 },{ 7,8,9 } }; //the tic-tac-toe board.
	int * COM_Stack; //a list of positions that the computer has selected.
	int * Player_Stack; // a list of positions that the Player has solected. 

	COM_Stack = new int[5];
	Player_Stack = new int[5];

	int empty_space = 9;

	int Com_choice; //how the computer will choose a position.

	int player_choice; //how the player will chose a position.

	cout << "the computer will go first ";

	for (int turn = 0; turn < 9; turn++)
	{
		Com_choice = rand() % 9 + 1;



		while (COM_Stack[turn] == NULL);
		{
			Com_choice = rand() % 9 + 1;
			COM_Stack[turn] = select(board, empty_space, Com_choice);
		}
		cout << "The number that the computer chooses, is " << Com_choice;
		bool win_con = false;
		win_con = Check_Win(COM_Stack);
		if (win_con == true)
		{
			cout << " The computer has won the game";
		}
		cout << "now it is your turn to chose ";
		cin >> player_choice;

		win_con = Check_Win(Player_Stack);
		if (win_con == true)
		{
			cout << " congrats you have won the game";
		}

		while (player_choice == Com_choice)
		{
			cout << "Please chose a different number ";
			cin >> player_choice;
		}

		Player_Stack[turn] = select(board, empty_space--, player_choice);
		while (Player_Stack[turn] == NULL);
		{
			cout << " either you or the computer already ";
			Player_Stack[turn] = select(board, empty_space--, player_choice);

		}

		sort(COM_Stack, COM_Stack + turn);
		sort(Player_Stack, Player_Stack + turn);


	}


	system("pause");
	return 0;
}


