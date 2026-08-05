#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv) {
    
    printf("Executing my ls :) \n");
    execlp("/bin/ls","ls",NULL);

}
