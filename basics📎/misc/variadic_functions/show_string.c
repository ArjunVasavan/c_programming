#include <stdio.h>
#include <stdarg.h>

void print(int count, ... )
{
  va_list ap;

  va_start(ap,count);

  int i = 0;

  while ( i < count )
  {
    printf("%s\n",va_arg(ap,char*));
    i+=1;
  }
}
int main()
{
    
  print(4,"Arjun","Vasavan","Clown","Joker");

}
