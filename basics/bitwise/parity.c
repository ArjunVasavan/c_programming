/*
-------------------------------------------------------------------------------

Name        : Arjun Vasavan

Date        : 06 - 10 - 2025

Description : Program to count number of set bits in an given number and print 
              parity.

Sample Execution:

Test Case 1:

Enter the number : 7
Number of set bits = 3
Bit parity is Odd

Test Case 2:

Enter the number : 15
Number of set bits = 4
Bit parity is Even

Test Case 3:

Enter the number : 6
Number of set bits = 2
Bit parity is Even

-------------------------------------------------------------------------------
*/
#include<stdio.h>

void parity_check(int num )
{

  int count = 0;

  for ( int i = 0 ; i < 32 ; i++ )
  {
    if (( num & ( 1 << i)) != 0 )
    {
      count+=1;
    }
  }

  printf("Number of Set bits = %d\n",count);

  if ( (num & 1) == 0 )
  {
    printf("Bit parity is Even \n");
  }
  else 
  {
    printf("Bit parity is Odd \n");
  }
  
}

int main()
{
  printf("Enter the number : ");
  int num;
  scanf("%d",&num);
  parity_check(num);

}
