#include<stdio.h>


void read( int row , int column , int arr[row][column] )
{
  printf("Enter the elements =>> \n");

  for ( int i = 0 ; i < row ; i++ )
  {
    for ( int j = 0 ; j < column ; j++ )
    {
      scanf("%d",&arr[i][j]);
    }
  }

}
int largest( int row , int column , int arr[row][column] )
{
  int largest = arr[0][0];

  for ( int i = 0 ; i < row ; i++ )
  {
    for ( int j = 0 ; j < column ; j++ )
    {
      if ( largest < arr[i][j] )
      {
        largest = arr[i][j];
      }
    }
  }

  return largest;
}

int main()
{
  printf("Enter the rows of the array : ");
  int row;
  scanf("%d",&row);
  printf("Enter the column of the array : ");
  int column;
  scanf("%d",&column);

  int arr[row][column];

  read(row,column,arr);

  printf("largest number you have entered is %d \n",largest(row,column,arr));

}
