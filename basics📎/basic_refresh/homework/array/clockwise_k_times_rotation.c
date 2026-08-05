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
    int itemp = 0;

    while(k != 0)
    {
        temp = arr[n-1];
        for ( int i = n-1 ; i > 0  ; i-- )
        {
            arr[i] = arr[i-1];

        }
        arr[0] = temp;
        k-=1;
    }

    printf("Result = \n");
    for ( int i = 0 ; i < n ; i++ )
    {
        printf("%d ",arr[i]);
    }
}
