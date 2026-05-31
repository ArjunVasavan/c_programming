#include <stdio.h>
#include <stdarg.h>

int sum(int count, ... )
{
  va_list ap;

  va_start(ap,count);

  int i = 0;

  int output = 0;
  while ( i < count )
  {

    output+=va_arg(ap,int);
    i+=1;
  }
  return output;
}


int main()
{

  printf("result =  %d\n",sum(3,10,10,10));
  printf("result =  %d\n",sum(2,100,50));
  printf("result =  %d\n",sum(4,10,10,10,10));

}
