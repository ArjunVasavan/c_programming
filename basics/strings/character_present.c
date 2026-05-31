#include <stdio.h>

void check ( char* str )
{
    int i = 0;

    int flag = 0;

    while ( str[i] )
    {
        if ( str[i] >= 65 && str[i] <= 90 || str[i] >= 97 &&  str[i] <= 122 )
        {
            flag = 1;

            break;
        }

        i+=1;
    }

    if ( flag ==1  )
    {
        printf("Character is Present\n");
    }
    else
    {
        printf("Character is not present\n");
    }
}

int main()
{
    char str[50];

    printf("Enter the string --> ");
    scanf("%[^\n]",str);

    check ( str );
}

