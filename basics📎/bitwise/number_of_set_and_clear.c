#include<stdio.h>
int main()
{
  printf("Enter the number : ");
  int n;
  scanf("%d",&n);

  int countset = 0;
  int countclear = 0;
  for ( int i = 31 ; i >= 0 ; i-- )
  {
    if (( n & ( 1 << i )) == 0 )
    {
      countclear+=1;
    }
    else {
      countset+=1;
    }
  }

  printf(" Number of Set = %d \n Number of Clear = %d \n",countset,countclear);
} 
