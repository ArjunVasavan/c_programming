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

    struct stat st;
    if (fstat(fd, &st) < 0) {
        perror("fstat");
        exit(EXIT_FAILURE);
    }

    printf("Size:         %ld bytes\n", st.st_size);
    printf("Permissions:  %o\n", st.st_mode & 0777);
    printf("Hard links:   %ld\n", st.st_nlink);
    printf("Owner UID:    %d\n", st.st_uid);
    printf("Last modified:%ld\n", st.st_mtime);
    printf("Block size:   %ld\n", st.st_blksize);
    printf("Blocks alloc: %ld\n", st.st_blocks);

    // check if it's a regular file
    if (S_ISREG(st.st_mode)) {
        printf("Type:         regular file\n");
    } else if (S_ISDIR(st.st_mode)) {
        printf("Type:         directory\n");
    }

    close(fd);
}
