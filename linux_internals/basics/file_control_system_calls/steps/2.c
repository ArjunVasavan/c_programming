#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

bool isprime(int n) {

    if ( n <= 1 ) return false; // 0 , 1 , and negatives are not prime
    if ( n == 2 || n == 3 ) return true; // 2 and 3 are prime
    if ( n % 2 == 0 ) return false; // even numbers > 2 are not prime


    for ( int i = 2 ; i*i <= n ; i++ ) {
        if ( n % i == 0 ) {
            return false;
        }
    }

    return true;
}

void prime() {

    for ( int i = 0 ; i <= 15 ; i++ ) {

        if ( isprime(i) == true ) {
            printf("%d ",i);
        }

    }

    printf("\n");
}

void fibonacci( void ) {

    int first = 0;
    int second = 1;
    int fib = 0;

    while(fib <= 10 ) {
        printf("%d ",fib);
        first = second;
        second = fib;
        fib = first+second;
    }

    printf("\n");
}

int main(int argc, char** argv) {
    
    if ( argc != 2 ) {
        errno = EINVAL;
        perror("format : ./a.out <file.txt> ");
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1],O_WRONLY|O_TRUNC|O_CREAT,0666);

    if ( fd == -1 ) {
        perror("opening argv \n");
        exit(EXIT_FAILURE);
    }

    struct flock lock_details;

    dup2(fd,1);

    pid_t pid = fork();

    lock_details.l_type = F_WRLCK;
    lock_details.l_len = 0; // till EOF
    lock_details.l_start = 0;
    lock_details.l_whence = SEEK_SET;

    if ( pid == 0 ) {

        printf("Child is trying to lock\n");

        if ( fcntl(fd,F_SETLKW,&lock_details) == -1 ) {
            perror("fcntl");
            exit(EXIT_FAILURE);
        }

        printf("Child successfully locked\n");

        prime();
        
        if ( fcntl(fd,F_SETLKW,&lock_details) == -1 ) {
            perror("fcntl");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);

    } else {

        sleep(1);
        printf("Parent trying to lock \n");

        if ( fcntl(fd,F_SETLKW,&lock_details) == -1 ) {
            perror("fcntl");
            exit(EXIT_FAILURE);
        }

        printf("Parent locked succesfully\n");

        fibonacci();

        if ( fcntl(fd,F_SETLKW,&lock_details) == -1 ) {
            perror("fcntl");
            exit(EXIT_FAILURE);
        }

    }

    exit(EXIT_SUCCESS);

}
