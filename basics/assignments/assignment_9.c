#include <stdio.h>

int my_isalnum(char ch)
{
  if ( (ch >= 48 && ch <= 52 ) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
  {
    return 8;
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
  

  if(my_isalnum(ch))
  {
    printf("Its an alphanumeric character \n");
  }
  else 
  {
  
    printf("Its not ah alphanumeric character \n");
  }
}
