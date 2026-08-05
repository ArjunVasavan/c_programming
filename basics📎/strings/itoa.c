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

    /* char sub[100]; */
    int rev = 0;
    while(num != 0)
    {
        int rem = num % 10;
        rev= rev*10+ rem;
        num/=10;
    }

    int i = 0;
    while ( rev != 0 )
    {
        int rem = rev % 10;
        str[i] = rem+48;
        rev/=10;
        i+=1;
    }

    str[i] = '\0';
    
}

