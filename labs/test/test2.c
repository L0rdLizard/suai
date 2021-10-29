#include<stdio.h>
int main() 
{
    int i, j, k, c[2002], a[1001], b[1001];
    int na, mb; 
    scanf("%d %d", &na, &mb); 
    for (i=0; i<na; i++)
    {
        scanf("%d", &a[i]); 
    }
    for (i=0; i<mb; i++)
    {
        scanf("%d", &b[i]);
    }
    i=0;j=0;k=0;
    while(i<na && j<mb)
    {
        if (a[i] < b[j]) 
            c[k++]=a[i++];
        else 
            c[k++]=b[j++]; 
    }
    while(i<na)
        c[k++]=a[i++];
    while(j<mb)
        c[k++]=b[j++]; 
 
    for (i=0; i<k; i++) 
    {
        printf(" %d", c[i]); 
    }
    return 0;
}