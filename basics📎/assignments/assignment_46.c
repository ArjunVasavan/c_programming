#include <stdlib.h>
#include <stdio.h>

void write(int number_of_rows,int* column_array,float** array)
{
  for ( int i = 0 ; i < number_of_rows ; i++ )
  {
    for ( int j = 0 ; j <= column_array[i] ; j++ )
    {
    printf("%f ",array[i][j]);
    }
    printf("\n");
  }
}
int main()
{
  int number_of_rows;

  printf("Enter the number of rows : ");
  scanf("%d",&number_of_rows);

  float** array =malloc(number_of_rows*sizeof(int*));

  int column_array[number_of_rows];

  for ( int i = 0 ; i < number_of_rows ; i++ )

  {
    printf("Enter the number of columns in row[%d] ->> ",i);
    scanf("%d",&column_array[i]);
    array[i] = malloc((column_array[i]+1)*sizeof(float));
  }

  for ( int i = 0 ; i < number_of_rows ; i++ )
  {
    
    float average = 0;
    printf("Enter %d values for row[%d] : ",column_array[i],i);
    for ( int j = 0 ; j < column_array[i] ; j++ )
    {
      scanf("%f",&array[i][j]);
      average+=array[i][j];
    }
    average/=column_array[i];
    array[i][column_array[i]] = average;
  }

  printf("Before Sorting : \n");
  write( number_of_rows,column_array,array);

  for ( int i = 0  ; i < number_of_rows - 1 ; i++ )
  {
    for ( int j = 0 ; j < number_of_rows - i - 1 ; j++ )
    {
      if ( array[j][column_array[j]] > array[i+1][column_array[j+1]] )
      {
        float* temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;

        column_array[j] = column_array[j]^column_array[j+1];
        column_array[j+1] = column_array[j]^column_array[j+1];
        column_array[j] = column_array[j]^column_array[j+1];

      }
    }
  }


  printf("After sorting :\n");
  write( number_of_rows,column_array,array);
}
