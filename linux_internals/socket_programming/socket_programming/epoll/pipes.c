#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <string.h>

#define MAX_EVENTS 5

/*
 * Why epoll is better than select:
 *
 * 1. select scans all FDs every time → O(n) 
 *    epoll returns only active FDs → O(1) (amortized) 
 *
 * 2. select has FD limit (~1024) 
 *    epoll supports large number of FDs 
 *
 * 3. select requires rebuilding fd_set every loop 
 *    epoll registers once, kernel maintains it 
 *
 * 4. epoll is event-driven (efficient for large systems)
 */

int main() {
    int fd[2];

    /* Create a pipe:
     * fd[0] → read end
     * fd[1] → write end
     */
    pipe(fd);

    if (fork() == 0) {
        // ===== CHILD PROCESS =====

        close(fd[0]);  // child does not read

        sleep(3);  // simulate delay

        /* Write data into pipe */
        write(fd[1], "Hello from child\n", 18);

        close(fd[1]);  // done writing
    } else {
        // ===== PARENT PROCESS =====

        close(fd[1]);  // parent does not write

        /* Create epoll instance (event manager) */
        int epfd = epoll_create1(0); /* 0 is used for telling normal usage */

        struct epoll_event ev;              /* for telling kernel what do we want */
        struct epoll_event events[MAX_EVENTS]; // returned ready events

        /*
         * Register fd[0] (pipe read end) with epoll
         *
         * ev.events:
         *   EPOLLIN → notify when data is available to read
         *
         * ev.data.fd:
         *   user-defined data (here we store fd itself)
         */
        ev.events = EPOLLIN; /* ev.events -> what to watch */
        ev.data.fd = fd[0]; /* ev.data.fd -> what to return back with this when an event happens it will return this */

        /* Add fd[0] to epoll interest list */
        epoll_ctl(epfd, EPOLL_CTL_ADD, fd[0], &ev); /* fd[0] -> the actual fd you want to monitor */
        /* EPOLL_CTL_ADD -> start monitoring */
        /* EPOLL_CTL_DEL -> stop monitoring */

        printf("Waiting using epoll...\n");

        /*
         * Wait for events:
         * - events[] will be filled with ready FDs
         * - MAX_EVENTS → max events to return
         * - -1 → wait indefinitely
         */
        int nfds = epoll_wait(epfd, events, MAX_EVENTS, -1);

        /*
         * Unlike select():
         * - No need to scan all FDs
         * - events[] contains ONLY ready FDs
         */
        for (int i = 0; i < nfds; i++) {

            /*
             * events[i].data.fd:
             *   gives the FD that is ready
             */
            if (events[i].data.fd == fd[0]) {

                char buffer[100];

                /* Safe read: epoll guarantees data is ready */
                int n = read(fd[0], buffer, sizeof(buffer));

                if (n > 0 && n < sizeof(buffer))
                    buffer[n] = '\0';

                printf("Received: %s", buffer);
            }
        }
    }

    return 0;
}
