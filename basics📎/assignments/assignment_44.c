#include <stdio.h>
void short_swap(char* hex_value )
{
  char temp = *hex_value;
  *hex_value = *(hex_value+1);
  *(hex_value+1) = temp;

}
void int_swap(char* hex_value)
{
  char temp = *hex_value;
  *hex_value = *(hex_value+3);
  *(hex_value+3) = temp;

  temp = *(hex_value+1);
  *(hex_value+1) = *(hex_value+2);
  *(hex_value+2) = temp;

}
int main()
{
  printf("Enter the size : ");
  int size;
  scanf("%d",&size);

  switch (size) 
  {
    case 2:
      {

        unsigned short hex_value;
        printf("Enter the hexadecimal :");
        scanf("%hx",&hex_value);
        short_swap((char*)&hex_value);
        printf("RESULT : %hX",hex_value);
        break;
      }
    case 4:
      {
        unsigned int hex_value;
        printf("Enter the hexadecimal :");
        scanf("%x",&hex_value);
        int_swap((char*)&hex_value);
        printf("RESULT : %X",hex_value);
        break;
      }
    default:
      {
        printf("Enter short size or integer size only\n");
      }
  
  }
}
