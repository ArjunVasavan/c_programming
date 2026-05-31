/*
--------------------------------------------------------------------------------

Name : Arjun Vasavan

Date : 24 - 10 - 2025

Description : Program to implement fragments using Array of Pointers

Sample Execution:

Test case 1:

Enter no.of rows : 3
Enter no of columns in row[0] : 4
Enter no of columns in row[1] : 3
Enter no of columns in row[2] : 5
Enter 4 values for row[0] : 1 2 3 4
Enter 3 values for row[1] : 2 5 9
Enter 5 values for row[2] : 1 3 2 4 1

Before sorting output is:

1.000000 2.000000 3.000000 4.000000 2.500000

2.000000 5.000000 9.000000 5.333333

1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

After sorting output is:

1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

1.000000 2.000000 3.000000 4.000000 2.500000

2.000000 5.000000 9.000000 5.333333

--------------------------------------------------------------------------------
*/


#include <stdlib.h>
#include <stdio.h>

// This functuon prints the 2d array
void print_function(int row_size,int* column_size,float** arr )
{
  printf("\n");
  for ( int i = 0 ; i < row_size ; i++ )
  {
    for ( int j = 0 ; j <= column_size[i] ; j++ )
    {
      printf("%f ",arr[i][j]); // Printing on float  
    }
    printf("\n");
  }
}
// This function is to read columns dynamically
void read_column(int row_size,int* column_size,float** arr)
{
  for ( int i = 0 ; i < row_size ; i++ )
  {
    printf("Enter the no of columns in row[%d] : ",i);
    scanf("%d",&column_size[i]);// here column size stores size of each columns 
  }

  for ( int i = 0 ; i < row_size ; i++ )
  {
    printf("Enter %d values for arr[%d] : ",column_size[i],i);

    float average = 0; // Here we are taking average directly when reading 
    arr[i] = malloc((column_size[i]+1)*sizeof(float));
    // in the above one we are dynamically creating columns from column_size 
    // array with size of float for each dynamic allocation

    for ( int j = 0 ; j < column_size[i] ; j++ )
    {
      scanf("%f",&arr[i][j]); // reading and storing it to array
      average+=arr[i][j]; // average is taking the sum of readed values
    }

    average = average/column_size[i]; // we divide it by column_size to get avg
    arr[i][column_size[i]] = average; // storing that average to the end of arr

  }
}

void fragments(int row_size,int* column_size,float** arr)
{
  // this is an bubble sort
  for ( int i = 0 ; i < row_size - 1 ; i++ ) // loop through whole row
  {
    for ( int j = 0 ; j < row_size - i - 1 ; j++ ) // inner looping row
    {
      if( arr[j][column_size[j]] > arr[j+1][column_size[j+1]] ) // comparing
      {

        float* temp = arr[j]; // an float pointer stores address of columns
        arr[j] = arr[j+1]; // swapping logic
        arr[j+1] = temp;
        // exor swapping logic
        column_size[j] = column_size[j] ^ column_size[j+1];
        column_size[j+1] = column_size[j] ^ column_size[j+1];
        column_size[j] = column_size[j] ^ column_size[j+1];

      }
    }
  }

}

void free_function(int row_size,float** arr)
{

  for ( int i = 0 ; i < row_size ; i++ )
  {
    free(arr[i]);
  }

}

int main()
{
  int row_size;

  printf("Enter the row : "); 
  scanf("%d",&row_size);

  float* arr[row_size];
  int column_size[row_size];

  read_column(row_size,column_size,arr);

  printf("Before sorting output is : \n");
  print_function(row_size,column_size,arr);

  fragments(row_size,column_size,arr);

  printf("After sorting output is : \n");
  print_function(row_size,column_size,arr);

  free_function(row_size,arr);

}
