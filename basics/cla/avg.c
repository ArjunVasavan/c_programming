#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{
  float average = 0;

  for ( int i = 1 ; i < argc ; i++ )
  {
    average+=atoi(argv[i]);
  }

  printf("o/p: Average: %g",average/(argc-1));
}
