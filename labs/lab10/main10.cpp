//Подсчитать частоту появления каждого ключевого слова языка С в символьном файле с программой на С.
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int Search(char* line, char* word)
{
    char *p, *start;
    int count = 0;
    start = line;
    while (1)
    {
        p = strstr(start, word);
        if (p == NULL)
            break;
        count++;
        start = p + strlen(word);
    }
    return count;
}

int main()
{
    // int sizew = 30;
    // char *words[] = {"auto", "continue", "else", "for", "long", "signed", "switch", "void", "break", "default", "enum", "goto", "register", "sizeof", "typedef", "while", "case", "do", "extern", "if", "return", "static", "union", "char", "double", "float", "int", "short", "struct", "unsigned"};
    // int countw[30] = {0};
    // cout << words[1] << endl;
    // char* a = "auto";
    // char* b = "abc";
    // cout << a << endl;
    // int razn = strcmp(a, words[0]);
    // cout << razn << endl;
    // cout << words[29] << endl;
    // cout << countw[29] << endl;
    // cout << sizeof(words) / 4 << endl;

    int nf = 0, nw = 0, nd = 0, ni = 0;
    char s[128];
    FILE *fp;
    fp = fopen("f1.txt", "r");
    while (fgets(s, 128, fp))
    {
        nf += Search(s, "for");
        nw += Search(s, "while");
        nd += Search(s, "do");
        ni += Search(s, "if");
    }
    fclose(fp);
    puts("File f1 has words:");
    printf("'for' %d times,\n'while' %d times,\n'do' %d times,\n and 'if' %d times.\n", nf, nw, nd, ni);
    return 0;
}