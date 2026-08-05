#include <stdio.h>

void fib(int n)
{
  int first = 1;
  int second = 0;
  int fib = 0;
  int i = 0;
  while (fib <= n)
  {
    
    printf("%d ",fib);


    second = first;

    first = fib;
    fib = first + second;

  }
}

int main()
{
  printf("Enter the number : ");
  int n;
  scanf("%d",&n);

  fib(n);


}
