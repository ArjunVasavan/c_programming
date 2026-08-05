#include <stdio.h>
int main ()
{
    int n ;

    printf("Enter n vale : ");

    scanf("%d",&n);
    if (n % 2 != 0)
    {
        for ( int i = 1; i <= n ; i++ )
        {
            for ( int j= 1; j <= n ; j++ )
            {
                if ( i == 1 || i == n )
                {
                    printf("* ");
                }
                else if ( j == 1 || j == n )
                {
                    printf("* ");
                }
                else if ( i ==  ((n / 2 ) + 1 ) && j == ((n / 2) + 1))
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }

            printf("\n");
        }

    }
    else
    {
        printf("Enter odd number only \n");
    }

}
