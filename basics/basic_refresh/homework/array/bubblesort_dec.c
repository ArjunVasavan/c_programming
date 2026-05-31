#include <stdio.h>

int main ()
{
    int n;

    printf("Enter the array size : ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the array elements : ");

    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",& arr[i]);
    }
    int temp = 0;
    for ( int i = 0 ; i < n / 2 ; i++ )
    {
        for ( int j = 0 ; j < n - i - 1 ; j++ )
        {
            if ( arr[j] <  arr[j+1] )
            {

                temp = arr[i];

                arr[i] = arr[n - i - 1];

                arr[n - i - 1] = temp;

            }
        
        }

    }
        printf("Enter the array elements : ");

        for ( int i = 0 ; i < n ; i++ )
        {
            printf("%d ", arr[i]);
        }
}
