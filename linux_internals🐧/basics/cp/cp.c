#include <stdio.h>
#include <fcntl.h> // contains file control functions
#include <unistd.h> 
#include <errno.h>

void my_cp(int source_fd, int destination_fd){

    char buffer;

    while (read(source_fd,&buffer,1) > 0 ) {

        write(destination_fd,&buffer,1);

    }

}

int main(int argc, char** argv) {

    if ( argc != 3 ){

        printf("[ERROR]: format =>> ./a.out source_file destination_file \n");
        return 1;

    }

    int source_fd = open(argv[1],O_RDONLY); 

    if ( source_fd == -1 ){

        perror("opening file");
        return 1;

    }

    int destination_fd = open(argv[2],O_CREAT|O_EXCL|O_WRONLY,0666);

    if(destination_fd == - 1){

        if ( errno == EEXIST) {

        error_return:

            printf("⚠️Contents are already present do you want to overwrite (y/n) =>> ");

            char option;

            scanf(" %c",&option);

            if ( option == 'y' || option == 'Y') {

                destination_fd = open(argv[2],O_TRUNC|O_WRONLY|O_CREAT,0666);

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

    printf("Successfully copied!\n");

    close(source_fd);

    close(destination_fd);
}
