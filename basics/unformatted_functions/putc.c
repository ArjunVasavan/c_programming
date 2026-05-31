#include<stdio.h>
int main()
{
  char ch;

  printf("enter an character : ");

  ch = getc(stdin);
// acutally getc read only characters only

  putc(ch,stdout);
  // so put c will also print only single character
}
