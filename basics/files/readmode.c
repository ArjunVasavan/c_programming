#include<stdio.h>
int main()
{
  FILE* fptr = fopen("abc.txt","r");

  char ch;

  if ( fptr == NULL )
  {
    printf("File opening in unsuccesfull\n");
  }
  else {
    printf("File opening is successfull\n");
  }

  printf("offset is at %lu on starting \n",ftell(fptr));

  // while ( (ch = getc(fptr)) != EOF)
  // {
  //   putc(ch,stdout);
  // }
  
  while ( !feof(fptr) )
  {
    ch= getc(fptr);
    putc(ch,stdout);
  }
  printf("offset is at %lu on ending\n",ftell(fptr));
}
