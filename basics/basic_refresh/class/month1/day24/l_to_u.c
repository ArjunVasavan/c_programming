#include <stdio.h>
int check (char ch)
{
    if ( ch >= 'a' && ch <= 'z' )
    {
        return ch - 32;
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

    if ( check(c) != 0 )
    {
        printf("%c \n",check(c));
    }
    else
    {
        printf("%c \n",c);
    }

}

