#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <string.h>

/* 
 * select() function:
 * select(nfds, readfds, writefds, exceptfds, timeout);
 *
 * nfds      : highest file descriptor + 1
 * readfds   : set of FDs to check if ready for reading
 * writefds  : set of FDs to check if ready for writing
 * exceptfds : set of FDs to check for errors (rarely used)
 * timeout   : max time to wait (NULL = wait forever)
 *
 * In most practical cases, we only use readfds.
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

        close(fd[0]);  // child will not read

        sleep(3);  // simulate delay before sending data

        char *msg = "Hello from child\n";

        /* Write data into pipe */
        write(fd[1], msg, strlen(msg));

        close(fd[1]);  // done writing
    } else {
        // ===== PARENT PROCESS =====

        close(fd[1]);  // parent will not write

        fd_set readfds;   // set to store FDs we want to monitor
        char buffer[100];

        while (1) {

            /* Always reset the set before using select()
             * because select() modifies it internally
             */
            FD_ZERO(&readfds);

            /* Add fd[0] (read end of pipe) to the set */
            FD_SET(fd[0], &readfds);

            printf("Parent waiting...\n");

            /* IMPORTANT:
             * nfds = highest FD + 1
             *
             * Internally, select() checks like:
             * for (i = 0; i < nfds; i++)
             *
             * If fd[0] = 3:
             * select(3, ...) → checks 0,1,2 (misses 3) 
             * select(4, ...) → checks 0,1,2,3 (correct) 
             *
             * So we must pass fd[0] + 1
             */

            /* Wait until fd[0] becomes ready for reading
             * If no data → process sleeps here
             * When child writes → kernel wakes this process
             */
            select(fd[0] + 1, &readfds, NULL, NULL, NULL);

            /* Check if fd[0] is ready */
            if (FD_ISSET(fd[0], &readfds)) {

                /* Now read() will NOT block */
                int n = read(fd[0], buffer, sizeof(buffer));

                /* Safety: null terminate properly */
                if (n > 0 && n < sizeof(buffer))
                    buffer[n] = '\0';

                printf("Received: %s", buffer);
                break;
            }
        }
    }

    return 0;
}
