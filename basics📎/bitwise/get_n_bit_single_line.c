/*  
--------------------------------------------------------------------------------

Name : Arjun Vasavan

Date : 06 - 10 - 2025

Description : Program to replace n bits of given number.


Sample Execution: 

Test Case 1:

Enter the num, n and val: 10 3 12
Result = 12

Test Case 2:

Enter the num, n and val: 15 2 1
Result =  13

--------------------------------------------------------------------------------
*/
#include <stdio.h>

int replace_nbits(int, int, int);

int main()
{
    int num, n, val, res = 0;
    
    printf("Enter num, n and val:");
    scanf("%d%d%d", &num, &n, &val);
    
    res = replace_nbits(num, n, val);
    
    printf("Result = %d\n", res);
}

int replace_nbits(int num,int n,int val )
{
  
  // clearing lsb side of bits

  // getting lsb side of bits

  return (num & ( ~( ( 1 << n ) - 1 ) ) ) |  ( val & ( ( 1 << n ) - 1 ) ); 

}

