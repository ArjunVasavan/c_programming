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

    for ( int i = 0 ; i < n/2 ; i++ )
    {

        temp = arr[i];

        arr[i] = arr[n- i - 1];
        
        arr[n-i-1] =temp;

    
    }



    printf("Enter Reversed  elements : ");

    for ( int i = 0 ; i < n ; i++ )
    {
        printf("%d ", arr[i]);
    }

}
