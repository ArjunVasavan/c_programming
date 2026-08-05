#include <stdio.h>

void blanks(char* str)
{
  int i = 0;

  while ( str[i] != '\0')
  {

    if ( str[i] ==' ' && str[i+1] == ' ' )
    {
      int j = i;

      while ( str[j] != '\0' )
      {
        str[j] = str[j+1];
        j+=1;
      }
      str[j] = '\0';
      i-=1;
    }

    i+=1;
  }
}

int main()
{
  char str[30];
  printf("Enter the string : ");
  scanf("%[^\n]",str);

  blanks(str);

  printf("Result : %s\n",str);
}
