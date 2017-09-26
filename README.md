//# Rock-Skissors-Paper-Lizard-Spok
//Simple console-output game
#include <iostream>
#include <time.h>
//========================================================
//DEFINE BLOCK
//The below "define" block simplifies our coding and
//helps us to avoid confusion when we list all possible 
//weapon combination:
//========================================================
#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define LIZARD 3
#define SPOK 4
#define DRAW 5
#define HUMAN_LOST 6
#define HUMAN_WIN 7
using namespace std;

//gameResult is a function, that takes two integer values and
//returns one of 3 possible values:
//DRAW, HUMAN_LOST, HUMAN_WIN
//here we declare a prototype of function, that is defined below main function
int gameResult(int, int); 

int main()
{
	cout << "ROCK, PAPER, SCISSORS, LIZARD, SPOK game" << endl;
	cout << "==============================================" << endl;
	cout << "The rules of game:\n" << endl;
	cout << "Human player and computer player choose weapon out of 5 possible options" << endl;
	cout << "Combination of weapons defines the result based on the following rules:" << endl;
	cout << "PAPER:" << endl;
	cout << "Paper covers rock, i.e. paper wins" << endl;
	cout << "Scissors cuts paper, paper looses" << endl;
	cout << "Lizard eats paper, paper looses" << endl;
	cout << "Paper disrpoves spok, paper wins" << endl;
	cout << "ROCK:" << endl;
	cout << "Paper covers rock, paper wins" << endl;
	cout << "Rock crushes scissors, rock wins" << endl;
	cout << "Rock crushes lizard, rock wins" << endl;
	cout << "Spok vaporizes rock, rock lost" << endl;
	cout << "SCISSORS:" << endl;
	cout << "Scissors cuts paper, scissors wins" << endl;
	cout << "Scissors decapitates lizard, scissor wins" << endl;
	cout << "Spok smashes scissors, scissors loose" << endl;
	cout << "Rock crushes scissors, rock wins" << endl;
	cout << "LIZARD:" << endl;
	cout << "Lizard poisons spok, lizard wins" << endl;
	cout << "Lizard eats paper, paper looses" << endl;
	cout << "Rock crushes lizard, rock wins" << endl;
	cout << "Scissors decapitates lizard, scissor wins" << endl;
	cout << "SPOK:" << endl;
	cout << "Lizard poisons spok, lizard wins" << endl;
	cout << "Spok smashes scissors, scissors loose" << endl;
	cout << "Spok vaporizes rock, rock lost" << endl;
	cout << "Paper disrpoves spok, paper wins" << endl;
	cout << "If both player select same weapon, that draw." << endl;
	cout << "Enjoy!" << endl;
	cout << "==============================================" << endl;
		
	srand(time(0));//random shift based on time. This makes a random generated number really random
	bool YesOrNo = true;//variable to stop the game loop(play again or exit

	//three variables below are added just to store the results of previous
	//games: 
	int win = 0;
	int draw = 0;
	int lost = 0;

	//Main game loop:
	while (YesOrNo)
	{
		int human_weapon = 0; //variable to store human choice
		do // show menu
		{			
			cout << "Please choose your weapon:" << endl;
			cout << ROCK << " - Rock" << endl;
			cout << PAPER << " - Paper" << endl;
			cout << SCISSORS << " - Scissors" << endl;
			cout << LIZARD << " - Lizard" << endl;
			cout << SPOK << " - Spok" << endl;
			cin >> human_weapon;
		} while (human_weapon < 0 || human_weapon > 4);
		cout << "You have choosen "; //show player choice
		switch (human_weapon)
		{
		case ROCK:
			cout << "ROCK" << endl;
			break;
		case PAPER:
			cout << "PAPER" << endl;
			break;
		case SCISSORS:
			cout << "SCISSORS" << endl;
			break;
		case LIZARD:
			cout << "LIZARD" << endl;
			break;
		case SPOK:
			cout << "SPOK" << endl;
			break;
		default:
			break;
		}

		int computer_weapon = rand() % 5; //generate computer choice
		cout << "Computer has choosen "; // show computer choice
		switch (computer_weapon)
		{
		case ROCK:
			cout << "ROCK" << endl;
			break;
		case PAPER:
			cout << "PAPER" << endl;
			break;
		case SCISSORS:
			cout << "SCISSORS" << endl;
			break;
		case LIZARD:
			cout << "LIZARD" << endl;
			break;
		case SPOK:
			cout << "SPOK" << endl;
			break;
		default:
			break;
		}
		cout << "======================================================" << endl;
		
		//Declare variable to store game result. 
		//Launch game function to return a result:
		int game_result = gameResult(human_weapon, computer_weapon); 

		//Show result, modify score:
		if (game_result == HUMAN_LOST)
		{
			lost++;
			cout << "You lost" << endl;
		}
		if (game_result == HUMAN_WIN)
		{
			win++;
			cout << "You won" << endl;
		}
		if (game_result == DRAW)
		{
			draw++;
			cout << "Draw" << endl;
		}
		//show score:
		cout << "The score so far is: " << endl;
		cout << "You won " << win << " times" << endl;
		cout << "You lost " << lost << " times" << endl;
		cout << "Draws " << draw << " times" << endl;
		cout << "======================================================" << endl;

		//ask user to exit or continue
		cout << "Would you like to play again (1) or exit (0)?" << endl;		
		cin >> YesOrNo;
	}
	return 0;
}
//Function below is accepts weapons and 
//returns game result based on comparison of weapons 
int gameResult(int human_weapon, int computer_weapon)
{
	int result = 0;
	if (human_weapon == computer_weapon) //if same weapon - stop function
	{
		result = DRAW;
		return result;
	}
	switch (human_weapon)
	{
	case ROCK:
		switch (computer_weapon)
		{
		case PAPER:
			cout << "Paper covers rock" << endl;
			result = HUMAN_LOST;
			break;
		case SCISSORS:
			cout << "Rock crushes scissors" << endl;
			result = HUMAN_WIN;
			break;
		case LIZARD:
			cout << "Rock crushes lizard" << endl;
			result = HUMAN_WIN;
			break;
		case SPOK:
			cout << "Spok vaporizes rock" << endl;
			result = HUMAN_LOST;
			break;
		default:
			break;
		}
		break;
	case PAPER:
		switch (computer_weapon)
		{
		case ROCK:
			cout << "Paper covers rock" << endl;
			result = HUMAN_WIN;
			break;
		case SCISSORS:
			cout << "Scissors cuts paper" << endl;
			result = HUMAN_LOST;
			break;
		case LIZARD:
			cout << "Lizard eats paper" << endl;
			result = HUMAN_LOST;
			break;
		case SPOK:
			cout << "Paper disrpoves spok" << endl;
			result = HUMAN_WIN;
			break;
		default:
			break;
		}
		break;
	case SCISSORS:
		switch (computer_weapon)
		{
		case ROCK:
			cout << "Rock crushes scissors" << endl;
			result = HUMAN_LOST;
			break;
		case PAPER:
			cout << "Scissors cuts paper" << endl;
			result = HUMAN_WIN;
			break;
		case LIZARD:
			cout << "Scissors decapitates lizard" << endl;
			result = HUMAN_WIN;
			break;
		case SPOK:
			cout << "Spok smashes scissors" << endl;
			result = HUMAN_LOST;
			break;
		default:
			break;
		}
		break;
	case LIZARD:
		switch (computer_weapon)
		{
		case ROCK:
			cout << "Rock crushes lizard" << endl;
			result = HUMAN_LOST;
			break;
		case PAPER:
			cout << "Lizard eats paper" << endl;
			result = HUMAN_WIN;
			break;
		case SCISSORS:
			cout << "Scissors decapitates lizard" << endl;
			result = HUMAN_LOST;
			break;
		case SPOK:
			cout << "Lizard poisons spok" << endl;
			result = HUMAN_WIN;
			break;
		default:
			break;
		}
		break;
	case SPOK:
		switch (computer_weapon)
		{
		case ROCK:
			cout << "Spok vaporizes rock" << endl;
			result = HUMAN_WIN;
			break;
		case PAPER:
			cout << "Paper disrpoves spok" << endl;
			result = HUMAN_LOST;
			break;
		case SCISSORS:
			cout << "Spok smashes scissors" << endl;
			result = HUMAN_WIN;
			break;
		case LIZARD:
			cout << "Lizard poisons spok" << endl;
			result = HUMAN_LOST;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return result;
}
