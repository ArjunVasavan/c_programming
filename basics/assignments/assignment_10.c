#include <stdio.h>

int my_islower(char ch)
{
  if ( ch >= 97 && ch <= 122 )
  {
    return 2;
  }
  else {
  return 0;
  }
}

int main()
{
  char ch;
  printf("Enter the characrter : ");
  scanf("%c",&ch);

  if ( my_islower(ch) )
  {
    printf("Its an Lower Case \n");
  }
  else {
  printf("Its not an Lower case \n");
  }
}
