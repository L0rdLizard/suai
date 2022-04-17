//Написать функции для поразрядного сложения и вычитания длинных целых чисел, представленных строками символов, и тестирующую программу к ним.
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    char arr1[6] = {'1', '2', '3', '4', '5', '6'},
         arr2[6] = {'5', '3', '7', '1', '9', '3'};
    int result[7] = {0};
    // int i = (int) arr1[0];
    // cout << i - 48 << endl;
    // char i2 = (char) i;
    // cout << i2 << endl;
    // cout << sizeof(result) << endl;
    // int temp_result1 = (char)(((int)arr1[0] - 48) + ((int)arr2[0] - 48));
    // cout << temp_result1;
    // cout << ((int)arr1[0] - 48) + ((int)arr2[0] - 48) << endl;
    // int b = 6;
    // result[0] = (char)b + 48;
    // cout << result[0] << endl;
    for (int i = 5; i >= 0; i--)
    {
        int temp_result = ((int)arr1[i] - 48) + ((int)arr2[i] - 48);
        // cout << temp_result << endl;
        // result[i + 1] += ((int)arr1[i] - 48) + ((int)arr2[i] - 48);
        result[i + 1] += temp_result;
        // cout << result[i + 1] << endl;
        if (temp_result > 9)
        {
            // int temp_result2 = (((int)result[i + 1] - 48) - ((int)result[i + 1] - 48) % 10) / 10;
            // int temp_result2 = (temp_result - (temp_result % 10)) / 10;
            int temp_result2 = ((temp_result) - (((temp_result) % 10) / 10));
            // result[i] = (((int)result[i + 1] - 48) - ((int)result[i + 1] - 48) % 10) / 10;
            result[i] = temp_result2;
            result[i + 1] = temp_result % 10;
        }
        cout << result[i + 1] << endl;
    }

    // summ(arr1, arr2, result);
    for (int i = 0; i < 6; i++)
        cout << arr1[i];
    cout << " + ";
    for (int i = 0; i < 6; i++)
        cout << arr2[i];
    cout << " = ";
    for (int i = result[0] == 0 ? 1 : 0; i < 7; i++)
        cout << result[i];
    cout << endl;
    // system("pause");
    return 0;
}