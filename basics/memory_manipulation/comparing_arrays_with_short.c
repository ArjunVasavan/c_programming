#include <stdio.h>
#include <string.h> // contain mem malipulation functions
int main(int argc, char** argv) {

    int arr1[] = {1,2}; //  0 0 0 1 , 0 0 0 2 // 4 bytes for int
    short int arr2[] = {1,2}; // 0 1 , 0 2 // short int is 2 bytes only

    //similair to strcmp
    //on passing size pass the smallest array 
    //it will compare byte by byte
    if(memcmp(arr1,arr2,2*sizeof(short int) ) == 0 ) {

        printf("Array are same\n");

    } else {

        printf("Array is not same\n");
    }


}
