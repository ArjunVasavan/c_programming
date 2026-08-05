#include <stdio.h>

int getword(char* str )
{
  int i = 0;

  while ( str[i] != ' ' )
  {
    i+=1;
  }
  i-=1;

  return i+1;
}

int main()
{
   char str[50];

  printf("Enter the string : ");
  scanf("%[^\n]",str);

  printf("Output of getword is  %d \n",getword(str));
}
