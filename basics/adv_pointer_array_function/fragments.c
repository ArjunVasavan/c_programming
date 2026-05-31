#include <stdlib.h>
#include <stdio.h>

int fragments(int, int *[]);

int main()
{
  int row_size;

  printf("Enter the row : ");
  scanf("%d",&row_size);

  float* arr[row_size];
  int column_size[row_size];
  for ( int i = 0 ; i < row_size ; i++ )
  {
    printf("Enter the number of column size : ");
    scanf("%d",&column_size[i]);
  }

  for ( int i = 0 ; i < row_size ; i++ )
  {
    printf("Enter %d values for arr[%d]",column_size[i],i);

    float average = 0;
    arr[i] = malloc((column_size[i]+1)*sizeof(float));
    for ( int j = 0 ; j < column_size[i] ; j++ )
    {
      scanf("%f",&arr[i][j]);
      average+=arr[i][j];
    }
    average = average/column_size[i];
    arr[i][column_size[i]] = average;
  }

  printf("Before sorting output is : \n");

  for ( int i = 0 ; i < row_size ; i++ )
  {
    for ( int j = 0 ; j <= column_size[i] ; j++ )
    {
      printf("%f ",arr[i][j]);
    }
    printf("\n");
  }


  for ( int i = 0 ; i < row_size - 1 ; i++ )
  {
    
    for ( int j = 0 ; j < row_size - i - 1 ; j++ )
    {
      if( arr[j][column_size[j]] > arr[j+1][column_size[j+1]] )
      {

        float* temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;

        column_size[j] = column_size[j]^column_size[j+1];
        column_size[j+1] = column_size[j]^column_size[j+1];
        column_size[j] = column_size[j]^column_size[j+1];
      }
    }
  }

  printf("After sorting output is : \n");

  for ( int i = 0 ; i < row_size ; i++ )
  {
    for ( int j = 0 ; j <= column_size[i] ; j++ )
    {
      printf("%f ",arr[i][j]);
    }
    printf("\n");
  }

}
