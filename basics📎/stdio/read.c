/*
-------------------------------------------------------------------------------
Name        : Arjun Vasavan

Date        : 28 - 10 2025

Description :Program to count characters, words and lines,entered through stdin

Sample execution: -

Test Case 1:

Hello world
Dennis Ritchie
Linux
Character count : 33
Line count : 3
Word count : 5

Test Case 2:

Hello         world
Dennis    Ritchie
Linux
Character count : 39
Line count : 3
Word count : 5


-------------------------------------------------------------------------------
*/

#include <stdio.h>
void wc_count(int* char_count,int* line_count,int* word_count)
{
    int ch;
    int inside = 0; 
    while((ch = getchar()) != EOF)
    {
        (*char_count)++;
        
        if(ch == '\n')
        {
            (*line_count)++;
        }
        
        if(ch == ' ' || ch == '\n' || ch == '\t')
        {
            inside = 0; 
        }
        else
        {
            if(inside == 0)
            {
                (*word_count)++;
                inside = 1;
            }
        }
    }

}
int main()
{
    int char_count = 0;
    int line_count = 0;
    int word_count = 0;
    
    wc_count(&char_count,&line_count,&word_count);
    
    printf("Character count : %d\n", char_count);
    printf("Line count : %d\n", line_count);
    printf("Word count : %d\n", word_count);
    
    return 0;
}
