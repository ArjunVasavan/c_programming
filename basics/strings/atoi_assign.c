#include <stdio.h>

int my_atoi(const char str[])
{
    int i = 0;
    int num = 0;

    if ( (str[0] == '+' || str[0] == '-'))
    {
        i+=1;
    }

    
    while ( (str[i] >= 48 &&  str[i] <= 57) && str[i] )
    { 
         num = (num * 10) + str[i] - 48;
         i+=1; 
    }

    return num;
}

int main()
{
    char str[20];
    
    printf("Enter a numeric string : ");
    scanf("%s", str);
    
    printf("String to integer is %d\n", my_atoi(str));
}
