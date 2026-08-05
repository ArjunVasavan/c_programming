#include<stdio.h>

char* fun(char* str, char* del)
{
  int i = 0;

  while( str[i] )
  {
    int j = 0;

    while ( del[j])
    {

      if ( str[i] == del[j] )
      {
        str[i] = '\0';

        return str;
      }

      j+=1;
    }

    i+=1;
  }
}

int main()
{
  char str[50],del[50];
  printf("Enter an Character  :");
  scanf("%[^\n]",str);
  printf("Enter an Delimeter  : ");
  scanf(" %[^\n]",del);

  char* token = fun(str,del);

  printf("Token : %s \n",token);

}
