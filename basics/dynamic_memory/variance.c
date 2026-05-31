/*
--------------------------------------------------------------------------------

Name        : Arjun Vasavan

Date        : 14 - 10 - 2025

Descriptiom : Variance calculation with dynamic arrays

Sample execution: -

Test Case 1:

Enter the no.of elements : 10

Enter the 10 elements:

[0] -> 9
[1] -> 12
[2] -> 15
[3] -> 18
[4] -> 20
[5] -> 22
[6] -> 23
[7] -> 24
[8] -> 26
[9] -> 31

Variance is 40.000000

--------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h> // fot including malloc

float variance(int *, int); // this function will find variance

int main()
{
  printf("Enter the no.of elements : ");
  int n;
  scanf("%d",&n);

  int* arr = malloc(n*sizeof(int));  // creating dynamic memory

  printf("Enter the %d elements : ",n);
  for ( int i = 0 ; i < n ; i++ )
  {
    printf("[%d]->",i);
    scanf(" %d",&arr[i]);
  }

  printf("Variance is %f",variance(arr,n));

}

float variance(int* arr, int n)
{
  int mean;
  for ( int i = 0 ; i < n ; i++ )
  {
    mean+=arr[i]; //  this loop wil find sum of all elements
  }

  mean/=n; // this will find mean

  float var; // for returning float value

  for ( int i = 0 ; i < n ; i++ )
  {
    arr[i] = arr[i] - mean; // for deviation
    arr[i] = arr[i]*arr[i]; // for square of each elements
    var+=arr[i]; // storing sum of that deviation arrays
  }

  return var/n; // returns variance 

}
