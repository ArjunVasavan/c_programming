#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char** argv) {
    
    int file_descriptor = open(argv[1],O_RDONLY);

    if ( file_descriptor == - 1){

        perror("open");
        close(file_descriptor);
    }

    char single_buffer;

    int read_returned_bytes = read(file_descriptor,&single_buffer,1);
    
    if ( read_returned_bytes == 0 ){

        printf("File : %s <EMPTY> ",argv[1]);
        close(file_descriptor);
        return 1;
    }

    do {

        putchar(single_buffer);
    
    }while (read(file_descriptor,&single_buffer,1) > 0 );

    close(file_descriptor);
}
