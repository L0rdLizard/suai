#include <iostream>

using namespace std;

int main()
{
    int arr1[116] = { 72, 97, 112, 112, 121, 32, 98, 105, 114, 116, 104, 100, 97, 121, 44, 32, 109, 121, 32, 107, 105, 116, 116, 101, 110,
                    44, 32, 115, 117, 110, 44, 32, 98, 117, 110, 44, 32, 99, 104, 101, 114, 114, 121, 44, 32, 102, 108, 111, 119, 101, 114, 44, 32, 99,
                    111, 114, 110, 44, 32, 99, 117, 99, 117, 109, 98, 101, 114, 44, 32, 116, 111, 109, 97, 116, 111, 44, 32, 115, 111, 117, 112, 44,
                    32, 102, 101, 108, 116, 45, 116, 105, 112, 32, 112, 101, 110, 44, 32, 98, 101, 97, 100, 44, 32, 112, 101, 112, 112, 101, 114, 44, 32, 112, 101, 97, 99, 104 };
    for (auto u : arr1)
        cout << (char)u;
    cout << endl;

    system("pause");
    system("cls");


    int arr2[201] = { 89, 111, 117, 32, 97, 114, 101, 32, 109, 121, 32, 114, 97, 121, 32, 111, 102, 32, 115, 117, 110, 115, 104, 105, 110, 101, 32, 98, 117, 110, 32, 112,
        105, 110, 101, 97, 112, 112, 108, 101, 32, 112, 111, 109, 101, 103, 114, 97, 110, 97, 116, 101, 32, 122, 117, 99, 99, 104, 105, 110, 105, 32, 112, 101, 112, 112,
        101, 114, 32, 99, 114, 101, 97, 109, 32, 99, 97, 107, 101, 32, 116, 101, 97, 32, 112, 114, 111, 103, 114, 97, 109, 109, 101, 114, 32, 112, 101, 110, 32, 102, 108,
        111, 119, 101, 114, 32, 112, 111, 116, 32, 112, 105, 108, 108, 115, 32, 100, 111, 103, 32, 104, 111, 114, 115, 101, 32, 112, 105, 122, 122, 97, 32, 98, 101, 97, 99,
        104, 32, 104, 111, 117, 115, 101, 32, 110, 101, 119, 115, 112, 97, 112, 101, 114, 32, 97, 110, 100, 32, 115, 105, 109, 112, 108, 121, 32, 116, 104, 101, 32, 109, 111,
        115, 116, 32, 98, 101, 108, 111, 118, 101, 100, 32, 98, 111, 121, 32, 111, 110, 32, 116, 104, 101, 32, 112, 108, 97, 110, 101, 116, 33 };
    for (auto u : arr2)
        cout << (char)u;
    cout << endl;

    system("pause");
    system("cls");
  

    int arr3[15] = { 73, 32, 106, 117, 115, 116, 32, 108, 111, 118, 101, 32, 121, 111, 117 };
    for (auto u : arr3)
        cout << (char)u;
    cout << endl;

    return 0;
}