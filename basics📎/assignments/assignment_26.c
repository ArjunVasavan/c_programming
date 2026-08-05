#include <stdio.h>

void rev(char* str,int start,int last)
{
  if ( start < last )
  {
    str[start] = str[start] ^ str[last];
    str[last] = str[start] ^ str[last];
    str[start] = str[start] ^ str[last];

    start+=1;
    last-=1;

  rev(str,start,last);
    
  }
}

int main()
{
   printf("Enter the string : ");
  char str[50];
  scanf("%[^\n]",str);

  int i = 0;

  while ( str[i] )
  {
    i+=1;

  }
  int last = i - 1;
  int start = 0;

  rev(str,start,last);

  printf("Result = %s\n",str);
}
