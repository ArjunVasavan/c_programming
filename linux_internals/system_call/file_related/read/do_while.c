#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {

    int fd = open("file.txt", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    printf("File descriptor: %d\n", fd);

    char buffer;

    int rd = read(fd, &buffer, 1);

    if (rd == 0) {
        printf("file.txt is EMPTY\n");
        close(fd);
        return 1;
    } else if (rd == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    do {
        putchar(buffer);
    } while ((rd = read(fd, &buffer, 1)) > 0);

    if (rd == -1)
        perror("read");

    close(fd);
    return 0;
}

