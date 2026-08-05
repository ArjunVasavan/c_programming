/*
--------------------------------------------------------------------------------

Name       : Arjun Vasavan

Date       : 06 - 10 - 2025

Description: Program to check N th bit is set or not, If yes, clear the M th bit


Sample Execution:

Test Case 1:

Enter the number: 19

Enter 'N': 1

Enter 'M': 4

Updated value of num is 3 

Test Case 2:

Enter the number: 19

Enter 'N': 2

Enter 'M': 4

Updated value of num is 19 

--------------------------------------------------------------------------------
*/
#include<stdio.h>

#define UPDATE(n,m,num) num = ( ( ( num ) & (1 << n )) != 0 ) ? ( num ) & ( ~( 1<<m ) ) : num;
// This macro above will do the operation

int main()
{
  int num,n,m;

  printf("Enter the number: ");
  scanf("%d",&num);

  printf("Enter the 'N': ");
  scanf("%d",&n);
  
  printf("Enter the 'M': ");
  scanf("%d",&m);

  UPDATE(n,m,num); // operation is done here where macro is replaced by function
                  //  like macro

  printf("Updated value of num is %d\n",num);

}
