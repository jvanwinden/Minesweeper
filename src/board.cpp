#include <board.h>
#include <iostream>
#include <time.h>
#include <cstdlib>


using namespace std;

//ctor
Board::Board(int mines, int sizex, int sizey) : sizeX(sizex), sizeY(sizey)
{
	srand(time(NULL));
	// init arrays
	uif = new char* [sizeX];
	data = new char* [sizeX];
	for(int i = 0; i < sizeX; i++){
		uif[i] = new char[sizeY];
		data[i] = new char[sizeY];
	}

	// fill arrays with dots
	for(int y = 0; y < sizeY; y++)
	{
		for(int x = 0; x < sizeX; x++)
		{
			uif[x][y] = '.';
			data[x][y] = '.';
		}
	}

	//add mines to data, not uif
	for(int i = 0; i < mines; i++)
	{
		int x, y;
		while(true)
		{
			x = rand() % sizeX;
			y = rand() % sizeY;
			if(data[x][y] != 'm')
			{
				data[x][y] = 'm';
				break;
			}
		}
	}

	//add numbers to data, not uif
	for(int y = 0; y < sizeY; y++)
	{
		for(int x = 0; x < sizeX; x++)
		{
			if(data[x][y] != 'm')
			{
				int minecount = 0;
				addToMinecount(x - 1, y - 1, minecount);
				addToMinecount(x, y - 1, minecount);
				addToMinecount(x + 1, y - 1, minecount);
				addToMinecount(x - 1, y, minecount);
				addToMinecount(x + 1, y, minecount);
				addToMinecount(x - 1, y + 1, minecount);
				addToMinecount(x, y + 1, minecount);
				addToMinecount(x + 1, y + 1, minecount);
				char c = (char)(((int)'0')+minecount);
				data[x][y] = c;
			}
		}
	}
}

Board::~Board()
{
	// delete inner arrays
	for(int i = 0; i < sizeY; i++)
	{
		delete[] data[i];
		delete[] uif[i];
	}
	// delete outer arrays
	delete[] data;
	delete[] uif;
}


//print board
void Board::print()
{
	// newline and 3 spaces
	cout << endl << "   ";

	//print abcde... etc
	for(int i = 0; i < sizeX; i++)
	{
		cout << (char) (97 + i);
	}
	cout << endl << endl;

	for(int y = 0; y < sizeY; y++)
	{
		// a is nr 97 on ascii table, 97 + 1 to char = b
		cout << (char) (97 + y) << "  ";
		for(int x = 0; x < sizeX; x++)
		{
			// only print uif
			cout << uif[x][y];
		}
		cout << endl;
	}
	cout << endl;
}

char Board::getData(int x, int y)
{
	if(x < sizeX && y < sizeY && x >= 0 && y >= 0)
	{
		return data[x][y];
	}

	//if x or y arent in range
	return 'o';

}

// copy minecount from data to uif
void Board::moveToUIF(int x, int y)
{
	uif[x][y] = data[x][y];
}


// recursive function if minecount == 0
void Board::checkEmptyField(int x, int y)
{
	if(x >= 0 && y >= 0 && x < sizeX && y < sizeY)
	{
		if(data[x][y] == '0' && uif[x][y] == '.'){
			uif[x][y] = '0';
			checkEmptyField(x - 1, y - 1);
			checkEmptyField(x, y - 1);
			checkEmptyField(x + 1, y - 1);
			checkEmptyField(x - 1, y);
			checkEmptyField(x + 1, y);
			checkEmptyField(x -1, y + 1);
			checkEmptyField(x, y + 1);
			checkEmptyField(x + 1, y + 1);
		} else {
			moveToUIF(x, y);
		}
	}
}

// if data[x][y] contains mine, increment minecount
int Board::addToMinecount(int x, int y, int& minecount){
	if(x >= 0 && x < sizeX && y >= 0 && y < sizeY)
	{
		if(data[x][y] == 'm') minecount++;
	}
	return 0;
}


int Board::getGameStatus()
{
	for(int y = 0; y < sizeY; y++)
	{
		for(int x = 0; x < sizeX; x++)
		{

			if(uif[x][y] == '.') {
				if(data[x][y] != 'm')
				{
					return 0;
				}
			}
			// if all dots are mines, return 1
		}
	}
	return 1;
}
