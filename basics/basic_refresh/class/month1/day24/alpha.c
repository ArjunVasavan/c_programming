#include <stdio.h>
int check (char ch)
{
    if ( ch >= 'A' && ch <= 'Z' )
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
        printf("Its an Capital Letter");
    }
    else
    {
        printf("Its Small Letter");
    }
}

