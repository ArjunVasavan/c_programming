#include<stdio.h>

// Input matrix elements
void scan_arr(int row, int column, int arr[row][column])
{
  printf("Enter the elements : ");
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }
}

// Display matrix
void print_arr(int row, int column, int arr[row][column])
{
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

// Transpose matrix (swap across diagonal)
void transpose(int row, int column, int arr[row][column])
{
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      if (i < j) 
      {
        int temp = arr[i][j];
        arr[i][j] = arr[j][i];
        arr[j][i] = temp;
      }
    }
  }
}

// Reverse rows (swap first row with last, second with second-last, etc.)
void reverseRows(int row, int column, int arr[row][column])
{
  for (int i = 0; i < row / 2; i++)
  {
    for (int j = 0; j < column; j++)
    {
      int temp = arr[i][j];
      arr[i][j] = arr[row - i - 1][j];
      arr[row - i - 1][j] = temp;
    }
  }
}

int main()
{
  int row, column;
  printf("Enter the row : ");
  scanf("%d", &row);
  printf("Enter the column : ");
  scanf("%d", &column);
  
  int arr[row][column];
  scan_arr(row, column, arr);
  
  // Rotate matrix 90 degrees clockwise
  transpose(row, column, arr);
  reverseRows(row, column, arr);
  
  printf("\nRotated matrix:\n");
  print_arr(row, column, arr);
  
  return 0;
}
