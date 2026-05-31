#include<stdio.h>
int main()
{
  int n;
  printf("Enter an Number : ");
  scanf("%d",&n);

  int leadingzeroes = 0;

  for( int i = 0 ; i <= 31 ; i++ )
  {
    if ( (n & (1 << i)) == 0 )
    {
      leadingzeroes+=1;
    }
      else {
      break;
      }
  }

  printf("Number of leading Zeroes = %d",leadingzeroes);
}
