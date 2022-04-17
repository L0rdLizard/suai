// Написать функции для поразрядного сложения и вычитания длинных целых чисел, представленных строками символов, и тестирующую программу к ним.
#include <iostream>
#include <math.h>
using namespace std;
void summ(char *arr1, char *arr2, int *result)
{
    for (int i = 5; i >= 0; i--)
    {
        int temp_result = ((int)arr1[i] - 48) + ((int)arr2[i] - 48);
        cout << temp_result << endl;
        result[i + 1] += temp_result;
        if (temp_result > 9)
        {
            int temp_result2 = (temp_result - (temp_result % 10)) / 10;
            result[i] = temp_result2;
            result[i + 1] %= 10;
        }
    }
}

int main()
{
    char arr1[6] = {'1', '2', '3', '4', '5', '6'},
         arr2[6] = {'5', '3', '7', '1', '9', '3'};
    int result[7] = {0};
    summ(arr1, arr2, result);
    for (int i = 0; i < 6; i++)
        cout << arr1[i];
    cout << " + ";
    for (int i = 0; i < 6; i++)
        cout << arr2[i];
    cout << " = ";
    for (int i = result[0] == 0 ? 1 : 0; i < 7; i++)
        cout << result[i];
    cout << endl;
    return 0;
}