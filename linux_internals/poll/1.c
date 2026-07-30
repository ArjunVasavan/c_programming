#include <poll.h>
#include <stdio.h>

int main() {
    struct pollfd fds[1];

    fds[0].fd = 0;          // watch fd 0 (stdin)
    fds[0].events = POLLIN; // POLLIN = "notify me when there's data to read"

    printf("Waiting for input...\n");
    poll(fds, 1, -1);       // 1 = number of fds watching, -1 = wait forever

    if (fds[0].revents & POLLIN) {
        printf("You typed something!\n");
    }

    return 0;
}
