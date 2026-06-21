#include<stdio.h>
int main()
{
  FILE* fptr = fopen("abc.txt","r");

  FILE* wptr = fopen("out.txt","w+");

  char ch;
  while ( (ch = getc(fptr))!=EOF)
  {
    if ( ch != 'c')
    {
      putc(ch,wptr);
    }
  }

  fclose(fptr);

  rewind(wptr);
  FILE* endptr = fopen("abc.txt","w");

  while ( (ch = getc(wptr))!=EOF)
  {
    putc(ch,endptr);
  }

  fclose(endptr);
  fclose(wptr);

}
