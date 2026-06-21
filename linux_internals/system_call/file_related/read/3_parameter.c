#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char** argv) {
    
    int fd = open("newfile.txt",O_CREAT|O_RDONLY,0666);

    if( fd == -1){
        perror("open");

        close(fd);
    }



}
