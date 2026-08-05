#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv) {

    int fd = open("file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);

    dup2(fd, 1);

    pid_t pid = fork();

    if (pid == 0) {        // child
        for (int i = 0; i <= 100; i++) {
            printf("child  : %d\n", i);
            fflush(stdout);   // forces immediate write → SHUFFLE
            usleep(50);
        }
    } else {               // parent
        for (int i = 101; i <= 200; i++) {
            printf("parent : %d\n", i);
            fflush(stdout);   //  forces immediate write → SHUFFLE
            usleep(50);
        }
    }

    return 0;
}

