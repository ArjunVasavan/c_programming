#include <stdio.h>

void word( char* str )
{
    int i = 0;
    int    first = -1;
    while ( str[i] )
    {
        if ( str[i] != ' ' && first == -1 )
        {
            first = i;
        }
        if (  str[i] != ' ' && ( str[i+1] == ' ' || str[i+1] == '\0'))
        {
          int   last = i;

          printf("first => %d and last %d \n",first,last);

          first = -1;
        }
        i+=1;
    }
}

int main()
{
    char str[50];
    printf("Enter the string==> ");
    scanf("%[^\n]",str);

    word(str);
}

