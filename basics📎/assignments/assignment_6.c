#include <stdio.h>
int main()
{
  printf("Enter the 'n' value :");
  int n;
  scanf("%d",&n);

  for ( int i = 1 ; i <= n ; i++ )
  {
    for ( int j = 1 ;j <= n ; j++ )
    {
      if ( i == j || (i+j) == n + 1 )
      {
        printf("%d",j);
      }
      else {
        printf(" ");
      }
    }
    printf("\n");


  }
}
