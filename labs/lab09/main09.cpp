#include "lab09.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
 
    char arr1[6] = { 1,2,3,4,5,6 },
        arr2[6] = { 5,3,7,1,9,3 },
        result[7] = { 0,0,0,0,0,0,0 };
    for (int i = 5; i >= 0; i--)
    {
        result[i + 1] += arr1[i] + arr2[i];
        if (result[i + 1] > 9)
        {
            result[i] = (result[i + 1] - result[i + 1] % 10) / 10;
            result[i + 1] %= 10;
        }
    }
 
    for (int i = 0; i < 6; i++)
        cout << arr1[i];
    cout << " + ";
    for (int i = 0; i < 6; i++)
        cout << arr2[i];
    cout << " = ";
    for (int i = result[0] == 0 ? 1 : 0; i < 7; i++)
        cout << result[i];
    cout << std::endl;
    system("pause");
 
    return 0;
}