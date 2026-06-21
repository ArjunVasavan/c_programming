#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd;
    struct stat st;

    /* 1. Open file */
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    /* 2. Get file information */
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        close(fd);
        return 1;
    }

    printf("Before fchmod:\n");
    printf("Permissions: %o\n", st.st_mode & 0777);

    /* 3. Change permissions to rw-r----- (640) */
    if (fchmod(fd, S_IRUSR | S_IWUSR | S_IRGRP) == -1) {
        perror("fchmod");
        close(fd);
        return 1;
    }

    /* 4. Verify change */
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        close(fd);
        return 1;
    }

    printf("After fchmod:\n");
    printf("Permissions: %o\n", st.st_mode & 0777);

    close(fd);
    return 0;
}

