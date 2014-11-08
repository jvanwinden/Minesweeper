#include <iostream>
#include <game.h>
#include <string>
#include <time.h>

using namespace std;

void getUserInput(int& result, const string message)
{
	cout << message;
	while(!(cin >> result))
	{
		cout << message;
		cin.clear();
		cin.ignore();
	}
}


int main()
{
	int minecount, sizeX, sizeY, x, y, status;
	string turn;
	getUserInput(sizeX, "Enter board width (3-16): ");
	getUserInput(sizeY, "Enter board height (3-16): ");
	getUserInput(minecount, "Enter the number of mines: ");
	Game game(minecount, sizeX, sizeY);

	time_t start = time(0);
	// main game loop
	while(true)
	{
		cout << "Enter coords: ";
		cin >> turn;
		if(turn.length() > 2)
		{
			cout << endl << "Too long. 2 coords please." << endl;
			continue;
		}
		// convert char to int
		x = turn[1] - 97;
		y = turn[0] - 97;
		status = game.update(x, y);
		if(status == -1) 
		{
			cout << endl << "You lost. Press any key to exit" << endl; 
			break;
		}
		if(status == 1)
		{
			int t = (int) difftime(time(0), start);
			cout << endl << "Congratulations! You won the game in " << t << " seconds." << endl;
			break;
		}
	}
	return 0;
}
