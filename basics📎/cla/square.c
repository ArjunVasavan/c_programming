#include <stdlib.h>
#include <stdio.h>
void square(int** arr)
{
  int square;

  square = (*arr[0])*(*arr[0]);
  printf("Square of n1 is : %d \n",square);
  square = (*arr[1])*(*arr[1]);
  printf("Square of n2 is : %d \n",square);
  square = (*arr[2])*(*arr[2]);
  printf("Square of n3 is : %d \n",square);
}
int main(int argc,char* argv[])
{
  int n1 = atoi(argv[1]);
  int n2 = atoi(argv[2]);
  int n3 = atoi(argv[3]);

  int* arr [] = {&n1,&n2,&n3};


  square(arr);
}
