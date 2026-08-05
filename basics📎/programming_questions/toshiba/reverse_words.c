#include <stdio.h>
#include <string.h>

// Reverse characters between two pointers
void reverse(char *start, char *end)
{
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverse_words(char *str)
{
    int len = strlen(str);

    // Step 1: Reverse entire string
    reverse(str, str + len - 1);

    // Step 2: Reverse each word
    char *word_start = str;

    for (int i = 0; i <= len; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            reverse(word_start, str + i - 1);
            word_start = str + i + 1;
        }
    }
}

int main()
{
    char str[] = "I love C programming";

    reverse_words(str);

    printf("%s\n", str);

    return 0;
}
