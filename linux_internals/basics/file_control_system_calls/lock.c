#include <stdio.h>
#include <fcntl.h> // fcntl
#include <unistd.h> // fork , getpid, dup2
int main(int argc, char** argv) {

    if ( argc != 2 ){

        fprintf(stderr,"[ERROR]: enter 2 inputs only");
    } 


    struct flock variable; // this structure contains file locking
    

    int fd = open(argv[1],O_CREAT|O_WRONLY,0666);

    dup2(fd,1);

    pid_t pid = fork(); // creates an child process

    if ( pid > 0 ){ // parent process section

        printf("PARENT PROCESS\n");

        variable.l_type = F_WRLCK; // lock type: exclusive write locking
                                  //[only one file can lock at a time] 

        //The word “whence” comes from old English and means
        //"from what place" or "from where"

        variable.l_whence = SEEK_SET; // start from beginning of file
                                     //[tells kernel where offset begins] 
        variable.l_start = 0; // [lock begins at byte 0 of file ] 
        
        variable.l_len = 0; // we dont know the limit to gived 0
                            //[lock form l_start until end of file ] 

        variable.l_pid = getpid();

        fcntl(fd,F_SETLKW,&variable);

        // F_SETLKW : Try to set the lock described in variable, 
        // but if you cannot because someone else owns a conflicting lock,
        // go to sleep until the lock becomes available.
        


        for ( int i = 2 ; i <= 15 ; i++ ){


            int j ;
            for (  j = 2 ; j*j <= i ; j++){

                if ( i % j == 0 ){
                    break;
                }
            }

            if ( j*j > i ){

                printf("%d ",i);
            }

        }

        printf("\n");

        variable.l_type = F_UNLCK;

        fcntl(fd,F_SETLKW,&variable);

        
    } else {
    
        printf("CHILD PROCESS\n");

        variable.l_type = F_SETLKW;
        variable.l_whence = SEEK_SET;
        variable.l_start = 0;
        variable.l_len = 0;
        variable.l_pid = getpid();

        fcntl(fd,F_SETLKW,&variable);

        int first = 0;
        int second = 1;
        int fib = 0;

        while (fib <= 10) {

            printf("%d ",fib);

            first = second;

            second = fib;

            fib = first + second;

        }

        printf("\n");

        variable.l_type = F_UNLCK;

        fcntl(fd,F_SETLKW,&variable);

    }

}
