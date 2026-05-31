/*
--------------------------------------------------------------------------------

Name        : Arjun Vasavan

Date        : 08 - 10 - 2025

Description : Program to print 'n' bits from LSB of a number

Sample Execution: 

Test Case 1:

Enter the number: 10
Enter number of bits: 12
Binary form of 10: 0 0 0 0 0 0 0 0 1 0 1 0 

Test Case 2:

Enter the number: 15
Enter number of bits: 4
Binary form of 15: 1 1 1 1

--------------------------------------------------------------------------------
*/
#include <stdio.h>

int print_bits(int, int);

int main()
{
    int num, n;
    
    printf("Enter num, n :\n");
    scanf("%d%d", &num, &n);
    
    printf("Binary form of %d:", num);
    print_bits(num, n);
 }

int print_bits(int num  , int n)
{
  num = ( (num) & ( (1 << n) - 1 ) ); // gets the n bits from lsb.

  for ( int i = 31 ; i >= 0 ; i-- ) // an loop which prints binary
  {
    if (( num &(1 << i)) == 0)
    {
      printf("0");
    }
  else 
  {
      printf("1");
  }

  }
  printf("\n");
}
