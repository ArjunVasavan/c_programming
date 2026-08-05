#include <stdio.h>

void rev ( char* str , int start , int last )
{
    while ( start <= last )
    {
        int temp = str[start];

        str[start] = str[last];

        str[last] = temp;

        start+=1;
        last-=1;
    }
}

void word( char* str )
{
    int i = 0;

    while ( str[i] )
    {
        i+=1;
    }

    int start = 0;
    int last = i - 1;

    while ( start <= last )
    {
        int temp = str[start];
        str[start] = str[last];
        str[last] = temp;
        start+=1;
        last-=1;
    }

    str[i] = '\0';
    
    i = 0;

    int first = -1;

    while ( str[i] )
    {
        if ( str[i] != ' ' && first == -1)
        {
            first = i;
        }

        if ( str[i] != ' ' && (str[i+1] == '\0' || str[i+1] == ' ') )
        {
            int last = i;

            rev(str,first,last);

            first = -1;
        }

        i+=1;
    }
}

int main()
{
    char str[50];
    printf("Enter the string => ");
    scanf("%[^\n]",str);

    word(str);

    printf("%s\n",str);
}

