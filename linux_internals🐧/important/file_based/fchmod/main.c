#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // change permissions to rw-r--r-- (644)
    if (fchmod(fd, 0644) < 0) {
        perror("fchmod");
        exit(EXIT_FAILURE);
    }
    printf("Permissions changed to 644\n");

    // verify with fstat
    struct stat st;
    fstat(fd, &st);
    printf("New permissions: %o\n", st.st_mode & 0777);

    close(fd);
}
