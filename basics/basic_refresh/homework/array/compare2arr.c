#include <stdio.h>

int main ()
{
    int n;

    int i = 0;

    printf("Enter array 1 and array 2 size : ");
    scanf("%d",&n);

    int arr1[n];
    int arr2[n];


    printf("Enter elements for array 1  ");
    for  ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",& arr1[i]);
        
    }
    printf("Enter elements for array 2  ");
    for  ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",& arr2[i]);
        
    }

    for (  i = 0 ; i < n ; i++ )
    {
       if ( arr1[i] != arr2[i] ){


                break;
            }

    }
    

    if ( i == n  )
    {

        printf("Element is Equal! \n");

    }
    else
    {
        printf("Element is not equal! \n");
    }

}
