#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <string.h>
#include <sys/wait.h>

void pipe_check(char** argv, int* pipe_places, int argc ) {

    int count = 1;

    for( int i = 0 ; i < argc ; i++ ) {

        if ( strcmp(argv[i],"|") == 0 ) {

            argv[i] = NULL;
            pipe_places[count] = i;
            count+=1;
        }
    }
}

int main(int argc, char** argv) {

    int pipe_places[3];
    pipe_places[0] = 1;

    pipe_check(argv,pipe_places,argc);

    char** first_command = &argv[1];
    char** second_command = &argv[(pipe_places[1] + 1)];
    char** third_command = &argv[(pipe_places[2]+1)];

    int f_pipe[2];
    int s_pipe[2];
    pipe(f_pipe);
    pipe(s_pipe);

    pid_t f_pid = fork();

    if ( f_pid == 0 ) {

        close(f_pipe[0]); // closed read

        dup2(f_pipe[1],STDOUT_FILENO);

        close(f_pipe[1]);
        close(s_pipe[0]);
        close(s_pipe[1]);

        execvp(argv[1],first_command);
    }

    pid_t s_pid = fork();

    if ( s_pid == 0 ) {
        close(f_pipe[1]);
        dup2(f_pipe[0],STDIN_FILENO);
        close(s_pipe[0]);
        dup2(s_pipe[1],STDOUT_FILENO);

        close(f_pipe[0]);
        close(s_pipe[1]);

        execvp(argv[(pipe_places[1]+1)],second_command);
    }

    pid_t t_pid = fork();

    if ( t_pid == 0 ) {

        close(s_pipe[1]);

        dup2(s_pipe[0],STDIN_FILENO);

        close(s_pipe[1]);
        close(f_pipe[0]);
        close(f_pipe[1]);

        execvp(argv[(pipe_places[2]+1)],third_command);
    }

    close(f_pipe[0]);
    close(f_pipe[1]);
    close(s_pipe[0]);
    close(s_pipe[1]);

    waitpid(f_pid,NULL,0);
    waitpid(s_pid,NULL,0);
    waitpid(t_pid,NULL,0);

}
