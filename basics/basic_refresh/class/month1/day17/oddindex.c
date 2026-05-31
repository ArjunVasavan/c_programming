#include <stdio.h>
int main ()
{
    int n;

    printf("Enter element size : ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter elements : ");

    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",&arr[i]);
    }

    printf("Elements are : ");

    for ( int i = 0 ; i < n ; i++ )
    {
        if ( i % 2 != 0 )
        {
            printf("%d ",arr[i]);
        }
    }
}
