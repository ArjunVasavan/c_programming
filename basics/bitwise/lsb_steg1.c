 // what i learned from this is that when number goes like 1,2,3,4,5,6,7,8,9 like wise and if You
 // try to change everones lsb to 1 out put will be an ODD number // ARJUNS SEQUENCE

#include <stdio.h>

void print(unsigned char ch )
{
  for ( int i = 7 ; i >= 0 ; i-- )
  {
    if (( ch & ( 1 << i) ) == 0 )
    {
      printf("0 ");
    }
    else {
      printf("1 ");
    }
  }
  printf("\n");
}
int main()
{
  int size;
  printf("Enter the size of the array : ");
  scanf("%d",&size);

  unsigned char arr[size];

  printf("Enter the elements : ");

  int value;
  for (int i = 0 ; i < size ; i++ )
  {
    scanf("%d",&value);
    arr[i] = (unsigned char)value;

  }

  int choice;
  printf("Are You entering an character or integer\n1.Integer\n2.Character\nChoice=>>");
  scanf("%d",&choice);

  unsigned char character;
  if ( choice == 1 )
  {
    printf("Enter the integer : ");
    scanf("%d",&value);
    character = (unsigned char)value;
  }
  else 
  {
  printf("Enter the Character : ");
  scanf(" %c",&character);
  }

  printf("Entered Character in Binary =>> ");
  print(character);

  printf("\n");
  int count = 7;
  for ( int i = size-1 ; i >= 0  ; i-- )
  {
    arr[size - i - 1 ] = arr[size - i - 1 ] & (~1); // setted zero to the end

    unsigned char mask = ((character & (1<<count))>>count); // we are getting that thing
    arr[size - i - 1] = arr[size - i - 1 ] | mask;
    count-=1;

  }
  printf("\n");
  for ( int i = 0 ; i < size ; i++ )
  {
    printf("%d =>> ",i);
    print(arr[i]);
    printf("\n");
  }

  printf("\nResultant array :\n\n");

  for ( int i = 0 ; i < size ; i++ )
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
}
