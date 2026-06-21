}/* --------------------------------------------------------------------------------
   Name        : Arjun Vasavan
   Description : Implement communication between three processes using two pipe
   Sample Execution :
   ./three_pipes (No arguments)
   Error: No arguments passed
   Usage: ./three_pipes <cmd1> '|' <cmd2> '|' <cmd3>
   
   2. ./pipe ls -l '|' grep
   Error: Insufficient arguments passed
   Usage: ./pipe <cmd1> '|' <cmd2> '|' <cmd3>
   
   3. ./pipe ls -l '|' grep "pattern" '|' wc -l
   5       5       25
   -------------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    // Check if no arguments passed
    if (argc < 2) {
        printf("Error: No arguments passed\n");
        printf("Usage: %s <cmd1> '|' <cmd2> '|' <cmd3>\n", argv[0]);
        return 1;
    }

    int command_2 = 0;
    int command_3 = 0;

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "|") == 0) {
            argv[i] = NULL;
            command_2 = i + 1;
            break;
        }
    }

    if (command_2 != 0) {
        for (int i = command_2; i < argc; i++) {
            if (strcmp(argv[i], "|") == 0) {
                argv[i] = NULL;
                command_3 = i + 1;
                break;
            }
        }
    }

    // Check if both pipes are present
    if (command_2 == 0 || command_3 == 0) {
        printf("Error: Insufficient arguments passed\n");
        printf("Usage: %s <cmd1> '|' <cmd2> '|' <cmd3>\n", argv[0]);
        return 1;
    }

    int pipe_1[2];
    int pipe_2[2];

    pipe(pipe_1);
    pipe(pipe_2);

    pid_t pid_1 = fork();
    if (pid_1 == 0) {
        close(pipe_1[0]);
        dup2(pipe_1[1], STDOUT_FILENO);
        close(pipe_1[1]);
        execvp(argv[1], argv + 1);
        perror("execvp");
        return 1;
    }

    pid_t pid_2 = fork();
    if (pid_2 == 0) {
        close(pipe_1[1]);
        close(pipe_2[0]);
        dup2(pipe_1[0], STDIN_FILENO);
        dup2(pipe_2[1], STDOUT_FILENO);
        close(pipe_1[0]);
        close(pipe_2[1]);
        execvp(argv[command_2], argv + command_2);
        perror("execvp");
        return 1;
    }

    pid_t pid_3 = fork();
    if (pid_3 == 0) {
        close(pipe_2[1]);
        close(pipe_1[0]);
        close(pipe_1[1]);
        dup2(pipe_2[0], STDIN_FILENO);
        close(pipe_2[0]);
        execvp(argv[command_3], argv + command_3);
        perror("execvp");
        return 1;
    }

    close(pipe_2[0]);
    close(pipe_2[1]);
    close(pipe_1[0]);
    close(pipe_1[1]);

    waitpid(pid_1, NULL, 0);
    waitpid(pid_2, NULL, 0);
    waitpid(pid_3, NULL, 0);

    return 0;
}
