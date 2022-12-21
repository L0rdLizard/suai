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
	place = 0;
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
	if (i < 0 || i >= a || j < 0 || j >= b)
	{
		return '+';
	}
	return data[i][j];
}

void Board::placeList(vector<string> &list)
{
	int previous = 0;
	while (1)
	{
		vector<int> temp;
		for (int i = 0; i < list.size(); i++)
		{
			bool add = true;
			if (place == 0)
			{
				for (int j = 0; j < list[0].size(); j++)
				{
					setSpot((list[0])[j], a / 2, (b - list[0].size()) / 2 + j);
				}
				locations[0][0] = a / 2;
				locations[0][1] = (b - list[0].size()) / 2;
				place++;
				temp.push_back(i);
				continue;
			}
			if (place != 0 && place % 2 == 0)
			{
				if (placeNextVer(list[i]))
				{
				}
				else if (placeNextHor(list[i]))
				{
				}
				else
				{
					add = false;
					// cout << "Could not place word: " << list[i] << endl;
					// list[i] = " ";
					// place++;
				}
			}
			else if (place != 0 && place % 2 != 0)
			{
				if (placeNextHor(list[i]))
				{
				}
				else if (placeNextVer(list[i]))
				{
				}
				else
				{
					add = false;
					// cout << "Could not place word: " << list[i] << endl;
					// list[i] = " ";
					// place++;
				}
			}
			if (add)
				temp.push_back(i);
		}
		if (temp.size() == previous)
			break;
		previous = temp.size();

		for (int i = 0; i < temp.size(); i++)
		{
			list.erase(list.begin() + temp[i] - i);
		}
	}
	if (list.size() != 0)
	{
		cout << "Could not place words: ";
		for (int i = 0; i < list.size(); i++)
		{
			cout << list[i] << " ";
		}
		cout << endl;
	}
}


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
				if (getSpot(i + k, j) == '_' || getSpot(i + k, j) == word[k])
				{
					match++;
				}

				if (getSpot(i + k, j) == word[k])
				{
					if (getSpot(i + k + 1, j) == '_' && getSpot(i + k - 1, j) == '_')
					{
						match = match + 2;
						key = 1;
					}
				}

				if (getSpot(i + k, j + 1) == '_' && getSpot(i + k, j - 1) == '_')
				{
					match = match + 2;
				}

				if (getSpot(i - 1, j) == '_' && getSpot((i + word.size()), j) == '_')
				{
					if (k == 0)
						match = match + 2;
				}
			}
			if (match == 3 * word.size() + 2 && key == 1 && isPlaced == 0)
			{

				for (int p = 0; p < word.size(); p++)
				{
					setSpot(word[p], i + p, j);
				}

				isPlaced = 1;

				locations[place][0] = i;
				locations[place][1] = j;
				place++;
				return 1;
			}
			match = 0;
			key = 0;
		}
	}  
	return 0; 
} 


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
				if (getSpot(j, i + k) == '_' || getSpot(j, i + k) == word[k])
				{
					match++;
				}

				if (getSpot(j, i + k) == word[k])
				{
					if (getSpot(j, i + k + 1) == '_' && getSpot(j, i + k - 1) == '_')
					{
						match = match + 2;
						key = 1;
					}
				}

				if (getSpot(j + 1, i + k) == '_' && getSpot(j - 1, i + k) == '_')
				{
					match = match + 2;
				}

				if (getSpot(j, i - 1) == '_' && getSpot(j, i + word.size()) == '_')
				{
					if (k == 0)
						match = match + 2;
				}

			} 
			if (match == 3 * word.size() + 2 && key == 1 && isPlaced == 0)
			{
				
				for (int p = 0; p < word.size(); p++)
				{
					setSpot(word[p], j, i + p);
				}
				locations[place][0] = j;
				locations[place][1] = i;
				place++;


				isPlaced = 1;
				return 1;
			}
			match = 0;
			key = 0;
		}
	}
	return 0; 
}

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


void Board::outputBoard(string output)
{
	ofstream fout;
	fout.open(output);
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