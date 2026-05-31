#include <stdio.h>

int main ()
{
    int n = 5;
    

    printf("Enter an Number : ");

    scanf("%d",&n);

    int odd = 0;
    int even;
    int temp;

    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= n ; j++ )
        {

            if ( i %2 != 0 )
            {
                odd++;

                printf("%d ",odd);

                if(i == 1 )
                {
                    printf(" ");
                }

              even = n + odd;

              temp = even;
            }
            else
            {

                printf("%d ",even);


                even--;

            }

        }

        odd = temp;

        printf("\n");
    }
}
