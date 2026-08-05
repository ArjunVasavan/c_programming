#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char** argv) {
    
    pid_t pid = fork();

    if ( pid == 0 ) { // child

        sleep(1);

        execvp(argv[1],argv+1);


    } else {

        int status;
        printf("Child created with pid %d\n",pid);
        wait(&status);

        if ( WIFEXITED(status)) {
            printf("Child exited\n");
        }
    }

}
