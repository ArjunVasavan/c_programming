#include <stdio.h>

void perfect ( int n )
{
  int sum = 0;
  for ( int i = 1 ; i <= n/2 ; i++ )
  {
    if ( n % i == 0 )
    {
      sum+=i;
    }
  }

  if ( sum == n )
  {
    printf("Its an Perfect Number \n");
  }
  else {
  
    printf("Its an not Perfect Number \n");
  }
}
int main()
{
  printf("Enter the number : ");
  int n;
  scanf("%d",&n);
  perfect(n);
}
