#include <stdio.h>
int fun(int j, int b);
void main()
{
  int i = 138, a = 136,k;

  k = fun( !++i,!++a );
  printf("%d %d %d",i,a,k);
}

int fun(int j, int b)
{
  int c;
  c = j+b;
  return (c);

}
