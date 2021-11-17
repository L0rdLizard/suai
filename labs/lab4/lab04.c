#include <stdio.h>

//Ввести строку. Вывести слова в алфавитном порядке.

void sort_words(char *words[], int count)
{
    char *x;

    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if ((char)(*words[i]) < (char)(*words[j]))
            {
                x = words[j];
                words[j] = words[i];
                words[i] = x;
            }
        }
    }
}

int main()
{
    char *words[] = { "cherry", "orange", "apple" };    
    int count = 0;
    //fgets(words, 101, stdin);
    sort_words(words, count);
    print("%c", words);
    return 0;
}
