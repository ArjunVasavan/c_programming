#include <stdio.h>

int main ()
{
    int l;
     
    int sum = 0;

    printf("Enter the size of array : ");

    scanf("%d",&l);
    int arr[l];

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

    for ( int i = 0 ; i < l ; i++ )
    {
        sum+=arr[i];
    }

    printf("sum is = %d \n",sum);

}
