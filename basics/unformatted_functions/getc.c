#include<stdio.h>
int main()
{
  char ch;

  printf("enter an character : ");

  ch = getc(stdin);

  // acutally itll read only characters only
  printf("%c",ch);
}
