#include <vector>
#include <string>

class Board
{
private:
	char data[15][15];
	int locations[20][2];
	string direction[20];
	int place;
public:
	Board();
	~Board();
	char getSpot(int, int);
	// int getRowLoc(int);
	// int getColLoc(int);
	string getDir(int);
	// void update();
	void setSpot(char, int, int);
	void placeList(vector<string> &);
	bool placeNextVer(string);
	bool placeNextHor(string);
	int findMatch(string);
	void printBoard();
	void outputBoard();
	// void printHidden();
};