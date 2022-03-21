#include <iostream>
using namespace std;

void cn(int n, int k, int *mass){
    if (n == 1) mass[n*57+k] = 1;
    else if (k == n || k == 1) mass[n*57+k] = 1;
    else mass[n*57+k] = mass[(n-1)*57+k]+mass[(n-1)*57+k+1];
}

int main(){
    int mass[57*57] = {0};
    for (int i = 0; i <= 57; i++){
        cn(57, i, mass);
    }
    for (int i = 0; i <= 57; i++){
        cout << mass[57*56+i] << endl;
    }
}