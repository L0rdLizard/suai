//Подсчитать частоту появления каждого ключевого слова языка С в символьном файле с программой на С.
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int len(char *str)
{
    int count = 0;
    while (1)
    {
        if (str[count] == NULL)
            break;
        count++;
    }
    return count;
}

int Search(char *line, char *word)
{
    char *p, *start;
    int count = 0;
    int lenght = len(word);
    start = line;
    while (1)
    {
        p = strstr(start, word);
        if (p == NULL)
            break;
        count++;
        start = p + lenght;
    }
    return count;
}

int main()
{
    int sizew = 30;
    char *words[] = {"auto", "continue", "else", "for", "long", "signed", "switch", "void", "break", "default", "enum", "goto", "register", "sizeof", "typedef", "while", "case", "do", "extern", "if", "return", "static", "union", "char", "double", "float", "int", "short", "struct", "unsigned"};
    int countw[30] = {0};

    int nf = 0, nw = 0, nd = 0, ni = 0;
    char s[128];
    FILE *fp;

    if ((fp = fopen("labs/lab10/f1.txt", "r")) == NULL)
    {
        printf("Cannot open file.\n");
        exit(1);
    }

    fp = fopen("labs/lab10/f1.txt", "r");
    while (fgets(s, 128, fp))
    {
        for (int i = 0; i < 30; i++)
        {
            countw[i] += Search(s, words[i]);
        }
    }

    fclose(fp);

    for (int i = 0; i < 30; i++)
    {
        cout << words[i] << " = " << countw[i] << endl;
    }
    return 0;
}