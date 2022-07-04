#include <stdio.h>
// #include <string.h>
#include <cstring>
#include <stdlib.h>

int Search(char line[], char word[])
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
    int nf = 0, nw = 0, nd = 0, ni = 0;
    char s[128];
    FILE *fp;
    if ((fp = fopen("file.txt", "r")) == NULL)
    {
        printf("Cannot open file.\n");
        exit(1);
    }
    fp = fopen("file.txt", "r");
    char *a = "for";

    // while (fgets(s, 128, fp) != NULL)
    // {
    //     nf += Search(s, a);
    //     nw += Search(s, "while");
    //     nd += Search(s, "do");
    //     ni += Search(s, "if");
    // }
    // while (!feof(fp))
    // {
    //     if (fgets(s, 128, fp))
    //         nf += Search(s, a);
    // }

    // fclose(fp);
    if (fgets(s, 128, fp))
    {
        nf += Search(s, "for");
    }
    puts("File f1 has words:");
    printf("'for' %d times,\n'while' %d times,\n'do' %d times,\n'if' %d times.\n", nf, nw, nd, ni);
    return 0;
}
