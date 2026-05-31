#include <stdio.h>

void fib(int n,int out,int first,int second)
{
  if ( out <= n )
  {
    printf("%d ",out);
    second = first;
    first = out;
    out = first+second;
    fib(n,out,first,second);
  }
}

int main()
{
   printf("Enter the number : ");
  int n;
  scanf("%d",&n);

  fib(n,0,1,0);
}
