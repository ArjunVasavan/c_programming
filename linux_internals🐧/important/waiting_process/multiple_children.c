#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pids[3];

    for (int i = 0; i < 3; i++) {
        pids[i] = fork();
        if (pids[i] == 0) {
            // Child
            printf("Child %d (PID %d) working...\n", i, getpid());
            sleep(i + 1);
            exit(i * 10);  // Each child exits with different code
        }
    }

    // Parent waits for each child specifically
    for (int i = 0; i < 3; i++) {
        int status;
        waitpid(pids[i], &status, 0);
        printf("Child %d exited with code %d\n", i, WEXITSTATUS(status));
    }

    return 0;
}
