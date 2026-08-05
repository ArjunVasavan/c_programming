#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    // open file - we need an fd for fchmod
    // O_RDONLY is enough - fchmod doesn't need write access to the file
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // fchmod changes the permission bits of the file
    // 0644 = rw-r--r-- (owner can read/write, group/others can only read)
    // unlike chmod(), it uses fd instead of a path
    if (fchmod(fd, 0644) < 0) {
        perror("fchmod");
        exit(EXIT_FAILURE);
    }
    printf("Permissions changed to 644\n");

    // verify the change using fstat
    // always good practice to confirm the operation worked
    struct stat st;
    fstat(fd, &st);

    // mask with 0777 to extract only the 9 permission bits
    // st_mode also contains file type bits we don't want here
    printf("New permissions: %o\n", st.st_mode & 0777);

    close(fd);
}
