#include <stdio.h>

int main()
{
    int n ;
    printf("Enter the size : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements : ");
    for ( int i = 0 ; i < n ;i++)
    {
        scanf("%d",&arr[i]);
    }
    int k = 1;

    printf("Enter K times of rotation :  ");
    scanf("%d",&k);
    
    int temp = 0;

    while(k != 0)
    {
        temp = arr[0];
        for ( int i = 0 ; i < n  ; i++ )
        {
            arr[i] = arr[i+1];

        }
        arr[n-1] = temp;
        k-=1;
    }

    printf("Result = \n");
    for ( int i = 0 ; i < n ; i++ )
    {
        printf("%d ",arr[i]);
    }
}
