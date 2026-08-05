#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char** argv) {

    //TODO:
    //1 -> using printf print on file.txt
    //2-> using printf print on terminal


    int file_fd = open("file.txt",O_CREAT|O_WRONLY,0666);

    int stdout_backup_fd = dup(1);

    dup2(file_fd,1);

    printf("Hello");  // for printing on file
    fflush(NULL);

    dup2(stdout_backup_fd,1);

    printf("World");
    fflush(NULL);


    close(file_fd);
    close(stdout_backup_fd);

}
