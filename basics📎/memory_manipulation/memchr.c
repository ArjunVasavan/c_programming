#include <stdio.h>
#include <string.h> // contain mem malipulation functions
int main(int argc, char** argv) {

    int arr1[] = {3,4}; // 0 0 0 3   0 0 0 4
    int arr2[] = {1,2};

    // to find an certain byte

    if(memchr(arr1,0,sizeof(int)*2) == NULL )
    {
        printf("Didnt find it\n");
    }/// find byte with value 0 and find till sizeof(int)*2 bytes
    // if it finds it will return the pointer where it find if doesnt find its NULL

    else {
    
        printf("Founded it");
    }

}
