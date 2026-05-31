#include<stdio.h>
int main()
{
    FILE *fptr = fopen("file1.txt","r");

    FILE *fp = fopen("write.txt","w");

    if ( fptr == NULL )
    {
      printf("File not opened\n");
      return 1;
    }

    printf("File open successfully\n");

    printf("offset positon at start : %ld\n",ftell(fptr));

    char ch;

    while ( !feof(fptr) )
  {
    ch = getc(fptr);
    putc(ch,fp);
  }

  fclose(fptr);
}
