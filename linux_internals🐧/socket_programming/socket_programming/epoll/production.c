#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <string.h>

#define MAX_EVENTS 10

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        // ===== CHILD =====
        close(fd[0]); // no read

        sleep(5);
        write(fd[1], "Message from child\n", 19);

        close(fd[1]);
        return 0;
    }

    // ===== PARENT =====
    close(fd[1]); // no write

    int epfd = epoll_create1(0);

    struct epoll_event ev, events[MAX_EVENTS];

    // ---------------------------
    // Register STDIN (fd = 0)
    // ---------------------------
    ev.events = EPOLLIN;
    ev.data.fd = 0;

    epoll_ctl(epfd, EPOLL_CTL_ADD, 0, &ev);

    // ---------------------------
    // Register PIPE read end
    // ---------------------------
    ev.events = EPOLLIN;
    ev.data.fd = fd[0];

    epoll_ctl(epfd, EPOLL_CTL_ADD, fd[0], &ev);

    printf("Waiting for stdin or pipe...\n");

    while (1) {
        // Wait for events
        int nfds = epoll_wait(epfd, events, MAX_EVENTS, -1);

        if (nfds == -1) {
            perror("epoll_wait");
            return 1;
        }

        // Loop through all READY FDs
        for (int i = 0; i < nfds; i++) {

            int current_fd = events[i].data.fd;

            // ---------------------------
            // STDIN event
            // ---------------------------
            if (current_fd == 0) {
                char buffer[100];
                int n = read(0, buffer, sizeof(buffer));

                if (n > 0 && n < sizeof(buffer)) {
                    buffer[n] = '\0';
                    printf("STDIN: %s", buffer);
                }
            }

            // ---------------------------
            // PIPE event
            // ---------------------------
            else if (current_fd == fd[0]) {
                char buffer[100];
                int n = read(fd[0], buffer, sizeof(buffer));

                if (n > 0 && n < sizeof(buffer)) {
                    buffer[n] = '\0';
                    printf("PIPE: %s", buffer);
                }

                // After reading, remove from epoll
                epoll_ctl(epfd, EPOLL_CTL_DEL, fd[0], NULL);
                close(fd[0]);
            }
        }
    }

    return 0;
}
