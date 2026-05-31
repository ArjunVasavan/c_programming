// Here were swapping string using malloc else we cant swap for macro because its 
// char* so when changing address it leads to error
#include<stdio.h>
#include <stdlib.h>
#define SWAP(d,a,b)   \
        {             \
          d temp = a; \
          a = b;      \
          b = temp;   \
        }             \

int main()
{
  printf("Enter the string 1 : ");
  char* str1 = malloc(50);

  char* str2 = malloc(50);
  scanf("%s",str1);

  printf("Enter the string 2 : ");
  getchar();
  scanf("%s",str2);

  SWAP(char*,str1,str2);

  printf("After Swapping =>\n str1 : %s\n str2 : %s \n",str1,str2);


}
