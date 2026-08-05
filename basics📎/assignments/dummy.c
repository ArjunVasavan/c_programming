#include <stdio.h>

char* mystrtok(char* str,const char* del)
{
  int i = 0;
  static char* storage;
  char* iterate;
  char* starting;

  if ( str != NULL )
  {
    storage = str;
    iterate = str;
    starting = str;
  }
  else 
  {
    iterate = storage;
    starting = storage;
  }

  while ( iterate[i] != '\0' )
  {
    int j = 0;

    while ( del[j] != '\0' )
    {

      if ( iterate[i] == del[j] )
      {
        iterate[i] = '\0';
        i+=1;
        storage = iterate+i;
        return starting;
      }

      j+=1;
    }
    i+=1;
  }

  if ( iterate[i] == '\0' && starting[0] != '\0' )
  {
    storage = iterate+i; 
    return starting;
  }
  return NULL;
}

int main()
{
  char str[50];
  printf("Enter the string : ");
  scanf("%[^\n]",str); 
  char del[20];
  printf("Enter the delimeter : ");
  getchar();
  scanf("%[^\n]",del);

  char* token = mystrtok(str,del);

  while ( token != NULL )
  {
    printf("%s\n",token);
    token = mystrtok(NULL,del);
  }
}
