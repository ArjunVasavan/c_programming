/*

So were here trying to learn WNOHANG

*/
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char** argv) {
    
    pid_t pid = fork();

    if ( pid > 0 ) { // parent

        int status;

        while ( waitpid(pid,&status,WNOHANG) == 0 ) {
        
            printf("Parent is running child is still alive\n");
            sleep(1);

        }

        if ( WIFEXITED(status)) {
            printf("Child exited with status %d\n",WEXITSTATUS(status));
        }

    } else { // child
    
        sleep(5);

    }

}
