#include<stdio.h>

#define swap(n) ((n&0xF0)>>4) | ((n&0xF0)<<4)
int main()
{
  char num;
  printf("Enter the number : ");
  scanf("%c",&num);

  printf("Swapped As : %d",swap(num));
}
