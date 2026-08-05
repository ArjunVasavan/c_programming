#include <stdio.h>

void prime(int n )
{
  int i;
  for (  i = 2 ; i*i <= n ; i++ )
  {
    if ( n % i == 0 )
    {
      break;
    }
  }

  if ( i*i > n )
  {
    printf("Its an Prime \n");
  }
  else
{
    printf("Its not an prime\n");
  }
}

int main()
{
  printf("Enter the number : ");
  int n;
  scanf("%d",&n);

  prime(n);
}
