// Ввести степень и коэффициенты полинома. Ввести границы интервала a, b и точность eps. Найти корень полинома на интервале [a, b] методом деления отрезка пополам (считать, что p(a) * p(b) < 0).

#include "lab08.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int n;

    node *top_polinom, *end_polinom;
    node *top_polinom1, *end_polinom1;
    node *top_polinom2, *end_polinom2;
    node *top_polinom3, *end_polinom3;

    cout << "enter n= ";
    cin >> n;
    create_polinom(top_polinom, end_polinom, n);

    return 0;
}