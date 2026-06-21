#include<stdio.h>
int main()
{
  FILE* input = fopen("source.txt","r");

  int ch; // int is maken for EOF being -1 sometime char ch will be unsifn=gnes so thats why
  
  FILE* output = fopen("destination.txt","w");

  if ( input == NULL || output == NULL )
  {
    printf("Error File cannot be opened\n");
    return 0;
  }

  int count = 0;

  while ((ch = getc(input)) != EOF )
  {
    putc(ch,output);


    if ( ch == '\n' )
    {
      count+=1;
    }
  }


  fclose(input);
  fclose(output);


  printf("Copied %d lines",count);

  return 0;
}
