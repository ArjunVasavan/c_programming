#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char msg[1024];
    int fd;

    if (argc != 2) {
        printf("usage: %s <device>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_WRONLY);
    if (fd < 0) {
        printf("could not open %s\n", argv[1]);
        return 1;
    }

    while (1) {
        printf("enter message (or quit): ");
        fgets(msg, sizeof(msg), stdin);

        if (strncmp(msg, "quit", 4) == 0)
            break;

        write(fd, msg, strlen(msg));
    }

    close(fd);
    return 0;
}
