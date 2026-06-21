#include <stdio.h>
#include <strings.h>
#include <string.h>
int main( int argc , char* argv[] , char* envp[] )
{
    int i = 0;

  while ( envp[i] )
  {
    char* ret = strtok(envp[i],"=");

    if ( strcasecmp(argv[1],envp[i]) == 0 )
    {
      ret = strtok(NULL,"\0");

      printf("%s \n",ret);
      break;
    }
    i+=1;
  }
}
