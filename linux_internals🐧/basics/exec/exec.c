/*
--------------------------------------------------------------------------------
Name: Arjun Vasavan

Description: create child process to execute command passed through command line

Sample execution :

1. No args passed (Print usage info)

./exe_child Usage: ./exe_child args...

2. Valid arg. passed

./exe_child date
This is the CHILD process, with id 11612

Wed Apr  4 13:27:19 IST 2012
Child exited with status 0

--------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc, char** argv) {

    if ( argc == 1){
        printf("./exe_child Usage: ./exe_child args...\n");
        return 1;
    }

    pid_t pid = fork();
    int status;

    if ( pid > 0 ){ // parent

        wait(&status);
        if ( WIFEXITED(status)){
            printf("Child exited with number %d\n",WEXITSTATUS(status));
        }

    } else { // child
        printf("This is child process with id %d\n",getpid());
        execvp(argv[1],argv+1);
    }

}
