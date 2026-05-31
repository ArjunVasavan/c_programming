#include <stdio.h>

void read ( int n , int arr[])
{
    printf("Enter the elements of array : ");

    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d",&arr[i]);
    }
}

void write ( int n , int arr[] )
{
    printf("Output : ");

    for ( int i = 0 ; i < n ; i++ )
    {
        printf("%d ",arr[i]);
    }

    printf("\n");
}

void uni (int  n1 ,int arr1[], int n2 , int arr2[] , int * n3 , int arr3[] )
{

    for ( int i = 0 ; i < n1 ; i++ )
    {
        int dup = 0;

        for ( int j = 0 ; j < *n3 ; j++  )
        {
            if(arr1[i] == arr3[j] )
            {
                dup = 1;
                break;
            }
        }

        if (!dup)
        {
            arr3[*n3] = arr1[i];

            (*n3)++;
            
        }
    }
    for ( int i = 0 ; i < n2 ; i++ )
    {
        int dup = 0;

        for ( int j = 0 ; j < *n3 ; j++  )
        {
            if(arr2[i] == arr3[j] )
            {
                dup = 1;
                break;
            }
        }

        if (!dup)
        {
            arr3[*n3] = arr2[i];

            (*n3)++;
            
        }
    }

}

int main()
{
    int size1,size2,size3;

    printf("Enter the size of array 1 : ");
    scanf("%d",&size1);

    int arr1[size1];

    read(size1,arr1);


    printf("Enter the size of array 2 : ");
    scanf("%d",&size2);

    int arr2[size2];

    read(size2,arr2);


    int arr3[size1+size2];

    size3 = 0;

    uni (size1,arr1,size2,arr2,&size3,arr3);


    write(size3,arr3);

}
