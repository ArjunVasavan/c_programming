#include <stdio.h>

int main()
{
    int n;

    printf("Enter array size : ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter each elements : ");

    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",&arr[i]);
    }

    int count = 0;
    for ( int i = 0 ; i < n ; i ++ )
    {
        if ( i % 2 != 0 )
        {
            count+=1;
        }

    }

    int arr2[count];

    int c = 0;

    for ( int i = 0 ; i < n ; i++ )
    {

        if ( i % 2 != 0 )
        {
            arr2[c] = arr[i];
            c+=1;
        }

    }

    for ( int i = 0 ; i < count ; i++ )
    {
        printf("%d ",arr2[i]);
    }
}

