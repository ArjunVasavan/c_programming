/*
--------------------------------------------------------------------------------
Name : Arjun Vasavan

Date : 08 - 10 - 2025

Description : Program to implement Circular right shift

Sample execution: -

Test Case 1:

Enter num: 12
Enter n : 3
Result in Binary: 00000000000000000000000001100000

Test Case 2: 

Enter num: -2
Enter n : 3
Result in Binary: 11111111111111111111111111110111

--------------------------------------------------------------------------------
*/

#include <stdio.h>

int circular_left(int, int);
int print_bits(int);

int main()
{
  int num, n, ret;

  printf("Enter the num:");
  scanf("%d", &num);

  printf("Enter n:");
  scanf("%d", &n);

  ret = circular_left(num, n);

  print_bits(ret);
}

int circular_left(int num,int n)
{
  return ((num >> n) | (num << (32 - n)));
}

int print_bits(int ret )
{
  for ( int i = 31 ; i >= 0 ; i-- )
  {
    if (( ret &(1 << i)) == 0)
    {
      printf("0");
    }
    else 
  {
      printf("1");
    }

  }

  printf("\n");

  return 1;
}
