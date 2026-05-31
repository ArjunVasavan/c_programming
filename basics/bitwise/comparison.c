#include<stdio.h>
int main()
{
  printf("Enter the num1 : ");
  int n1;
  scanf("%d",&n1);

  printf("Enter the num2 : ");
  int n2;
  scanf("%d",&n2);

  int result = n1 ^ n2;

  int count = 0;

 for ( int i = 31 ; i >= 0 ; i-- )
  {
    if ( (result & ( 1 << i )))
    {
      count+=1;
    }
  }

  printf("Total Flips Required = %d",count);
}
