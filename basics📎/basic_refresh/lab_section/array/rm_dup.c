#include <stdio.h>

int main ()
{
    int size ;
    
    printf("Enter array size: ");
    scanf("%d",& size);
    
    int arr[size];
    
    int uniq_array[size];
    
    printf("Enter array elements: ");
    for( int i = 0 ; i < size ; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int duplicate = 0;
    
    int count = 0;
    
    for( int i = 0 ; i < size ; i++)
    {
        duplicate = 0;
        
        for ( int j = 0 ; j < count ; j++)
        {
            if ( arr[i] == uniq_array[j] )
            {
                duplicate = 1;
                break;
                
            }
        }
        
        if ( duplicate == 0 )
        {
            uniq_array[count] = arr[i];
            count++;
        }
    }
    
    printf("Unique array elements: ");
    for( int i = 0 ; i < count ; i++)
    {
        printf("%d ",uniq_array[i]);
    }
    
}
