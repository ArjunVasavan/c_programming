#include<stdio.h>

int main()
{
    int n = 5;

    for ( int i = 1 ; i <= n ; i++ )
    {

        for (int j = 1 ; j<= n ; j++)
        {
            if ( i >= j ){


                if ( j == 1 || j == i)
                {
                    printf("%d",j);
                }
                else
                {
                    printf(" ");
                }
            }


        }
            printf("\n");
    }
}

