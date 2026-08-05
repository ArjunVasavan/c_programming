/*
--------------------------------------------------------------------------------

Name: Arjun Vasavan

Date: 08/12/2025

Description : Program to avoid child becoming zombie without blocking parent

--------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char** argv) {


    pid_t pid = fork(); // creates child process

    int status; // creating an integer status to 

    if ( pid > 0 ){ // this process is an parent 

        printf("A child created with pid %d\n",pid); // prints the pid in parent
        
        while (waitpid(pid,&status,WNOHANG) == 0 ) {
            printf("parent is running\n");
            sleep(1);
        }
        // when the parent gets signal that child has stopped 
        if ( WIFEXITED(status)){
            printf("child %d terminated normally with  exit status %d parent terminating\n"
                   ,pid,WEXITSTATUS(status));
        }

    } else {

        sleep(5);

    }
}
