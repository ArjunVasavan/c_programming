#include<stdio.h>

int main()
{
    int n;

    printf("Enter 'n' value : ");
    scanf("%d",&n);

    for (int i = 0 ; i < n ; i++)
    {
        for ( int j = 0 ; j < (n - i - 1) ; j++ )
        {
            printf(" ");
        }
        
            printf("*");

        if ( i > 0 && i < n - 1 )
        {
            for ( int k = 0 ; k < 2*i - 1 ; k++ )
            {
                printf(" ");
            }

                printf("*");
        }

        else if ( i == n -1 )
        {
            for ( int l = 0 ; l < i ; l++ )
            {
                printf(" *");
            }
        }

        printf("\n");

    }
}
