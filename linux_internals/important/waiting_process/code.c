#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Create a child process

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // --- CHILD PROCESS ---
        printf("Child (PID %d): Hello from child!\n", getpid());
        sleep(2);  // Simulate some work
        printf("Child: Done!\n");
        exit(42);  // Exit with code 42
    } else {
        // --- PARENT PROCESS ---
        printf("Parent: Waiting for child PID %d...\n", pid);

        int status;
        pid_t result = waitpid(pid, &status, 0);  // Wait for specific child

        if (result == -1) {
            perror("waitpid failed");
        } else if (WIFEXITED(status)) {
            printf("Parent: Child exited with code %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
