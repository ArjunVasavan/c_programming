#include <stdio.h>
#include <string.h>

static  char str[15] = "Hello"; //all are getting garbage
int main() {
    // char str[15] = "Hello";  // partial initialization occurs here
    // char str[15];
   // strcpy(str, "Hello"); //garbage value comes here 
    for (int i = 0; i < 15; i++) {
        printf("%c ", str[i]);
    }
}

