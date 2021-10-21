 #include <stdio.h>
int is_char(int ch)
{
    if (
        (65 <= ch && ch <= 90) || (97 <= ch && ch <= 122) ||
        (128 <= ch && ch <= 175) || (224 <= ch && ch <= 239))
        return 1;
    else
        return 0;
}

int main()
{
    int user_count, count;
    int start = -1, end = -1;
    char str[101] = {0};
    fgets(str, 101, stdin);
    scanf_s("%d", &user_count);

    for (int i = 0; i < 101; i++)
    {
        if (is_char(str[i]) == 1)
        {
            if (start == -1)
                start = i;
            if (i == 100)
                end = i;
        }
        else
        {
            if (end == -1 && start != -1)
                end = i - 1;
        }
        if ((start != -1) && (end != -1))
        {
            if ((user_count - 1) == (end - start))
            {
                for (int i = start; i <= end; i++)
                    printf("%c", str[i]);
                printf("\n");
            }
            end = -1;
            start = -1;
        }
    }
    return 0;
} 