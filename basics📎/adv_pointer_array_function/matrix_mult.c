/*
-------------------------------------------------------------------------------

Name : Arjun Vasavan

Date : 26 - 10 - 2025

Description : Program to find the product of given matrix.

Sample output:
Test case1:
Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :
1      2      3
1      2      3
1      2      3
Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :

1      1     1
2      2     2
3      3     3
Product of two matrix :
14      14      14
14      14      14
14      14      14

Test case 2:
Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :
1      2      3
1      2      3
1      2      3
Enter number of rows : 2
Enter number of columns : 3
Matrix multiplication is not possible

-------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

void read(int rows,int columns,int** matrix) // for reading from user
{

  for ( int i = 0 ; i < rows ; i++ )
  {
    for ( int j = 0 ; j < columns ; j++ )
    {
      scanf("%d",&matrix[i][j]);
    }
  }
}

void write(int rows,int columns,int** matrix) // for printing output
{
  for ( int i = 0 ; i < rows ; i++)
  {
    for ( int j = 0 ; j < columns ; j++ )
    {
      printf("%d ",matrix[i][j]);
    }
    printf("\n");
  }
}
int matrix_mul(int **, int, int, int **, int, int, int **, int, int);

int main()
{
  int **mat_a, **mat_b, **result;

  printf("Enter the number of rows: ");
  int row1;
  scanf("%d",&row1);
  printf("Enter the number of columns: ");
  int column1;
  scanf("%d",&column1);

  mat_a = malloc(row1*sizeof(int*));

  for ( int i = 0 ; i < row1 ; i++ )
  {
    mat_a[i] = malloc(column1*sizeof(int));
  }

  read(row1,column1,mat_a);
  printf("Enter the number of rows: ");
  int row2;
  scanf("%d",&row2);
  printf("Enter the number of columns: ");
  int column2;
  scanf("%d",&column2);

  if ( column1 != row2 || row1 != column2  ) // this should be satisfied 
  {
    printf("Matrix multiplication is not possible\n");
    return 0;
  }
  mat_b= malloc(row2*sizeof(int*));

  for ( int i = 0 ; i < row2 ; i++ )
  {
    mat_b[i] = malloc(column2*sizeof(int));
  }

  int res_row = row1;  // naming result wise to prevent confusion and also
                       // question protoype is mentioning it
  int res_col = column2;
  result = calloc(res_row,sizeof(int*)); // result matrix should be of size 
  // row1*column2

  for ( int i = 0 ; i < res_row ; i++ )
  {
    result[i] = calloc(res_col,sizeof(int));
  }

  read(row2,column2,mat_b);

  if(matrix_mul(mat_a,row1,column1,mat_b,row2,column2,result,res_row,res_col))
  {
    printf("Product of two matrix :");
    write(res_row,res_col,result);
  }
  else 
{
    printf("Error! function not returning !\n");
  }
  // i have written this if else because on question prototype there function 
  // was returning int its unnecessery i think

}

int matrix_mul(int** mat_a, int row1, int column1, int** mat_b,int row2,
               int column2,int** result,int res_row,int res_col)
{
  for ( int i = 0 ; i < row1 ; i++ )
  {
    for ( int j = 0 ; j < column2 ; j++)
    {
      for ( int k = 0 ; k < column1 ; k++ ) // for iterating 1st matrix
      {
        result[i][j] += (mat_a[i][k])*(mat_b[k][i]);
        // mat_a[i][k] means at first matrix iterating  columns after that next row
        // mat_b[k][i] meams at second matrix iterating first rows after that next col
      }
    }
  }

  return 1;
}
