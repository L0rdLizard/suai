// #include "stdafx.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

#include "crossword.h"

using namespace std;

string sharedLetters(string s1, string s2)

{
    string sharedletters = "";

    string commonletter = "";

    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {

            if (tolower(s1.at(i)) == tolower(s2.at(j)))
            {
                commonletter = s1.at(i);

                sharedletters.append(commonletter);
            }
        }
    }

    return sharedletters;
}