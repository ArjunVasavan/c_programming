#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char** argv) {
    // here task is -> 1; Print hello using printf on file.txt
    //  2; print world on teminal using printf


    int file_fd = open("File.txt",O_CREAT|O_WRONLY,0666);

    // now if i delete the stdout i dont know how to get stdout back
    // so im using an backup to store the stdout;

    int backup_stdout_fd = dup(1);

    close(1);

    dup(file_fd);

    printf("Hello");
    fflush(NULL);
    // here if i didnt used fflush it will stored on stdout till it get full or those other 
    // 5 conditions gets satisfied to print on terminal

    close(1);
    // here when i close stdout the hello and stdout are removed so thats why
    // were flushing early else in this code it will wait for 
    // normal termination 

    dup(backup_stdout_fd);

    printf("World");
    fflush(NULL);


}
