#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int cyes = 0;
    int cno = 0;

    cout << "Вы закончили школу NBA с отличием? Type 'yes' or 'no' - ";
    string ar1;
    cin >> ar1;
    if (ar1 == "yes") cyes++;
    if (ar1 == "no") cno++;
    cout << endl;

    cout << "Вам нравится Аль-Хайтам? Type 'yes' or 'no' - ";
    string ar2;
    cin >> ar2;
    if (ar2 == "yes") cyes++;
    if (ar2 == "no") cno++;
    cout << endl;

    cout << "Вы любите Максимилиана Барсодия? Type 'yes' or 'no' - ";
    string ar3;
    cin >> ar3;
    if (ar3 == "yes") cyes++;
    if (ar3 == "no") cno++;
    cout << endl;

    if (ar1 == "yes" && ar2 == "yes" && ar2 == "yes"){
        cout << "piska" << endl << endl;
    }
    cout << "yes - " << cyes << endl << "no - " << cno << endl;

    return 0;
}