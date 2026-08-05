#include<stdio.h>
#include <string.h>
int main()
{

  char str[50];

  printf("Enter string characters =>> ");

  fgets(str,sizeof(str),stdin);
  

  printf("Result =>> ");
  fputs(str,stdout);
}
