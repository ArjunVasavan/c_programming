#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int child_pid;
int child_status;

int main(int argc, char** argv) {
    
    int ret;

    ret = fork();

    switch (ret) {
    
        case -1:{
            perror("fork");
            exit(1);
        }

        case 0: {
            printf("This is child process\n");
            exit(0);
        }

        default: {
            printf("This is parent process\n");
            wait(&child_status);
            exit(0);
        }

    }

}
