#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#include "board.h"

Board::Board(unsigned int a, unsigned int b)
{
	this->a = a;
	this->b = b;
	data = new char *[a];
	for (int i = 0; i < a; i++)
	{
		data[i] = new char[b];
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			data[i][j] = '_';
		}
	}

	for (int row = 0; row < 20; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			locations[row][col] = 0;
		}
	}
	place = 1;
}

Board::~Board()
{
	for (int i = 0; i < a; i++)
	{
		delete[] data[i];
	}
	delete[] data;
}

void Board::setSpot(char c, int row, int col)
{
	data[row][col] = c;
}

char Board::getSpot(int i, int j)
{
	return data[i][j];
}

void Board::placeList(vector<string> &list)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < list[0].size(); j++)
			{
				setSpot((list[0])[j], a / 2, (b - list[0].size()) / 2 + j);
			}
			locations[0][0] = a / 2;
			locations[0][1] = (b - list[0].size()) / 2;
		}
		if (i != 0 && i % 2 == 0)
		{
			if (placeNextVer(list[i]))
			{
			}
			else if (placeNextHor(list[i]))
			{
			}
			else
			{
				cout << "Could not place word: " << list[i] << endl;
				list[i] = " ";
				place++;
			}
		}
		else if (i != 0 && i % 2 != 0)
		{
			if (placeNextHor(list[i]))
			{
			}
			else if (placeNextVer(list[i]))
			{
			}
			else
			{
				cout << "Could not place word: " << list[i] << endl;
				list[i] = " ";
				place++;
			}
		}
	}
}

// placeNextVer method tries to find and place next word on board, vertically
bool Board::placeNextVer(string word)
{
	int match = 0;
	bool isPlaced = 0, key = 0;
	for (int j = 0; j < b; j++)
	{
		for (int i = 0; i < a + 1 - word.size(); i++)
		{
			for (int k = 0; k < word.size(); k++)
			{
				if ((i + k < a) && (getSpot(i + k, j) == '_' || getSpot(i + k, j) == word[k]))
				{
					match++;
				}

				if ((i + k < a) && (getSpot(i + k, j) == word[k]))
				{
					if ((i + k + 1 < a) && (i + k - 1 >= 0) && (i + k - 1 < b) && (getSpot(j, i + k + 1) == '_' && getSpot(j, i + k - 1) == '_'))
					{
						match = match + 2;
						key = 1;
					}
				}

				if ((i + k < a) && (j + 1 < b) && (j - 1 >= 0) && (getSpot(i + k, j + 1) == '_' && getSpot(i + k, j - 1) == '_'))
				{
					match = match + 2;
				}

				if ((i + word.size() < a) && (i - 1 >= 0) && (getSpot(i - 1, j) == '_' && getSpot((i + word.size()), j) == '_'))
				{
					if (k == 0)
						match = match + 2;
				}

			} // end of "k" for loop
			if (match == 3 * word.size() + 2 && key == 1 && isPlaced == 0)
			{
				// place word
				for (int p = 0; p < word.size(); p++)
				{
					setSpot(word[p], i + p, j);
				}
				// set isPlaced to true
				isPlaced = 1;
				// assign coordinates to the newly-placed word
				locations[place][0] = i;
				locations[place][1] = j;
				place++;
				return 1;
			}
			match = 0;
			key = 0;
		}	  // end of second for loop (i)
	}		  // end of outermost for loop (j)
	return 0; // return false if the word was not able to be placed vertically
} // end of placeNextVer method

// placeNextHor method tries to find and place next word on board, horizontally
bool Board::placeNextHor(string word)
{
	int match = 0;
	bool isPlaced = 0, key = 0;
	for (int j = 0; j < b; j++)
	{
		for (int i = 0; i < a + 1 - word.size(); i++)
		{
			for (int k = 0; k < word.size(); k++)
			{
				if ((i + k < a) && (getSpot(j, i + k) == '_' || getSpot(j, i + k) == word[k]))
				{
					match++;
				}

				if ((i + k < a) && (getSpot(j, i + k) == word[k]))
				{
					if ((i + k + 1 < a) && (i + k - 1 >= 0) && (i + k - 1 < b) && (getSpot(j, i + k + 1) == '_' && getSpot(j, i + k - 1) == '_'))
					{
						match = match + 2;
						key = 1;
					}
				}

				if ((i + k < a) && (j + 1 < b) && (j - 1 >= 0) && (getSpot(j + 1, i + k) == '_' && getSpot(j - 1, i + k) == '_'))
				{
					match = match + 2;
				}

				if ((i + word.size() < a) && (i - 1 >= 0) && (getSpot(j, i - 1) == '_' && getSpot(j, i + word.size()) == '_'))
				{
					if (k == 0)
						match = match + 2;
				}
			} // end of "k" for loop
			if (match == 3 * word.size() + 2 && key == 1 && isPlaced == 0)
			{
				// place word
				for (int p = 0; p < word.size(); p++)
				{
					setSpot(word[p], j, i + p);
				}
				locations[place][0] = j;
				locations[place][1] = i;
				place++;

				// set isPlaced to true
				isPlaced = 1;
				return 1;
			}
			match = 0;
			key = 0;
		}	  // end of second for loop (i)
	}		  // end of outermost for loop (j)
	return 0; // return false if the word was not able to be placed horizontally
} // end of placeNextVer method

void Board::printBoard()
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << data[i][j];

			cout << " ";
		}
		cout << endl;
	}
}

// output in file board.txt
void Board::outputBoard()
{
	ofstream fout;
	fout.open("board.txt");
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			fout << data[i][j];
			fout << " ";
		}
		fout << endl;
	}
	fout.close();
}