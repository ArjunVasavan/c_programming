#include<stdio.h>

int main ()
{
    int n = 5;

    for ( int i = 1 ; i <= 5 ; i++ )
    {
        for ( int j = 1 ; j <= ( n - i ) ; j++ )
        {
            printf(" ");
        }
        for (int k = 1 ; k <= i ; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
