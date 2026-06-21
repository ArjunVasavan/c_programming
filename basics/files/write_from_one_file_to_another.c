#include<stdio.h>
int main()
{
  FILE* fptr = fopen("abc.txt","w");

  FILE* cptr = fopen("new.txt","r");

  char ch ;

  if ( fptr == NULL )
  {
    printf("FILE OPENING IS UNSUCCESFULL\n");
  }
  else {
  
    printf("FILE OPENING IS SUCCESFULL\n");
  }

  while ( !feof(fptr))
  {
    ch = getc(stdin);
    int cp;

    putc( FILE *stream)
  }



}
