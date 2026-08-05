#include <stdio.h>

int fun(char* str)
{
    int sum = 0;
    int i = 0;

    while ( str[i] )
    {
        if ( str[i] >= 48 && str[i] <= 57 )
        {
            sum+=(str[i] - 48);
        }
        i+=1;
    }

    return sum;
}

int main()
{
    char str[100];
    printf("Enter the string : ");
    scanf("%[^\n]",str);
    
    printf("sum is %d",fun(str));
}

