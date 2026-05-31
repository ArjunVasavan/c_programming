#include <stdio.h>

void rev(char* str)
{
  int i = 0;

  while ( str[i] )
  {
    i+=1;
  }

  int end = i-1;
  int start = 0;

  while ( start < end )
  {

    str[start] = str[start] ^ str[end];
    str[end] = str[start] ^ str[end];
    str[start] = str[start] ^ str[end];

    start+=1;
    end-=1;
  }
}

int main()
{
   printf("Enter the string : ");
  char str[40];

  scanf("%[^\n]",str);

  rev(str);

  printf("Result : %s \n",str);
}
