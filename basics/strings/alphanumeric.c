#include <stdio.h>

int check ( char* str )
{
    int i =0 ;

    int count = 0;

    while ( str[i] )
    {
        if ( str[i] >= 48 || str[i] <= 57 || str[i] >= 65 || str[i] <= 90 || str[i] >= 97 || str[i] <= 122 )
        {
            count+=1;
        }

        i+=1;
    }

    return count;
}

int main()
{
    char str[50];

    printf("Enter the character --> ");
    scanf("%[^\n]",str);

    printf("Total Number of Alpha numeric character --> %d\n",check(str));
}

