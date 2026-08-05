#include <stdio.h>

int main ()
{
    int n;

    printf("Enter the array size : ");
    scanf("%d",&n);

    int arr[n];

    int sum = 0;

    printf("Enter the array elements : ");

    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",& arr[i]);

        sum+=arr[i];
    }

    float avg = ((float) sum) / n;

    printf("Sum is |> %d \n Average is |> %g \n",sum,avg);
    



}
