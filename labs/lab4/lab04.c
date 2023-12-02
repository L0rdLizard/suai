#include <stdio.h>

//Ввести строку. Вывести слова в алфавитном порядке.

void sort_words(char *words[], int count)
{
    char *x;

    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if ((char)(*words[i]) > (char)(*words[j]))
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
    int count = 3;
    //fgets(words, 101, stdin);
    sort_words(words, count);
    // printf("%c", words);
    printf("%s", words[0]);
    printf("%s", words[1]);
    printf("%s", words[2]);
    // printf("apple cherry orange");
    return 0;
}

// Ребята я грустный туалет 

