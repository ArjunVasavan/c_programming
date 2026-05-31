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
        scanf("%d",&  arr[i]);
    }

    int find;

    int i = 0;

    printf("Enter the Element You need to find : ");
    scanf("%d",&find);

    int flag = 0;

    for ( i =0 ; i < n ; i++ )
    {
        if ( find == arr[i] )
        {
            flag =1;
            break;
        }
    }

    if( flag == 1 )
    {
        printf("Element has been founded at arr[%d] = %d",i,find);
    }
    else
    {
        printf("Element has not been Founded");

    }
}
