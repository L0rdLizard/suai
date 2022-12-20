#include <vector>
#include <string>

class Board
{
private:
	// char **data;
	char **data;
	int locations[20][2];
	int place;
	unsigned int a, b;
public:
	Board(unsigned int a, unsigned int b);
	~Board();
	char getSpot(int, int);
	void setSpot(char, int, int);
	void placeList(vector<string> &);
	bool placeNextVer(string);
	bool placeNextHor(string);
	void printBoard();
	void outputBoard(string output);
};