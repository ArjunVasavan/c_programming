/* 
--------------------------------------------------------------------------------
Name : Arjun Vasavan

Date : 15 - 12 - 2025

Descripition : communication between two related processes using one pipe

--------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    int second_command = 0;

    // Find pipe symbol
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "|") == 0) {
            argv[i] = NULL;
            second_command = i + 1;
            break;
        }
    }

    // Validation
    if (second_command == 0) {
        printf("Usage: ./pipe cmd1 | cmd2\n");
        return 1;
    }

    int fd[2];
    pipe(fd);

    // First child → command before |
    pid_t pid1 = fork();
    if (pid1 == 0) {
        close(fd[0]);                     // close read end
        dup2(fd[1], STDOUT_FILENO);       // stdout → pipe
        close(fd[1]);

        execvp(argv[1], argv + 1);
        perror("execvp cmd1");
        return 1;
    }

    // Second child → command after |
    pid_t pid2 = fork();
    if (pid2 == 0) {
        close(fd[1]);                     // close write end
        dup2(fd[0], STDIN_FILENO);        // stdin ← pipe
        close(fd[0]);

        execvp(argv[second_command], argv + second_command);
        perror("execvp cmd2");
        return 1;
    }

    // Parent process
    close(fd[0]);
    close(fd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}

