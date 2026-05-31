/*
------------------------------------------------------------------------------
Name : Arjun Vasavan

Description : Program to 

Sample execution: -
Test Case 1:
Size of int : 4 bytes
Size of char : 1 byte
Size of float : 4 bytes
Size of double : 8 bytes
Size of unsigned int : 4 bytes
Size of long int : 8 bytes
-------------------------------------------------------------------------------
*/
#include<stdio.h>
#define SIZEOF(x) (char*)(&x+1) - (char*)(&x)
int main()
{
  int i;
  char c;
  float f;
  double d;
  unsigned int ui;
  long int li;

  printf("Size of int : %lu\n",SIZEOF(i));
  printf("Size of char : %lu\n",SIZEOF(c));
  printf("Size of float : %lu\n",SIZEOF(f));
  printf("Size of double :  %lu\n",SIZEOF(d));
  printf("Size of unsigned int : %lu\n",SIZEOF(ui));
  printf("Size of long int : %lu\n",SIZEOF(li));
}
