#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    // open file - we need an fd for fstat
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // fstat fills the stat struct with file metadata
    // unlike stat(), it uses fd instead of a path
    struct stat st;
    if (fstat(fd, &st) < 0) {
        perror("fstat");
        exit(EXIT_FAILURE);
    }

    // st_size: actual content size in bytes
    printf("Size:         %ld bytes\n", st.st_size);

    // st_mode & 0777: mask out just the permission bits (ignore file type bits)
    printf("Permissions:  %o\n", st.st_mode & 0777);

    // st_nlink: how many directory entries point to this file
    printf("Hard links:   %ld\n", st.st_nlink);

    // st_uid: user id of the file owner
    printf("Owner UID:    %d\n", st.st_uid);

    // st_mtime: unix timestamp of last modification
    printf("Last modified:%ld\n", st.st_mtime);

    // st_blksize: optimal buffer size for reading this file efficiently
    printf("Block size:   %ld\n", st.st_blksize);

    // st_blocks: actual disk space used (in 512B units, not st_blksize)
    printf("Blocks alloc: %ld\n", st.st_blocks);

    // S_ISREG / S_ISDIR are macros that check the file type bits in st_mode
    if (S_ISREG(st.st_mode)) {
        printf("Type:         regular file\n");
    } else if (S_ISDIR(st.st_mode)) {
        printf("Type:         directory\n");
    }

    close(fd);
}
