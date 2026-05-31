#include<stdio.h>

int main ()
{
    int min;
    int n ;
    
    printf("Enter n value : ");
    scanf("%d",&n);

    int len = (2*n)- 1 ;
    for ( int i = 0 ; i < len ; i++ )
    {
        for ( int j = 0  ; j < len ; j++)
        {
            int upwards = i ;

            int left = j ;

            int right = len - j - 1;

            int bottom = len - i - 1;

            min = upwards ;

            if ( left < min )
            {
                min = left ;
            }
            if ( right < min  )
            {
                min = right ;
            }
            if ( bottom < min )
            {
                min = bottom ;
            }

            printf("%d ", n - min);
        }

        printf("\n");
    }
}
