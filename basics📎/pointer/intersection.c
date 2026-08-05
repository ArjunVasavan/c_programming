#include <stdio.h>

void read ( int n , int arr[] )
{
    printf("Enter the elements : --> ");

    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",&arr[i]);
    }
}

void write ( int n , int arr[] )
{

    for ( int i = 0 ; i < n ; i++ )
    {
        printf("%d ",arr[i]);
    }

    printf("\n");
}


void intersection (int n1 , int arr1[] , int n2 , int arr2[] , int* n3 , int arr3[])
{

    for ( int i = 0; i < n1 ; i++ )
    {
        int dup = 0;

        for ( int k = 0 ; k < *n3 ; k++ )
        {
            if ( arr1[i] == arr3[k] )
            {
                dup = 1;
                break;
            }
        }

        if ( !dup )
        {
            for ( int j = 0 ; j < n2 ; j++ )
            {
                if (arr1[i] == arr2[j] )
                {
                    arr3[*n3] = arr1[i];
                    (*n3)++;
                }
            }
        }
    }

}

int main()
{
    int n1,n2,n3;

    printf("Enter the size of array1 : ");
    scanf("%d",&n1);

    int arr1[n1];
    read(n1,arr1);


    printf("Enter the size of array2 : ");
    scanf("%d",&n2);

    int arr2[n2];
    read(n2,arr2);


    int dummy = n1 < n2 ? n1 : n2 ;
    int arr3[dummy];
    n3 = 0;
    intersection ( n1 , arr1 , n2 , arr2 , &n3 , arr3 );
    write ( n3 , arr3 );

}

