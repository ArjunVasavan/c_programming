#include <stdio.h>


int my_isxdigit(char ch)
{
  if ( (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F' ) || (ch >= 'a' && ch <= 'f' ))
  {
  
    return 1;
  }
  else {
  return 0;
  }
}

int main()
{
  char ch;

  printf("Enter the character : ");
  scanf("%c",&ch);

  if (my_isxdigit(ch))
  {
    printf("Its an Hexadecimal\n");
  }
  else {
  printf("Its not an Hexadecimal\n");
  }
}
