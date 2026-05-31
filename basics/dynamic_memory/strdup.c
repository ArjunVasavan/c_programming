#include <stdlib.h>
#include <stdio.h>

int my_strlen(const char* str )
{

  int i = 0;

  while ( str[i] != '\0' )
  {
    i+=1;
  }

  return i-1;
}

void my_strcpy(char* str1,const char* str2)
{

  int i = 0;

  while (str2[i] != '\0') 
  {
    str1[i] = str2[i];
    i+=1;
  }

  str1[i] = '\0';

}

char* my_strdup(const char* str)
{
  char* dup = malloc( my_strlen(str) + 1 );

  my_strcpy(dup,str);
  
  return dup;
}

int main()
{
  char str[30];
  printf("Enter the String : ");
  scanf("%[^\n]",str);

  char* copy = my_strdup(str);

  printf("Output of stdup : %s \n",copy);

}
