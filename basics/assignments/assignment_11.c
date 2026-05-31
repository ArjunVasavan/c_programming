#include <stdio.h>

int my_ispunct(char ch)
{
  if ( !((ch >= 65 && ch <= 90 ) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <= 57)))
  {
    return 1;
  }
  else {
  return 0;
  }
}


int main()
{
   printf("Enter the character : ");
  char ch;
  scanf("%c",&ch);

  if ( my_ispunct(ch) )
  {

    printf("Its an Punctuation \n");
  }
  else {
  printf("Its not an Punctuatuion !\n");
  }
}
