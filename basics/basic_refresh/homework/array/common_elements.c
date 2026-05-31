#include <stdio.h>

int main ()
{
    int n;

    printf("Enter the array size : ");
    scanf("%d",&n);

    int arr1[n];

    int arr2[n];

    printf("Enter the array 1 elements : ");

    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",& arr1[i]);
    }

    printf("Enter the array 2 elements : ");

    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",& arr2[i]);
    }

    printf("Common Elements Founded are >>-> ");


    for ( int i = 0 ; i < n ; i++ )
    {
        int present = 0;

        int common = 0;


        for ( int k = 0 ; k < i ; k++ )
        {
            if ( arr1[i] == arr1[k] )
            {
                present = 1;
            }
        }

        if ( present != 1 )
        {
            for (int j = 0 ; j < n ; j++)
            {
                if ( arr1[i] == arr2[j] )
                {
                    common = 1;

                    break;
                }
            }


        }

        if ( common == 1 )
        {
            printf("%d ",arr1[i]);
        }
    }


}
