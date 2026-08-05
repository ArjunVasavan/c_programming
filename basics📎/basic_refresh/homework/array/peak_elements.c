#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size : ");
    scanf("%d",&n);

    int arr[n];

    printf("enter the array elements : ");
    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",&arr[i]);
    }
    for(int i = 0 ; i < n ; i++)
    {
        if ( i == 0 )
        {
            if (arr[i] >= arr[i+1])
            {
                printf("%d ",arr[i]);
                
            }
            continue;

        }
    if (i == n-1)
        {
            if (arr[i] >= arr[i-1])
            {
                printf("%d ",arr[i]);
            }
        continue;
        }
    if (arr[i] >=  arr[i+1] && arr[i] >=  arr[i - 1])
        {
                printf("%d ",arr[i]);
        }
    }

}

