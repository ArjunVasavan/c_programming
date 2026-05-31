#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "I love C programming";

    char words[50][50];   // store words
    int word_count = 0;
    int i = 0, j = 0;

    // Step 1: Split words
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            words[word_count][j++] = str[i];
        }
        else
        {
            words[word_count][j] = '\0';
            word_count++;
            j = 0;
        }
        i++;
    }

    // store last word
    words[word_count][j] = '\0';
    word_count++;

    // Step 2: Print in reverse order
    for (int k = word_count - 1; k >= 0; k--)
    {
        printf("%s ", words[k]);
    }

    return 0;
}
