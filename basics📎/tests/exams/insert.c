#include <stdio.h>
/* this code to insert an value without using second array (unsorted) */
int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements : ");
    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the Value : ");
    int val;
    scanf("%d",&val);

    printf("Enter the position : ");
    int pos;
    scanf("%d",&pos);

    if ( pos < 1 || pos > n )
    {
        printf("Invalid\n");
    }

    for ( int i = 0 ; i < n ; i ++ )
    {
        if ( pos == i )
        {
            printf("%d ",val);
        }

        printf("%d ",arr[i]);
    }

    printf("\n");


}

