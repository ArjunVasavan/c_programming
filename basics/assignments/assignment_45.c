 // this is called siamese method

#include<stdlib.h>
#include <stdio.h>
int main()
{
  printf("Enter an Number : ");
  int number;
  scanf("%d",&number);
  int** array = calloc(number,sizeof(int*));
  for ( int i = 0 ; i < number ; i++ )
  {
    array[i] = calloc(number,sizeof(int));
  }

  for ( int i = 0 ; i < number ; i++ )
  {
    for ( int j = 0 ;j < number ; j++ )
    {
      printf("%d ",array[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  int row = 0;
  int column = number/2;
  int value = 1;
  int prev_row = row;
  int prev_column = column;
  array[row][column] = value;
  row-=1;
  column+=1;
  value+=1;
  while ( value <= number*number )
  {
    if ( row < 0 )
    {
      row = number-1;
    }
    if ( column >= number )
    {
      column = 0;
    }
    if ( array[row][column] == 0 )
    {
      array[row][column] = value;  
      prev_row = row;
      prev_column = column;
      row-=1;
      column+=1;
    }
    else 
    {
      row = prev_row+1;
      column = prev_column;
      array[row][column] = value;  
      prev_row = row;
      prev_column = column;
      row-=1;
      column+=1;

    }
      value+=1;
  }

  printf("RESULT =>> \n");
  for ( int i = 0 ; i < number ; i++ )
  {
    for ( int j = 0 ;j < number ; j++ )
    {
      printf("%d ",array[i][j]);
    }
    printf("\n");
  }

}
