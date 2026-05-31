#include <stdio.h>

void itoa(int num, char str[]);

int main()
{
    int num;
    char str[10];
    
    printf("Enter the number:");
    scanf("%d", &num);
    
    itoa(num, str);
    
    printf("Integer to string is %s", str);
}

void itoa( int num , char str[] )
{   

    int i = 0;

    if ( num < 0 )
    {
        str[i] = '-';
        i+=1;
        num*=-1;
    }
    /* char sub[100]; */
    int rev = 0;
    while(num != 0)
    {
        int rem = num % 10;
        rev= rev*10+ rem;
        num/=10;
    }

    while ( rev != 0 )
    {
        int rem = rev % 10;
        str[i] = rem+48;
        rev/=10;
        i+=1;
    }

    str[i] = '\0';
    
}

