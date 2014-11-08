#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
	Board(int mines, int sizex, int sizey);
	~Board();
	void print();
	char getData(int x, int y);
	void moveToUIF(int x, int y);
	void checkEmptyField(int x, int y);
	int addToMinecount(int x, int y, int& minecount);
	int getGameStatus();
private:
	// multidimensional board arrays
	//what the user sees
	char** uif;
	//what there actually is
	char** data;
	//size of arrays (and board)
	const int sizeX;
	const int sizeY;
};

#endif
