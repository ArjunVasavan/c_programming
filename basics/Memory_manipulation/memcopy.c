#include <stdio.h>
#include <string.h> // contain mem malipulation functions
int main(int argc, char** argv) {

    int arr1[] = {3,4};
    int arr2[] = {1,2};


    // memcpy(destination , source,total byte to copy)
    memcpy(arr1,arr2,2*sizeof(int));

    printf("%d %d",arr1[0],arr1[1]);

}
