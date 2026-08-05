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
  
  // Skip leading delimiters
  while ( starting[i] != '\0' )
  {
    int k = 0;
    int is_delimiter = 0;
    while ( del[k] != '\0' )
    {
      if ( starting[i] == del[k] )
      {
        is_delimiter = 1;
        break;
      }
      k++;
    }
    if ( is_delimiter )
    {
      i++;  // Skip this delimiter
    }
    else
    {
      break;  // Found a non-delimiter, stop skipping
    }
  }
  
  // Update starting to point past the delimiters
  starting = starting + i;
  iterate = starting;
  i = 0;  // Reset i to search from the new starting position
  
  // If we've reached the end, no more tokens
  if ( starting[0] == '\0' )
  {
    return NULL;
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
