// #include<stdio.h>
// int main()
// {
//   unsigned int n;
//
//   printf("Enter The Hexadecimal :");
//   scanf("%x",&n);
//
//   n = n&0xFF;
//
//   unsigned int  res1 = (n&0xF0)>>4;
//   n = (n&0x0F)<<4;
//
//   n = n|res1;
//
//   printf("%02X",n);
// }


#include <stdio.h>

#define SWAP(x)                      \
{                                    \
  x = x & 0xFF;                      \
  unsigned int res = (x & 0xF0) >> 4;\
  x = (x & 0x0F) << 4;               \
  x = x | res;                       \
}                                    \
                

int main()
{

  unsigned int num;

  printf("Enter an Number : ");
  scanf("%x",&num);

  SWAP(num)

  printf("Result : %X \n",num);

}
