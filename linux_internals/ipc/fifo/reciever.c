#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>


#define MYFIFO "/tmp/MYFIFO"

int main(int argc, char** argv) {
    
    int fdr = open(MYFIFO, int oflag, ...)

    if ( fdr < 0 ){

        perror("open failed");
        return 1;
    }

    printf("FIFO CREATED\n");

    int fdw = open(MYFIFO,O_WRONLY);

    char buff[20] = "Hello";

    write(fdw,buff,strlen(buff)+1);

    printf("COMPLETED\n");

    close(fdw);


}
