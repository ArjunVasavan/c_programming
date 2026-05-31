#include<stdio.h>
int main()
{
    int n;

    printf("Enter an Number : ");

    scanf("%d",&n);
    
    n = n+1;

    int i,j;

        for( i = 2 ; i <= n ; i++ )

        {

            for (j = 2 ; j*j <= i ; j++)
            {
                if(i%j == 0)

                {
                    break;
                }
            }



        }

            if (j*j > i )
            {
                printf("%d ",i);
            }
}
