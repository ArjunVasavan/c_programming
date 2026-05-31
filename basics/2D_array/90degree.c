#include<stdio.h>
void scan_arr(int row,int column,int arr[row][column])
{
  printf("Enter the elements : ");
  for ( int i = 0 ; i < row ; i++ )
  {
    for ( int j = 0 ; j < column ; j++ )
    {
      scanf("%d",&arr[i][j]);
    }
  }
}
void print_arr(int row,int column,int arr[row][column])
{
  for ( int i = 0 ; i < row ; i++ )
  {
    for ( int j = 0 ; j < column ; j++ )
    {
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }

}

void transpose(int row, int column, int arr[row][column] )
{
  for ( int i = 0 ; i < row ; i++ )
  {
    for ( int j =0 ; j < column ; j++ )
    {
      if ( i < j ) 
      {
        int temp = arr[i][j];

        arr[i][j] = arr[j][i];

        arr[j][i] = temp;
      }
    }
  }
}

// for reversing 

void rev(int column , int* arr)
{
  for ( int i = 0 ; i < column/2 ; i++ )
  {
    int temp = arr[i];
    arr[i] = arr[column -  i - 1];
    arr[column - i - 1] = temp;

  }
}
// now swapping rows

void rowrev(int row, int column , int arr[row][column] )
{
  for ( int i = 0 ; i < row ; i++)
  {
    rev(column,arr[i]);
  }
}
int main()
{
  int row,column;
  printf("Enter the row : ");
  scanf("%d",&row);
  printf("Enter the column : ");
  scanf("%d",&column);

  int arr[row][column];

  scan_arr(row,column,arr);
  transpose(row,column,arr);
  rowrev(row,column,arr);
  printf("\n");
  print_arr(row,column,arr);
}
