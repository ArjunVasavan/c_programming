#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char** argv)
{
    int fd = open("file.txt",O_RDONLY);

    if ( fd == -1){

        perror("Error Could not open the file\n");

    }

    printf("File discriptor value : %d\n",fd);

    int rd;
    char buffer;

    while(read(fd,&buffer,1) != 0 ){

        putchar(buffer);

    }

}
