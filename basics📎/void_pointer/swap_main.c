#include <stdio.h>

void swap(void* n1,void* n2,int size)
{
  unsigned char*ptr1 = n1;
  unsigned char* ptr2 = n2;
  unsigned char temp;

  for ( int i = 0 ; i < size ; i++ )
  {
    temp =  ptr1[i];
    ptr1[i] = ptr2[i];
    ptr2[i] = temp;
  }
}

int main()
{
  int num1 = 10 ,num2 = 20;

  float n1 = 10.5,n2 = 20.5;

  printf("Before swapping num1 = %d, num2 = %d \n",num1,num2);

  swap(&num1,&num2,sizeof(int));

  printf("After swapping num1 = %d, num2 = %d \n",num1,num2);

  printf("Before swapping n1 = %g, n2 = %g \n",n1,n2);

  swap(&n1,&n2,sizeof(float));

  printf("After swapping n1 = %g, n2 = %g \n",n1,n2);
}
