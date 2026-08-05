#include<stdio.h>
int main()
{
  printf("Enter the number : ");
  int num;
  scanf("%d",&num);

  int count = 0;

  for ( int i = 0 ; i <= 31 ; i++ )
  {
    if ( ( num & ( 1 << i)) != 0 )
    {
      count+=1;
    }
  }

  printf("The count of set bits is %d\n",count);
}
