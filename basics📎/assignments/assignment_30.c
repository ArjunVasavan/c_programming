#include <stdio.h>

void pangram(char* str)
{
  char* alpha = "abcdefghijklmnopqrstuvwxyz";

  int ispangram = 1;

  int i = 0;
  while (alpha[i])
  {

    int j = 0;

    while ( str[j] )
    {
      if (str[j] == alpha[i])
      {
        break;
      }
      j+=1;
    }

    if ( str[j] == '\0' )
    {
      ispangram = 0;
      break;
    }

    i+=1;
  }

  if (ispangram)
  {
    printf("Its  an Pangram\n");
  }
  else
{
    printf("Its not an Pangram\n");
  }
}

int main()
{
  printf("Enter the string : ");
  char str[50];
  scanf("%[^\n]",str);

  pangram(str);

}
