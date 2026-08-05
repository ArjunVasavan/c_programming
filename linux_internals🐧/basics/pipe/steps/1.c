#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/ipc.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

int pipe_place = 0;

bool is_pipe_present(char** argv,int argc) {

    for ( int i = 0 ; i < argc ; i++ ) {

        if ( strcmp(argv[i],"|") == 0 ) {
            pipe_place = i;
            argv[i] = NULL;
            printf("%s\n",argv[pipe_place+1]);
            return true;
        }

    }
    return false;
}

int main(int argc, char** argv) {

    if ( is_pipe_present(argv,argc) == false ) {

        errno = EINVAL;
        perror("pipe is not present or not on order");
        exit(EXIT_FAILURE);

    }

    int fd_pipe[2];

    pipe(fd_pipe);

    int stdin_back = dup(0);
    int stdout_back = dup(1);

    pid_t pid = fork();

    if ( pid == 0 ) {

        close(fd_pipe[0]);

        dup2(fd_pipe[1],STDOUT_FILENO);

        execvp(argv[1],argv+1);

        close(fd_pipe[0]);

    } else {

        close(fd_pipe[1]);

        dup2(fd_pipe[0],STDIN_FILENO);  

        execvp(argv[pipe_place+1],argv+(pipe_place+1));

        close(fd_pipe[1]);

    }
}
