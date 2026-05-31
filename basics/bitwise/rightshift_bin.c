#include<stdio.h>
int main()
{
  printf("Enter the num : ");
  int n;
  scanf("%d",&n);

  int setcount = 0;
  int clearcount = 0;

  for ( int i = 31 ;i >= 0 ; i--)
  {
    if ( (n & (1 << i) ) == 0 )
    {
      clearcount+=1;
    }
    else {
      setcount+=1;
    }
  }
  printf("1s = %d");
}
