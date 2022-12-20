#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

#include "board.h"

void sortHighLow(vector<string> &);
void makeCaps(vector<string> &);
bool checkForLetters(string);

void sortHighLow(vector<string> &list)
{
    string temp;

    for (int i = 0; i < list.size() - 1; i++)
    {
        for (int j = 0; j < list.size() - i - 1; j++)
        {
            if (list[j].size() < list[j + 1].size())
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void makeCaps(vector<string> &list)
{
    for (int i = 0; i < list.size(); i++)
    {
        for (int j = 0; j < list[i].size(); j++)
        {
            (list[i])[j] = toupper((list[i])[j]);
        }
    }
}

bool checkForLetters(string word)
{

    if (word.size() > 15)
        return false;

    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] < 65 || word[i] > 122 || (word[i] > 90 && word[i] < 97))
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[])
{
    vector<string> list;
    string temp;

    ifstream ifs;
    string file = "words.txt";
    ifs.open(file);
    if (!ifs)
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    while (ifs >> temp)
    {
        if (checkForLetters(temp))
        {
            list.push_back(temp);
        }
    }

    ifs.close();

    Board board(40, 40);

    sortHighLow(list);
    makeCaps(list);

    cout << "--------------------------------------" << endl;
    for (int a = 0; a < list.size(); a++)
    {
        cout << list[a] << endl;
    }
    cout << endl;

    board.placeList(list);

    cout << "---------------------------------------------" << endl;
    board.printBoard();
    board.outputBoard();
    return 0;
}