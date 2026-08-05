#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <sys/signal.h>
#include <unistd.h>
#include <sys/wait.h>

int status;

void handler () {

    printf("handler called\n");
    wait(&status);


    if( WIFEXITED(status) ) {

        printf("Child exited with %d\n",WEXITSTATUS(status));
    }
}

int main(int argc, char** argv) {

    signal(SIGCHLD,handler);

    pid_t pid = fork();

    if ( pid == -1 ) {
        perror("FORK");
    }

    if ( pid == 0 ) { // Child 

        printf("CHILD PROCESS\n");
        return 0;

    } else { // PARENT

        sleep(2);

        for ( int i = 0 ; i <= 3 ; i++ ) {

            printf("PARENT PROCESS\n");

        }

        printf("Parent Terminated\n");

        return 0;
    }
}
