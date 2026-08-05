#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h>

int main() {
    int epfd;

    // Step 1: Create epoll instance
    epfd = epoll_create1(0);

    // Step 2: Create event structure
    struct epoll_event ev, events[1];

    // We want to monitor stdin (fd = 0)
    ev.events = EPOLLIN;   // ready to read
    ev.data.fd = 0;        // store fd

    // Step 3: Register stdin with epoll
    epoll_ctl(epfd, EPOLL_CTL_ADD, 0, &ev);

    printf("Type something:\n");

    // Step 4: Wait for event
    int nfds = epoll_wait(epfd, events, 1, -1);

    // Step 5: Handle event
    if (events[0].data.fd == 0) {
        char buffer[100];
        int n = read(0, buffer, sizeof(buffer));

        buffer[n] = '\0';
        printf("You typed: %s", buffer);
    }

    return 0;
}
