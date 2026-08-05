#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char** argv) {
    
   int fd = open("output.txt",O_CREAT|O_WRONLY,0666);

    close(1);

    int new_fd = dup(fd);

    printf("Hello\n");
}
