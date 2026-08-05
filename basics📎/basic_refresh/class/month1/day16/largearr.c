#include <stdio.h>

int main ()
{
    int l;
     
    int sum = 0;

    int large;

    printf("Enter the size of array : ");

    scanf("%d",&l);
    int arr[l];

    large = arr[0];

    printf("\n");
    
    printf("Enter an Number : ");

    for ( int i =0 ; i < l ; i++ )
    {
    scanf("%d",&arr[i]);
    }

    printf("\n");

    for ( int i =0 ; i < l ; i++ )
    {
    printf("arr[%d] values are :  %d \n",i,arr[i]);
    }

    for ( int i = 1 ; i < l ; i++ )
    {
        if ( arr [0] < arr[i] )
        {

            arr[0] = arr[i];

        }
            
    }

    printf("Largest is = %d \n",arr[0]);

}
