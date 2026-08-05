/*

--------------------------------------------------------------------------------

Name : Arjun Vasavan

Date : 05-08-2025

Description:-

Program to find the median of two unsorted arrays.

Sample execution:-

Test Case 1:


Enter the 'n' value for Array A: 5
Enter the 'n' value for Array B: 4

Enter the elements one by one for Array A: 3 2 8 5 4
Enter the elements one by one for Array B: 12 13 7 5

Median of array1 : 4
Median of array2 : 9.5                                      
Median of both arrays : 6.75    

Test Case 2: 

Enter the 'n' value for Array A: 5
Enter the 'n' value for Array B: 5

Enter the elements one by one for Array A: 3 2 8 5 4
Enter the elements one by one for Array B: 12 3 7 8 5

Median of array1 : 4
Median of array2 : 7
Median of both arrays : 5.5           


--------------------------------------------------------------------------------

*/

#include <stdio.h>

int main ()
{
    
    int n1;
    int n2;
    
    float mid1;
    float mid2;
    
    printf("Enter the 'n' value for Array A: ");
    scanf("%d",&n1);
    
    printf("Enter the 'n' value for Array B: ");
    scanf("%d",&n2);
    
    int arr1[n1];
    
    int arr2[n2];
    
    int temp;
    
    printf("Enter the elements one by one for Array A:");
    
    for ( int i = 0 ; i < n1 ; i++)
    {
        scanf("%d",&arr1[i]);
    }
    
    printf("Enter the elements one by one for Array B:");
    
    for ( int i = 0 ; i < n2 ; i++)
    {
        scanf("%d",&arr2[i]);
    }
    
    for ( int i = 0 ; i < n1 - 1 ; i++ )
    {
        for( int j = 0 ; j < n1 - i - 1 ; j++ )
        {
            if ( arr1[j] > arr1[j+1] )
            {
                temp = arr1[j];
                
                arr1[j] = arr1[j+1];
                
                arr1[j+1] = temp;
            }
        }
    }
    
    for ( int i = 0 ; i < n2 - 1 ; i++ )
    {
        for (int j = 0; j < n2 - i - 1 ; j++ )
        {
            if ( arr2[j] > arr2[j+1] )
            {
                temp = arr2[j];
                
                arr2[j] = arr2[j+1];
                
                arr2[j+1] = temp;
            }
        }
    }
    
    if ( n1 % 2 != 0 )
    {
        mid1 = arr1[n1/2];
    }
    else
    {
        mid1 = ( arr1[n1/2] + arr1[(n1/2)-1] ) / 2.0;
    }
    
    if ( n2 % 2 != 0 )
    {
        mid2 = arr2[ n2 / 2 ];
    }
    else
    {
       mid2 = ( arr2[ n2 / 2 ] + arr2[ ( n2 / 2 ) - 1 ] ) / 2.0;
    }
    
    printf("Median of array1: %g \n",mid1);
    
    printf("Median of array2: %g \n",mid2);
    
    float middle =( ( mid1 + mid2 ) / 2.0 );
    
    printf("Median of both arrays: %g",middle);
    
}
