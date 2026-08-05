#include <stdio.h>

int main ()
{
    int n;

    printf("Enter the array size : ");
    scanf("%d",&n);

    int arr1[n];

    int arr2[n];

    printf("Enter the array 1  elements : ");

    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",& arr1[i]);
    
    }

    printf("Enter the array 2  elements : ");

    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",& arr2[i]);
    }


    for ( int i = 0 ; i < n ; i ++ )
    {
        int iflag = 0;

        int jflag = 0;

        for ( int j = 0 ; j < n ; j++ )
        {
            if (arr1[i] == arr2[j])
            {
                iflag = 1;
            }
            if (arr2[i] == arr1[j])
            {
                jflag = 1;
            }
        }

        if ( iflag != 1 )
        {
            printf("%d ",arr1[i]);
        }

        if ( jflag != 1 )
        {
            printf("%d ",arr2[i]);
        }
    
    }

    printf("\n");

}
