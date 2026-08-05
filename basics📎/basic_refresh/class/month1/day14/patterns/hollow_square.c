#include <stdio.h>

int main()
{
    int n;

    printf("Enter N vale : ");

    scanf ("%d",&n);

    for (int i = 1 ; i<= n ; i++)
    {
        for (int j = 1 ; j <= n ; j ++)
        {
            if ( i == 1 )
            {
                printf ("* ");
            }
            else if ( i == n )
            {
                printf("* ");
            }
            else if ( j == 1 )
            {
                printf("* ");
            }
            else if (j== n)
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
