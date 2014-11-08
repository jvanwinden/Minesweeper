#include <game.h>
#include <iostream>

using namespace std;

//ctor
Game::Game(int minecount, int sizeX, int sizey) : board(Board(minecount, sizeX, sizey))
{
	// print board for first time
	board.print();
}

Game::~Game()
{
	// empty dtor
}

//update, called after uinput
int Game::update(int x, int y)
{
	if(board.getData(x, y) == 'm')
	{
		// if a mine was hit
		return -1;
	} else if(board.getData(x, y) == '0')
	{
		// if empty field was hit, enter recursive function
		board.checkEmptyField(x, y);
		// out of bounds
	} else if(board.getData(x, y) == 'o'){
		
	}
	else {
		// none of the above, so a number was hit
		board.moveToUIF(x, y);
	}
	if(board.getGameStatus() == 1) {
		board.print();
		return 1;
	}

	// clear screen?
	cout << endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

	//finally, print board
	board.print();
	return 0;
}
