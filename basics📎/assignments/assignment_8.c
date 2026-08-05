#include <stdio.h>

void sort(int* arr,int n)
{
  for( int i = 0 ; i < n - 1 ; i++ )
  {
    for ( int j = 0 ; j < n - i - 1 ; j++ )
    {
      if ( arr[j] > arr[j+1])
      {
        arr[j] = arr[j] ^ arr[j + 1];
        arr[j+1] = arr[j] ^ arr[j+1];
        arr[j] = arr[j] ^ arr[j+1];
      }
    }
  }
}

int main()
{
  printf("enter th n value of array 1 : ");
  int n1,n2;
  scanf("%d",&n1);
  int arr1[n1];

  printf("enter th n value of array 2 : ");
  scanf("%d",&n2);
  int arr2[n2];

  printf("Enter element by element for array 1 : ");
  for ( int i = 0 ; i < n1 ; i++ )
  {

    scanf("%d",&arr1[i]);

  }

  printf("Enter element by element for array 2 : ");
  for ( int i = 0 ; i < n2 ; i++ )

  {

    scanf("%d",&arr2[i]);

  }

  sort(arr1,n1);
  sort(arr2,n2);

  if ( (n1 & 1 )== 0 )
  {
    printf("Median of array 1 : %.2f\n",((float)arr1[(int)(n1 / 2)] + (float)arr1[(int)((n1 / 2) - 1)]) / 2.0);
    // look why other one is showing error and understand to manipulate
  }
  else 
{
    printf("Median of array 1: %d \n",arr1[n1/2]);

  }

  if ( (n2 & 1 )== 0 )
  {
    printf("Median of array 2 : %g\n",(arr2[(n2)/2]+arr2[(n2/2)-1])/2.0);
  }
  else 
{
    printf("Median of array 2 : %d \n",arr2[n2/2]);

  }


}
