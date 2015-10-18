/*
              Test 1
intput: game_type = 1, starting_position = 2
	output: 2, 1.5, 2, 1.5, 1, .5, 0, .5, 0, .5, 0.
	You won a total of: $100

			  Test 2
input: game_type = 2, starting_position = 4, num_chips = 5
	output: You won a total of: $12000
	With an average of: $2400

			  Test 3
input: game_type = 3, num_chips = 10
	output: Slot 0 has a total reward of: $6200.00
			With an average of: $620.00
			Slot 1 has a total reward of: $5700.00
			With an average of: $570.00
			Slot 2 has a total reward of: $13200.00
			With an average of: $1320.00
			Slot 3 has a total reward of: $23100.00
			With an average of: $2310.00
			Slot 4 has a total reward of: $31500.00
			With an average of: $3150.00
			Slot 5 has a total reward of: $24000.00
			With an average of: $2400.00
			Slot 6 has a total reward of: $13700.00
			With an average of: $1370.00
			Slot 7 has a total reward of: $3300.00
			With an average of: $330.00
			Slot 8 has a total reward of: $5700.00
			With an average of: $570.00
*/

#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

int Menu()// option 1: 1 chip drop, option 2: multiple chips dropped, option 3: quit
{
	int game_type = 0;
	int starting_position = 0;
	do
	{
		cout << "" << endl;
		cout << "Please enter 1. to drop one chip," << endl;
		cout << "2. to drop multiple chips," << endl;
		cout << "3. to drop the same amount of chips into each slot," << endl;
		cout << "or 4. to quit the program: ";
		cin >> game_type;
	} while (game_type > 4 || game_type < 1);
	return game_type;
}


double Chip_Movement(double current_position, int num_chips)
{
	for (int rows = 12; rows > 0; rows--)
	{
		double movement = .5;
		int randomnumber = rand() % 2;
		if (current_position == 0)//left edge of the board
		{
			(current_position = current_position + movement);
			if (num_chips == 1)
			{
				cout << current_position << endl;
			}
		}
		else if (current_position == 8)//right edge of the board
		{
			(current_position = current_position - movement);
			if (num_chips == 1)
			{
				cout << current_position << endl;
			}
		}
		else if (randomnumber == 0) // moves to the right
		{
			(current_position = current_position - movement);
			if (num_chips == 1)
			{
				cout << current_position << endl;
			}
		}
		else //(randomnumber == 1), moves to the left
		{
			(current_position = current_position + movement);
			if (num_chips == 1)
			{
				cout << current_position << endl;
			}
		}
	}
	return current_position;
	
}


int Prize_Winnings(double current_position)
{
	int winnings = 0;
	const int prize0 = 100;
	const int prize1 = 500;
	const int prize2 = 1000;
	const int prize3 = 0;
	const int prize4 = 10000;
	const int prize5 = 0;
	const int prize6 = 1000;
	const int prize7 = 500;
	const int prize8 = 100;
	if (current_position == 0)
	{
		winnings = prize0;
	}
	if (current_position == 1)
	{
		winnings = prize1;
	}
	if (current_position == 2)
	{
		winnings = prize2;
	}
	if (current_position == 3)
	{
		winnings = prize3;
	}
	if (current_position == 4)
	{
		winnings = prize4;
	}
	if (current_position == 5)
	{
		winnings = prize5;
	}
	if (current_position == 6)
	{
		winnings = prize6;
	}
	if (current_position == 7)
	{
		winnings = prize7;
	}
	if (current_position == 8)
	{
		winnings = prize8;
	}
	return winnings;
}

int Multiple_Chips(double current_position, int num_chips)//option 2
{
	int money = 0;
	int total_reward = 0;
	double average_reward = 0;
	for (int num_times = 0; num_times < num_chips; num_times++)
	{
		double final_slot = Chip_Movement(current_position, num_chips);
		money = Prize_Winnings(final_slot);
		total_reward += money;
	}
	return total_reward;
}

int Multiple_Slots(int num_chips)//option 3
{
	int money = 0;
	double total_reward = 0;
	int current_position = 0;
	for (int starting_position = 0; starting_position <= 8; starting_position++)
	{
		int money = 0;
		double total_reward = 0;
		total_reward = Multiple_Chips(starting_position, num_chips);
		double average_reward = total_reward / num_chips;
		cout << "Slot " << starting_position << " has a total reward of: $" << total_reward << endl; 
		cout << "\tWith an average of: $" << fixed << setprecision(2) << average_reward << endl;
		cout << "" << endl;
	}
	return total_reward;
}

int main()
{
	srand(time(0));

	int game_type = 0;
	do
	{
		game_type = Menu();
		if (game_type == 1)//single chip, you choose position
		{
				int num_chips = 1;
				double starting_position = 0;
				cout << "Please enter the starting position you'd like to drop your chips: ";
				cin >> starting_position; 
				if (starting_position >= 0 && starting_position <= 8)
				{
					cout << starting_position << endl;
					double final_slot = Chip_Movement(starting_position, num_chips);
					int money = Prize_Winnings(final_slot);
					cout << "You won a total of: $" << money << endl;
				}
		}
		if (game_type == 2)//multiple chips, you choose position
		{
			int num_chips = 0;
			double current_position = 0;
			double starting_position = 0;
			cout << "Please enter the starting position you'd like to drop your chips: ";
			cin >> current_position;
			if (current_position >= 0 && current_position <= 8)
			{
				cout << "Please enter the number of chips you'd like to drop: ";
				cin >> num_chips;
				if (num_chips > 1)
				{
					double total_reward = Multiple_Chips(current_position, num_chips);
					cout << "You won a total of: $" << total_reward << endl;
					double average_winnings = total_reward / num_chips;
					cout << "With an average of: $" << average_winnings << endl;
				}
			}
		}
		if (game_type == 3)//you choose number of chips, that number goes in each slot
		{
			int num_chips = 0;
			double starting_position = 0;
			cout << "Please enter the number of chips you'd like to drop: ";
			cin >> num_chips;
			if (num_chips > 1)
			{
				double total_reward = Multiple_Slots(num_chips);
			}
		}
	} while (game_type >= 1 && game_type <= 3);
	if (game_type == 4)
	{
		cout << "Have a nice day!" << endl;
	}

	system("pause");
	return 0;
}
