#include <stdio.h>
#include <stdlib.h>


int main()
{
    long long mas[53][53] = { 1 };
	for (int i = 1; i < 53; i++)
	{
		for (int k = 0; k < 53; k++)
		{
			if (k == 0)
				mas[i][k] = mas[i - 1][k];
			else mas[i][k] = mas[i - 1][k - 1] + mas[i - 1][k];
		}
	}
	for (int i = 0; i <= 52; i++)
	{
		printf("%d -- %d\n", i, mas[52][i]);
	}
}