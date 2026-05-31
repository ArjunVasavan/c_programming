#include <stdio.h>

int dist( char* str )
{
    int flag = 1;
    int i = 0;

    while ( str[i] )
    {
        int j = i + 1;

        while ( str[j] )
        {
            if ( str[i] == str[j] )
            {
                flag = 0;
                break;
            }
            j+=1;
        }

        i+=1;
    }
    
    return flag;
}
int main()
{
    char str[100];

    printf("Enter the string=> ");
    scanf("%[^\n]",str);

    if ( dist(str) )
    {
        printf("its an distinct element\n");
    }
    else
    {
        printf("its not an distinct element\n");
    }
}

