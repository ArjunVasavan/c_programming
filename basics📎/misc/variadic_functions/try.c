#include <stdio.h>
#include <stdarg.h>

int add(int count , ... )
{
  va_list ap;

  va_start(ap, count);

  int sum = 0;

  int i = 0;

  while ( i < count )
  {
    sum+=va_arg(ap,int);
    i+=1;
  }

  va_end(ap);

  return sum;
}
int main()
{

  printf("%d\n",add(5,1,2,3,4,5));
  printf("%d\n",add(5,10,30,10,4,5));
  printf("%d\n",add(5,1,2,3,100,5));
  printf("%d\n",add(5,1,2,3,4,500));
    
}
