#include <stdio.h>
int main()
{
   int num;

  printf("Enter the number : ");
  scanf("%d",&num);

  int n;

  printf("Enter the n : ");
  scanf("%d",&n);

  printf("RESULT : "); 
  for ( int i = n-1 ; i >= 0 ; i-- )
  {
    if ( (num & (1 << i))== 0 )
    {
      printf("0");
    }
    else {
    printf("1");
    }
  }
  printf("\n");

}
