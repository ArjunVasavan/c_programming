#include<stdio.h>

int main()
{
    int n = 5;
    for ( int i =1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= n ; j++ )
        {
            if ( i == 1 )
            {
                printf ("1");
            }
            else if (i > 1 && i <= n && j == 1)
            {
                printf("2");
            }
            else if ( j == n && i != n )
            {
                printf("4");
            }
            else if ( i == n && j >= 2 && j <= n )
            {
                printf("3");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }
}
