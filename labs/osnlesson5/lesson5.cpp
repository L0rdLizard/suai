#include <iostream>
#include <math.h>
#define N 9
#define D 3

using namespace std;

unsigned long long count_ones(unsigned long long n) {
    unsigned char w = 0;
    while (n > 0) {
        w += n & 1;
        n = n >> 1;
    }
    return w;
}

int main()
{
    int M = 0;
    int size = pow(2, N);
    int mark[size] = { 0 };
    int CodeBook[size] = { 0 };

    int zero = 0;
    
    while (zero<size)
    { 
        CodeBook[M] = zero;
        mark[zero] = 2;
        M++;

        for (int i = 0; i < size;i++)
        {
            if (mark[i] == 0 && (count_ones(i ^ CodeBook[M - 1]) < D))
            {
                mark[i] = 1;

            }
            cout << mark[i] << " ";
        }
        for (zero = 0; (mark[zero] != 0 && zero<size); zero++);
        cout << endl;
    }

    cout << "Answers: ";
    int counter = 0;
    for (size_t i = 0; i < M; i++){ 
        cout << CodeBook[i] << " ";
        counter++;    
    }
    cout << endl;
    cout << counter;
    return 0;
}