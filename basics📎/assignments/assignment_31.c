#include <stdio.h>
int main()
{
  int num;
  printf("Enter the number : ");
  scanf("%d",&num);

  int count = 0;
  for ( int i = 0 ; i < 32 ; i++ )
  {
    if ( (num & (1<<i)) != 0 )
    {
      count+=1;
    }

  }

  printf("Number of set bits : %d\n",count);
  if ((count & 1 )== 0 )
  {
    printf("Its Even Parity \n");
  }
  else {
  printf("Its odd parity\n");
  }
}
