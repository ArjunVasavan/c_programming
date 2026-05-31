#include <stdio.h>

void fun( char str[] )
{
    int i = 1;

    printf("%c",str[0]);
    while ( str[i] )
    {
        if ( str[i] == ' ' )
        {
            printf(" ");
        }
        if (( (str[i] != ' ') && (str[i+1] == ' ' || str[i+1] == '\0' )) || ((str[i-1] == ' ' && str[i] !=' ')) )
        {
            printf("%c",str[i]);
        }

        i+=1;
    }

    printf("\n");
}

int main()
{
    char str[100];
    printf("Enter the string : ");
    scanf("%[^\n]",str);

    fun(str);
}

