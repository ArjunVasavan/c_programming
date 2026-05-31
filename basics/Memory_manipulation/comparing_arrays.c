#include <stdio.h>
#include <string.h> // contain mem malipulation functions
int main(int argc, char** argv) {

    int arr1[] = {1,2};
    int arr2[] = {1,2};

    //similair to strcmp
    if(memcmp(arr1,arr2,2*sizeof(int) ) == 0 ) {

        printf("Array are same\n");

    } else {

        printf("Array is not same\n");
    }


}
