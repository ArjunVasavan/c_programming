#include <stdio.h>

int main()
{
    printf("Enter the string (To stop use ctrl + D) =>> \n");
    char ch;
    int wordcount = 0;
    int linecount = 0;
    int charactercount = 0;
    int inWord = 0;  // Flag to track if we're inside a word
    
    while ((ch = getchar()) != EOF)
    {
        charactercount++;
        
        if (ch == '\n')
        {
            linecount++;
        }
        
        // Check if current character is whitespace
        if (ch == ' ' || ch == '\t' || ch == '\n')
        {
            if (inWord)
            {
                wordcount++;
                inWord = 0;
            }
        }
        else
        {
            inWord = 1;  // We're in a word
        }
    }
    
    // Count the last word if input doesn't end with whitespace
    if (inWord)
    {
        wordcount++;
    }
    
    printf("\nWORDS => %d\nLINES => %d\nCHARACTERS => %d\n", 
           wordcount, linecount, charactercount);
    
    return 0;
}
