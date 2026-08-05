#include <sys/select.h>
#include <stdio.h>

int main() {
    fd_set readfds;

    FD_ZERO(&readfds);       // clear the list
    FD_SET(0, &readfds);     // add fd 0 (stdin/keyboard) to the watch list

    printf("Waiting for input...\n");
    select(1, &readfds, NULL, NULL, NULL);   // wait until fd 0 has data

    if (FD_ISSET(0, &readfds)) {
        printf("You typed something!\n");
    }

    return 0;
}
