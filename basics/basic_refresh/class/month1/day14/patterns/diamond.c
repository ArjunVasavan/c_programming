#include <stdio.h>

int main()
{
    int n;

    printf("Enter an Number : ");
    scanf("%d",&n);

    for ( int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= (n-i) ; j++ )
        {
            printf(" ");
        }
        for (int k = 1 ; k <= i ; k++)
        {
            printf("* ");
        }
        printf("\n");
    }

    n = n-1;

    for ( int i = 1; i <= n ; i++ )
    {
        for (int j = 1 ; j <= i ; j++)
        {
            printf(" ");
        }
        for (int k = 1 ; k <= (n-i+1) ; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
