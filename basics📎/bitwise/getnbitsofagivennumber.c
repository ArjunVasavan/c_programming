/*

--------------------------------------------------------------------------------

Name        : Arjun Vasavan

Date        : 06 - 10 - 2025

Description : Program to get 'n' bits of a given number

Sample Execution: 

Test Case 1:

Enter the number: 10
Enter number of bits: 3
Result = 2

Test Case 2:

Enter the number: 15
Enter number of bits: 2
Result = 3

--------------------------------------------------------------------------------
*/

#include <stdio.h>

int get_nbits(int, int);

int main()
{
    int num, n, res = 0;
    
    printf("Enter num and n:");
    scanf("%d%d", &num, &n);
    
    
    printf("Result = %d\n", get_nbits(num,n));
}

int get_nbits(int num,int n)
{
  return ( num & ( ( 1 << n ) - 1 ) );
}
