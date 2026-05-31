#include <stdio.h>

void pal ( char* str )
{
    int i = 0;
    while ( str[i] )
    {
        i+=1;
    }
    int flag = 1;

    int n = i-1;

    for ( int c = 0 ; c <= (n/2) ; c++ )
    {
        if ( str[c] != str[n-c])
        {
            flag = 0;
            break;
        }
    }

    if ( flag == 1 )
    {
        printf("Its an Palindrome \n");
    }
    else
    {
        printf("Its not an palindrome\n");
    }
}

int main()
{
    char str[60];
    printf("Enter The String -> ");
    scanf("%[^\n]",str);

    pal(str);

}


