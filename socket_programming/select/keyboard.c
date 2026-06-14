#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        // ===== CHILD =====
        close(fd[0]);  // child doesn't read

        sleep(3);
        write(fd[1], "Message from child\n", 19);

        close(fd[1]);
    } else {
        // ===== PARENT =====
        close(fd[1]);  // parent doesn't write

        fd_set readfds;
        char buffer[100];

        while (1) {
            FD_ZERO(&readfds);

            // Add stdin (fd = 0)
            FD_SET(0, &readfds);

            // Add pipe read end
            FD_SET(fd[0], &readfds);

            // Find max fd
            int max_fd = fd[0] > 0 ? fd[0] : 0;

            printf("Waiting for input (keyboard or pipe)...\n");

            int ret = select(max_fd + 1, &readfds, NULL, NULL, NULL);

            if (ret < 0) {
                perror("select error");
                return 1;
            }

            // Check keyboard input
            if (FD_ISSET(0, &readfds)) {
                int n = read(0, buffer, sizeof(buffer));
                if (n > 0 && n < sizeof(buffer)) {
                    buffer[n] = '\0';
                    printf("Keyboard: %s", buffer);
                }
            }

            // Check pipe input
            if (FD_ISSET(fd[0], &readfds)) {
                int n = read(fd[0], buffer, sizeof(buffer));
                if (n > 0 && n < sizeof(buffer)) {
                    buffer[n] = '\0';
                    printf("Pipe: %s", buffer);
                }
                break; // exit after child message
            }
        }
    }

    return 0;
}
