#include <math.h>
#include <stdio.h>
int main()
{
  int* c;
  c = check(10,20);
  printf(" c = %u",c);
  return 0;
}

check ( int i , int j )
{
  int *p,*q;
  p = &i;
  q = &j;
  if ( i >= 45 )
  return (p);
  else
   return (q);
}

