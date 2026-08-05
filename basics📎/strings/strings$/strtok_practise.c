#include<stdio.h>

char* fun(char* str , char* delim) {
  static  int i = 0;
  static char* start;

  int begin = i;

  if ( str != NULL ) {
    start = str;
  }

  while ( start[i]) {

    int j = 0;

    while ( delim [j] ) {

      if ( start[i] == delim[j] ) {
        start[i] = '\0';
        return start+begin;
      } else {
        j+=1;
      }

    }

    i+=1;
  }


  if ( start[begin] != '\0' ) {
    return start+begin;
  } else {
    
    return NULL;
  }


  return start;
}

int main()
{

  char str[50],delim[50];

  printf("Enter an string -> ");
  scanf("%[^\n]",str);

  printf("Enter an Delimeter -> ");
  scanf(" %[^\n]",delim);

  char* token = fun(str,delim);

  while ( token != NULL )
  {
    printf(" Token = %s \n",token);

    token = fun(NULL,delim);
  }

}
