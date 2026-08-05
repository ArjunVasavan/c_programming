#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

/* NOTE: select
 * select is just a Waiting tool
 * it does not read data, it does not process data
 * it only answers: which file descriptors are ready right now
 * so that read() will not block
 */

// NOTE: select return value
// int ret = select(...);
//
// if (ret == -1) {
//     perror("select");
// }
// else if (ret == 0) {
//     // timeout happened
// }
// else {
//     // some fds are ready
// }

int main() {
    fd_set readfds;

    while (1) {
        FD_ZERO(&readfds); /* clearing set */

        // 0 = stdin
        FD_SET(0, &readfds); /* we are adding stdin to watch */

        printf("Waiting for input...\n");

        // nfds = highest fd + 1 = 1
        select(1, &readfds, NULL, NULL, NULL); /* sleep until stdin gets input */

        if (FD_ISSET(0, &readfds)) { /* check wheather stdin is ready */
            char buffer[100];
            read(0, buffer, sizeof(buffer)); /* now read it will not block */
            printf("You typed: %s\n", buffer);
        }
    }
}
