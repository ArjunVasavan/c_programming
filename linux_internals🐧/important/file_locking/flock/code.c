#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("shared.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    pid_t pid = fork();  // Split into two processes here

    if (pid == 0) {
        // ---- CHILD PROCESS ----
        printf("Child: waiting for lock...\n");
        flock(fd, LOCK_EX);         // Will block if parent has it

        printf("Child: got the lock! Writing...\n");
        for (int i = 0; i < 5; i++) {
            write(fd, "child line\n", 11);
            sleep(1);
        }

        printf("Child: done, releasing lock.\n");
        flock(fd, LOCK_UN);

    } else {
        // ---- PARENT PROCESS ----
        printf("Parent: grabbing lock first!\n");
        flock(fd, LOCK_EX);         // Parent grabs it first

        printf("Parent: got the lock! Writing...\n");
        for (int i = 0; i < 5; i++) {
            write(fd, "parent line\n", 12);
            sleep(1);
        }

        printf("Parent: done, releasing lock.\n");
        flock(fd, LOCK_UN);

        wait(NULL);  // Wait for child to finish
    }

    close(fd);
    return 0;
}
