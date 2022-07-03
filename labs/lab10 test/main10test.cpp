#include <stdio.h>
#include <string.h>
 
int Search(char line[], char word[])
{
    char *p, *start;
    int count = 0;
    start = line;
        while(1){
            p = strstr(start, word);
            if(p == NULL)break;
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
    fp = fopen("f1.txt", "r");
    char* a = "for";
    while(fgets(s, 128, fp)){
        nf += Search(s, a);
        // nw += Search(s, "while");
        // nd += Search(s, "do");
        // ni += Search(s, "if");
    }
    fclose(fp);
    puts("File f1 has words:");
    printf("'for' %d times,\n'while' %d times,\n'do' %d times,\n and 'if' %d times.\n", nf, nw, nd, ni);
    return 0;
}
