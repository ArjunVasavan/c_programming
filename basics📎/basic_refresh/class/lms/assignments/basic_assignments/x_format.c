/*

Name : Arjun Vasavan

Date : 30-07-2025

Description : Program which prints numbers in  X format.

Sample Output:

Test Case 1:

Enter the number: 4


1  4
 23
 23
1  4

Test Case 2:
Enter the number: 5
1   5
 2 4
  3
 2 4
1   5

*/
#include <stdio.h>

int main ()
{
    int n;
    
    //printf("Enter the number: ");
    
    scanf("%d",&n);
    
    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= n ; j++ )
        {
            if ( i == j )
            {
                printf("%d",i);
            }
            
            else if ( i + j == n + 1)
            {
                printf("%d",j);
            }
            
            else
            {
                printf(" ");
            }
        }
        
        printf("\n");
    }
}
