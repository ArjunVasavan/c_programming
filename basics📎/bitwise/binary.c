#include<stdio.h>
int main()
{
  printf("Enter the num : ");
  int n;
  scanf("%d",&n);

  for ( int i = 31 ;i >= 0 ; i--)
  {
    if ( (n & (1 << i) ) == 0 )
    {
      printf("0");
    }
    else {
      printf("1");
    }
  }
  printf("\n");
}
