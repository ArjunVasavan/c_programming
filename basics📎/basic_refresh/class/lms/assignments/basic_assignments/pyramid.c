/*

Name : Arjun Vasavan

Date : 30-07-2025

Description : Program which prints pyramid pattern.

Sample Output:

Test Case 1:
Enter the number: 4

4
3 4
2 3 4
1 2 3 4
2 3 4
3 4
4


Test Case 2:
Enter the number: 6


6
5 6
4 5 6
3 4 5 6
2 3 4 5 6
1 2 3 4 5 6
2 3 4 5 6
3 4 5 6
4 5 6
5 6
6


*/
#include<stdio.h>

int main()
{
    int n;
    
    //printf("Enter the number: ");
    
    scanf("%d",&n);
    
    for ( int i = n ; i > 0 ; i-- )
    {
        for ( int j = i ; j <= n ; j++ )
        {
            printf("%d ",j);
        }
        
        printf("\n");
    }
    
    for ( int i = 2 ; i <= n ; i++ )
    {
        for ( int j = i ; j <= n ; j++ )
        {
            printf("%d ",j);
        }
        
        printf("\n");
    
    }
}
