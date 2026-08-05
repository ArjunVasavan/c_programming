#include <stdio.h>

char* strrev(char* str)
{
    int i = 0;

    while ( str[i] )
    {
        i+=1;
    }

    int end = i-1;

    int start = 0;

    while ( start < end )
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start+=1;
        end-=1;
    }

    return str;
}

int main()
{
    printf("Enter thE STRING->");
    char str[50];

    scanf("%[^\n]",str);

    printf("Result is --> %s\n",strrev(str));
}

