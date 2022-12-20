#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "CLI/CLI11.hpp"

using namespace std;

#define EXEC "crossword.exe"
#define TITLE "\nCrossword generator"
#define FOOTER \
    "Created with <3 by L0rdLizard (Barsukov Maxim) at SUAI University"

class Settings
{
public:
    string file_in;
    string file_out = "board.txt";
    int size = 15;
};

#include "board.h"

void sortHighLow(vector<string> &);
void makeCaps(vector<string> &);
bool checkForLetters(string);



int main(int argc, char *argv[])
{
    CLI::App app(TITLE, EXEC);
    Settings config;
    app.footer(FOOTER);

    app.add_option("input", config.file_in, "Input file")->option_text("FILE");
    app.add_option("output", config.file_out, "Output file")->option_text("FILE");

    app.add_option("-s, --size", config.size, "Width of the board")->option_text("SIZE");

    CLI11_PARSE(app, argc, argv);

    if (config.file_in.empty())
    {
        cout << "No file specified" << endl;
        cout << "Use -h or --help to see usage" << endl;
        return 0;
    }

    if (config.size < 0)
    {
        cout << "Width and height must be positive" << endl;
        return 0;
    }


    vector<string> list;
    string temp;

    ifstream ifs;
    string file = config.file_in;
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

    Board board(config.size, config.size);

    sortHighLow(list);
    makeCaps(list);

    cout << "--------------------------------------" << endl;
    for (int z = 0; z < list.size(); z++)
    {
        cout << list[z] << endl;
    }
    cout << endl;

    board.placeList(list);

    cout << "---------------------------------------------" << endl;
    board.printBoard();
    board.outputBoard(config.file_out);
    return 0;
}



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