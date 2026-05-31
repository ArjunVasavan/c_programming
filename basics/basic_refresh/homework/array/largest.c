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

    int largest = arr[0];

    for ( int i = 1 ; i < n ; i++ )
    {
        if (largest < arr [i])
        {

            largest = arr[i];

        }
    }

    printf("The largest element is |> : %d",largest);
}
