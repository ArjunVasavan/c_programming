#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char** argv) {

    if ( argc != 2 ) {

        errno = EINVAL;
        perror("argument should only be 2");
        exit(1);

    }

    struct flock lock_details;

    int fd = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0666);

    if ( fd == -1 ) {
        fprintf(stdout,"[ERROR]: fd is -1 \n");
    }

    pid_t pid = fork();


    lock_details.l_whence = SEEK_SET;
        // lock_details.l_pid = {KERNEL FILLS IT};
    lock_details.l_start = 0;
    lock_details.l_len = 0;
    lock_details.l_type = F_WRLCK;

    if ( pid == 0 ) { // child

        printf("Child trying to acquire lock\n");

        if ( fcntl(fd,F_SETLKW,&lock_details) == -1 ) {
            perror("fcntl");
            exit(1);
        }

        printf("Child acquired\n");
        write(fd,"CHild writing\n",15);
        sleep(2);
        // do operation


        lock_details.l_type = F_UNLCK;
        if ( fcntl(fd,F_SETLK,&lock_details) == -1 ) {
            perror("fcntl");
            exit(1);
        }

        printf("Child released\n");
        close(fd);
        exit(0);


    } else { // parent

        sleep(1); // for ensuring child does it first
        printf("Parent trying to lock\n");
        if ( fcntl(fd,F_SETLKW,&lock_details) == -1 ) {
            perror("fcntl");
            exit(1);
        }

        printf("Parent locked\n");
        write(fd,"Parent trying to write\n",24);
        // do operation


        lock_details.l_type = F_UNLCK;
        if ( fcntl(fd,F_SETLKW,&lock_details) == -1 ) {
            perror("fcntl");
            exit(1);
        }

        printf("Parent lock released\n");
        close(fd);
        exit(0);


    }


}
