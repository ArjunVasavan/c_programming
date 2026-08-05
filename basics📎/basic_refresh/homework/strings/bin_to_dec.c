#include <stdio.h>

int power ( int n )
{
    int mul = 1;
    for ( int i = 1 ; i<= n ; i++ )
    {
        mul*=2;
    }

    return mul;
}

int bintodec(char* str)
{
    int i = 0;
    while ( str[i] )
    {
        i+=1;
    }

    int n = i-1;

    i = 0;

    int sum = 0;

    while ( str[i] )
    {
        if ( str[i] == 49 )
        {
            sum+=power(n-i);
        }

        i+=1;
    }

    return sum;
}

int main()
{
    char str[60];
    printf("Enter The String -> ");
    scanf("%[^\n]",str);

    printf("The binary conversion of %s is %d \n",str,bintodec(str));

}


