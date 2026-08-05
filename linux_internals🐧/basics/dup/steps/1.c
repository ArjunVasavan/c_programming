#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void my_dup2(int fd ) {

 int dup1 = dup(1);
    printf("Hello\n");
    fflush(stdout);

    int new_fd = dup2(fd,1);
    printf("World\n");
    fflush(stdout);

    int n_dup = dup2(dup1,new_fd);
    printf("Hello\n");

}

void my_dup1(int fd ) {

    printf("fd --> %d\n",fd);
    int st_fd = dup(1);
    close(1);

    int new_fd = dup(fd);
    printf("Hello\n");
    fflush(stdout);

    int last = dup(st_fd);
    printf("World\n");
    fflush(stdout);

}


int main(int argc, char** argv) {

    int fd;

    int choice = atoi(argv[1]);

    if ( argc == 3 ) {
        if ( choice == 1 ) {
            fd = open(argv[2],O_CREAT|O_EXCL|O_WRONLY,0666);
            printf("We are executing dup1 system call\n");
            if ( fd == -1 ) {

                if ( errno == EEXIST ) {
                    printf("File already exits, do you want to rewrit(y/n)?\n");
                    char ch;
                    scanf("%c",&ch);

                    if ( ch == 'y' ) {

                        fd = open(argv[2],O_WRONLY|O_TRUNC,0666);
                        my_dup1(fd);


                    } else if ( ch == 'n' ) {

                    } else {
                        errno = EINVAL;
                        perror("choice");
                        exit(1);
                    }

                }

            } else {

                my_dup1(fd);

            }
        } else if ( choice == 2 ) {

            fd = open(argv[2],O_CREAT|O_EXCL|O_WRONLY,0666);

            printf("Here were executing dup2\n");

            if ( fd == -1 ) {

                if ( errno == EEXIST ) {

                    printf("File already exits, do you want to rewrit(y/n)?\n");
                    char ch;
                    scanf("%c",&ch);

                    if ( ch == 'y' ) {

                        fd = open(argv[2],O_WRONLY|O_TRUNC,0666);
                        my_dup2(fd);


                    } else if ( ch == 'n' ) {

                    } else {
                        errno = EINVAL;
                        perror("choice");
                        exit(1);
                    }
                }

            } else {
                my_dup2(fd);
            }

        }
    }

}
