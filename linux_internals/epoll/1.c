#include <sys/epoll.h>
#include <stdio.h>

int main() {
    int epoll_fd = epoll_create1(0);   // step 1: create the epoll instance

    struct epoll_event event, events[10];

    event.events = EPOLLIN;   // "notify me when readable"
    event.data.fd = 0;        // watching fd 0 (stdin)

    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, 0, &event);   // step 2: register stdin with epoll

    printf("Waiting for input...\n");
    int n = epoll_wait(epoll_fd, events, 10, -1);    // step 3: wait until something's ready

    for (int i = 0; i < n; i++) {
        if (events[i].data.fd == 0) {
            printf("You typed something!\n");
        }
    }

    return 0;
}
