#include<stdio.h>

int main()
{
    int n;

    printf("Enter Array Size : ");

    scanf("%d",&n);

    int  arr[n];

    int arr2[n];

    printf("Enter the elements : ");
    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",& arr[i]);

        arr2[i] = arr[i];

    }

    printf("Array 2 Elements stored are ==>");

    for ( int i  = 0 ; i < n ; i++ )
    {
        printf("%d",arr2[i]);
    }



}

