#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    struct flock lock;

    /* Open file */
    fd = open("data.txt", O_RDWR | O_CREAT, 0666);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    /* ----------- SET WRITE LOCK ----------- */
    lock.l_type   = F_WRLCK;      // Write lock
    lock.l_whence = SEEK_SET;     // From beginning
    lock.l_start  = 0;            // Start of file
    lock.l_len    = 0;            // Lock till EOF

    printf("Trying to acquire write lock...\n");

    /* Blocking lock */
    fcntl(fd, F_SETLKW, &lock);

    printf("Write lock acquired!\n");

    /* ----------- CRITICAL SECTION ----------- */
    write(fd, "Hello from process\n", 19);
    sleep(10);   // Simulate long operation

    /* ----------- UNLOCK ----------- */
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Lock released.\n");

    close(fd);
    return 0;
}

