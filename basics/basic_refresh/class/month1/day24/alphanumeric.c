#include <stdio.h>
int check (char ch)
{
    if ( ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z'|| ch >= '0' && ch <= '9' )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char c;
    printf("Enter an character only : ");
    scanf("%c",&c);

    if( check(c) )
    {
        printf("Its an Alphanumeric !\n");
    }
    else
    {
        printf("Its not an Alphanumeric \n");
    }
}

