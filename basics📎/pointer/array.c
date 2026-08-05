#include <stdio.h>

void read( int reader[], int size )
{
    printf("Enter the array elements --> ");
    for ( int i = 0 ; i < size ; i ++ )

    {
        scanf("%d",reader + i );
    }

}

void write( int* writer , int size )
{   
    printf("Your Written elements are --> ");
    for ( int i = 0 ; i < size ; i ++ )
    {
        printf("%d ",writer[i]);
    }

    printf("\n");

}

int main()
{
    int size ;

    printf("Enter the size of the array --> ");
    scanf("%d",&size);

    int arr[size];

    read (arr,size);

    write(arr,size);

}

