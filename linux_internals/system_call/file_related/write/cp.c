#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char** argv) {
    
    if ( argc != 3){

        fprintf(stderr,"Invalid Syntax 󰍳  \n");
        return 1;
    }

    int fd_read = open(argv[1],O_RDONLY);

    if ( fd_read == -1){

        fprintf(stderr,"[ERROR]: file is not present\n");
        return 1;
    }

    int fd_write = open(argv[2],O_CREAT|O_WRONLY,0666);
    
    char buffer[10] = {0};

    int ret;
    while ( (ret = read(fd_read,buffer,10)) && ret != 0 ) {
        write(fd_write,buffer,ret);
    }

}
