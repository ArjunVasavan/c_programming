#include<stdio.h>
int main()
{
  char str[100];

  FILE* input = fopen("source.txt","r");

  FILE* output = fopen("destination.txt","w");

  if ( input == NULL || output == NULL )
  {
    printf("Error Cannot open the files\n");
  }

  while ( fgets(str,sizeof(str),input) )
  {
    int i = 0;

    while ( str[i] )
    {

      if ( str[i] >=  97  && str[i] <= 122 )
      {
        str[i]-=32;
      }

      i+=1;

    }

    fputs(str,output);
  }

  fclose(input);
  fclose(output);
}
