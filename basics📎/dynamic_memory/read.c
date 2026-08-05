#include <stdio.h>
#include<stdlib.h>
int main()
{
   printf("Enter the String : ");
  char* str = malloc(15);
  scanf("%[^\n]",str);

  printf("%s \n",str);

}
