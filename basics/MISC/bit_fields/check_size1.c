#include <stdio.h>

struct test 
{
  char ch : 4;
  int x : 24;
};
int main()
{
  struct test var;

  printf("%lu bytes \n",sizeof(var));
    
}
