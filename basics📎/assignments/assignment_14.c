#include <stdio.h>

int seclarge(int* arr,int n)
{
  int largest = arr[0];
  int smallest = arr[0];
  for ( int i = 0 ; i < n ; i++  )
  {
    if ( largest < arr[i] )
    {
      largest = arr[i];
    }

    if ( smallest > arr[i] )
    {
      smallest = arr[i];
    }
  }

  int second = smallest;

  for ( int i = 0 ; i < n ; i++ )
  {

    if ( second < arr[i] && arr[i] < largest )
    {
      second = arr[i];
    }

  }

  return second;
}

int main()
{
   printf("Enter the size of the array : ");
  int size;
  scanf("%d",&size);

  printf("Enter the elements : ");

  int arr[size];
  for ( int i = 0 ; i < size ; i++ )
  {
    scanf("%d",&arr[i]);
  }

  printf("second largest element is %d \n",seclarge(arr,size));
}
