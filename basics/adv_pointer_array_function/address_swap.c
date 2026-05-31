/*
--------------------------------------------------------------------------------

Name : Arjun Vasavan

Date : 23-10-2025

Description : Program to convert little endian data to big endian

Sample execution: -

Test Case 1:

Enter the size: 2
Enter any number in Hexadecimal: ABCD
After conversion CDAB

Test Case 2:

Enter the size: 4
Enter any number in Hexadecimal: 12345678
After conversion 78563412

--------------------------------------------------------------------------------
*/
#include <stdio.h>

void swap_short( char* ptr )
{
  char temp;             //swapping bytes 
  temp = *ptr;
  *ptr = *(ptr+1);
  *(ptr+1) = temp;
}
void swap_int( char* ptr )
{
  char temp;                //swapping bytes 
  temp = *ptr;
  *ptr = *(ptr+3);
  *(ptr+3) = temp;

  temp = *(ptr+1);
  *(ptr+1) = *(ptr+2);
  *(ptr+2) = temp;


}
int main()
{
  int size;
  printf("Enter the size : ");
  scanf("%d",&size);

  if ( size == 2 )
  {
    unsigned short var;

    printf("Enter any number in Hexadecimal : ");
    scanf("%hx",&var);
    char * ptr = (char *)&var; // typecasting the address to 1 byte so that
                              //  when i add that pointer it will be increased 
                             //   by 1.
    swap_short(ptr);
    printf("After conversion : %hX",var);
  }
  else if ( size == 4 )
  {
    unsigned int var;
    printf("Enter any number in Hexadecimal : ");
    scanf("%x",&var);
    char * ptr = (char *)&var;
    swap_int(ptr);
    printf("After conversion : %X",var);
  }


}
