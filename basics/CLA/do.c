#include <stdio.h>
#include <string.h>
int main(int argc , char* argv[] ,char* envp[])
{
  if ( argc == 1 )
  {
    printf("ERROR : ENTER AN INPUT");
  }

  char* val ;
  char* var ;
  int i = 0;
  while ( envp[i] != NULL )
  {
    var = strtok(envp[i],"=");
    if ( strcmp(var,argv[1]) == 0 )
    {
      val = strtok(NULL,"=");

      printf("%s",val);

      break;
    }
    i+=1;
  }
}
