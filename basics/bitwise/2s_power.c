
//sir got impressed by my logic

#include<stdio.h>
int main()
{
  int n;
  printf("Enter the number : ");
  scanf("%d",&n);

  if ( (n&(n-1)) == 0 )
  {
    printf("It Belongs to 2's power\n");

  }
  else {
  printf("It doesnt Belongs to 2's power\n");
  }
}
