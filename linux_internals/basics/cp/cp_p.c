/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 
NAME: Arjun Vasavan 
DATE: 02-12-2025
Description : program to create an cp command replica 
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 
SAMPLE EXECUTION : 

$ gcc cp_replica.c -o mycp
$ ./mycp source.txt destination.txt
Successfully copied!

$ ./mycp -p source.txt destination2.txt
Changed permission 
Successfully copied!

$ ./mycp source.txt destination.txt
⚠️Contents are already present do you want to overwrite (y/n) =>> y
Successfully copied!

$ ./mycp source.txt destination.txt
⚠️Contents are already present do you want to overwrite (y/n) =>> n
Exiting...

$ ./mycp
[ERROR]: format =>> ./a.out source_file destination_file 

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 
*/
#include <stdio.h>
#include <string.h>
#include <fcntl.h> // contains file control functions
#include <unistd.h> 
#include <errno.h>
#include <sys/stat.h>
#include <stdlib.h>

void my_cp(int source_fd, int destination_fd){
    char buffer;
    while (read(source_fd,&buffer,1) > 0 ) {
        if(write(destination_fd,&buffer,1) == -1){
            printf("Error Writing the destination file\n");
            exit(1);
        }
    }
}

int main(int argc, char** argv) {
    char* source_argument;
    char* destination_argument;
    
    if ( argc == 3 ){
        source_argument = argv[1];
        destination_argument = argv[2];
    } else if (argc == 4) {
    
        if ( strcmp(argv[1],"-p") != 0 ){
            printf("[ERROR]: you can use only -p for 4 argument\n");
            return 1;
        }
        source_argument = argv[2];
        destination_argument = argv[3];
    } else {
        printf("[ERROR]: format =>> ./a.out source_file destination_file \n");
        return 1;
    }
    
    int source_fd = open(source_argument,O_RDONLY); 
    if ( source_fd == -1 ){
        perror("opening file");
        return 1;
    }
    
    int destination_fd = open(destination_argument,O_CREAT|O_EXCL|O_WRONLY,0666);
    if(destination_fd == - 1){
        if ( errno == EEXIST) {
        error_return:
            printf("⚠️Contents are already present do you want to overwrite (y/n) =>> ");
            char option;
            scanf(" %c",&option);
            if ( option == 'y' || option == 'Y') {
                destination_fd = open(destination_argument,O_TRUNC|O_WRONLY|O_CREAT,0666);
            } else if (option == 'n' || option == 'N') {
                printf("Exiting...\n");
                close(source_fd);
                return 1;
            }
            else {
                printf("Enter y or n only\n");
                goto error_return;
            }
        } else {
            perror("opening destination");
            close(source_fd);
            return 1;
        }
    }
    
    my_cp(source_fd,destination_fd);
    
    if(argc == 4){
        struct stat chmod_variable;
        fstat(source_fd,&chmod_variable);
        fchmod(destination_fd,chmod_variable.st_mode);
        printf("Changed permission \n");
    }
    
    printf("Successfully copied!\n");
    close(source_fd);
    close(destination_fd);
}
