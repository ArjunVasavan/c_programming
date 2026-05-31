#include<stdio.h>

void binary(int n, int i)
{
  if ( i >= 0 )
  {
    if ( (n & ( 1 << i) ) == 0 )
    {
      printf("0");
    }
    else 
    {
      printf("1");
    }

    binary(n,i-=1);
  }
  else 
  {
    printf("\n");
  }

}
int main()
{
  int n;
  printf("Enter the number : ");
  scanf("%d",&n);

  binary(n,31);
}
