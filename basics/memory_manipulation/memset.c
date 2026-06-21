#include <stdio.h>
#include <string.h> // contain mem malipulation functions
int main(int argc, char** argv) {

    int arr1[] = {3,4};
    int arr2[] = {1,2};

    memset(arr1,0,2*sizeof(int)); // set 2*sizeof(int ) bytes int arr1 as zero

    memset(arr2,1,2*sizeof(int)); // looks like arr1: 01010101 01010101 // all bytes are turned to 1 

    printf("array 1 :  %d %d\n",arr1[0],arr1[1]);
    printf("array 2 :  %d %d\n",arr2[0],arr2[1]);

}
