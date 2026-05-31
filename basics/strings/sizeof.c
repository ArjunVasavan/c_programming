#include <stdio.h>

int main()
{
    char str[20];

    scanf("%[^\n]",str);

    int i = 0 , count = 0;

    while ( str[i] )
    {
        count+=1;
        i+=1;

    }

    printf("length of the string --> %d",count);
}

