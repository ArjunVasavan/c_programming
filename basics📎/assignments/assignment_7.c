#include <stdio.h>
int main()
{
   printf("Enter the n vale : ");
  int n;
  scanf("%d",&n);

  for ( int i = n ; i >= 1 ; i-- )
  {
    for ( int j = i ; j <= n ; j++ )
    {
      printf("%d",j); 
    }
    printf("\n");
  }

  for ( int i = 2 ; i <= n ; i++ )
  {
    for ( int j = i ; j <= n ; j++  )
    {
      printf("%d",j);
    }
    printf("\n");
  }
}
