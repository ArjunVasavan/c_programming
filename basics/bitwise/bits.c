/*
-------------------------------------------------------------------------------

Name        : Arjun Vasavan

Date        : 06 - 10 - 2025

Description : Program to print bits of entered number.

Sample execution: 

Enter the number : 10

00000000000000000000000000001010

-------------------------------------------------------------------------------
*/
#include<stdio.h>

int main()
{
  //printf("Enter the number :");
  int n;
  scanf("%d",&n);
  for ( int i = 31 ; i >= 0 ; i-- )
    if ( (n & ( 1 << i )) == 0 ) // i checks each bit by bit from msb to lsb
    {
      printf("0");
    }
    else 
    {
      printf("1");
    }
  }

}
