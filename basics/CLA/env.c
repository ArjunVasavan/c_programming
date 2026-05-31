#include <stdio.h>
#include <string.h>
int main(int argc , char* argv[] ,char* envp[])
{
  int i = 0;
  while ( envp != NULL )
  {
    strtok(envp[i],"=");
    printf("%s\n",envp[i]);
    i+=1;
  }
}
