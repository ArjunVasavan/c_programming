#include <stdio.h>
int check (char ch)
{
    if ( ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z'|| ch >= '0' && ch <= '9' )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    char c;
    printf("Enter an character only : ");
    scanf("%c",&c);

    if( check(c) )
    {
        printf("Its an Punctual !\n");
    }
    else
    {
        printf("Its not an Punctual \n");
    }
}

