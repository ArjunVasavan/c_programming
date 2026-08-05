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

    int smallest = arr[0];

    for ( int i = 1 ; i < n ; i++ )
    {
        if (smallest >  arr [i])
        {

            smallest = arr[i];

        }
    }

    printf("The smallest  element is |> : %d",smallest);
}
