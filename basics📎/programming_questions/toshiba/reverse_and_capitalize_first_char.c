#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

// Reverse words
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

// Capitalize first character of each word
void capitalize_words(char *str)
{
    int new_word = 1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            new_word = 1;
        }
        else
        {
            if (new_word)
            {
                str[i] = toupper(str[i]);
                new_word = 0;
            }
            else
            {
                str[i] = tolower(str[i]);
            }
        }
    }
}

int main()
{
    char str[] = "i love c programming";

    reverse_words(str);
    capitalize_words(str);

    printf("%s\n", str);

    return 0;
}
