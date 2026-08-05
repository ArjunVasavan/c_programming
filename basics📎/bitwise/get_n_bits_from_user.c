/*

--------------------------------------------------------------------------------

Name        : Arjun Vasavan

Date        : 06 - 10 - 2025

Description : Program to get 'n' bits from given position of a number

Sample Execution: 

Test Case 1:

Enter the number: 12
Enter number of bits: 3
Enter the pos: 4
Result = 3

Test Case 2:

Enter the number: 15
Enter number of bits: 2
Enter the pos: 2
Result =  3

--------------------------------------------------------------------------------
*/

#include <stdio.h>

int get_nbits_from_pos(int, int, int);

int main()
{
  int num, n, pos, res = 0;

  printf("Enter num, n and val:");
  scanf("%d%d%d", &num, &n, &pos);

  res = get_nbits_from_pos(num, n, pos);

  printf("Result = %d\n", res);
}
int get_nbits_from_pos(int num, int n, int pos)
{
  return ( num & ( ( 1 << n ) - 1 ) << (pos - n + 1) ) >> (pos - n + 1);
}
