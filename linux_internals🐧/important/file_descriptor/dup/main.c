#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    // -------------------------------------------------------
    // dup() demo
    // dup() creates a copy of the fd, using the lowest
    // available fd number
    // -------------------------------------------------------

    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("original fd = %d\n", fd);  // probably 3

    int fd_copy = dup(fd);             // duplicates fd -> gets next free fd
    printf("dup'd fd    = %d\n", fd_copy);  // probably 4

    // both fd and fd_copy point to the same file
    // writing via either one writes to output.txt
    write(fd,      "line via original fd\n", 21);
    write(fd_copy, "line via dup'd fd\n",    18);

    close(fd);
    // fd_copy still works even after closing fd
    write(fd_copy, "still writing after closing original\n", 37);
    close(fd_copy);


    // -------------------------------------------------------
    // dup2() demo
    // dup2(oldfd, newfd) — like dup() but YOU choose the
    // destination fd number. if newfd is already open,
    // it closes it first automatically
    // -------------------------------------------------------

    int fd2 = open("output2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("fd2 = %d\n", fd2);  // probably 3

    // redirect stdout (fd 1) to output2.txt
    // dup2 closes fd 1 (stdout) and makes fd 1 point to output2.txt
    dup2(fd2, 1);

    // now printf writes to output2.txt, not the terminal!
    printf("this goes to output2.txt, not the terminal\n");

    close(fd2);
    close(1);


    // -------------------------------------------------------
    // classic use case: redirect child stdout in a pipe
    // -------------------------------------------------------

    int pipefd[2];
    pipe(pipefd);   // pipefd[0] = read end, pipefd[1] = write end

    pid_t pid = fork();

    if (pid == 0) {
        // child process
        close(pipefd[0]);             // child doesn't need read end

        dup2(pipefd[1], 1);           // redirect child's stdout -> pipe write end
        close(pipefd[1]);             // original write end no longer needed

        // now anything child writes to stdout goes into the pipe
        printf("child writing into pipe via stdout\n");
        exit(0);

    } else {
        // parent process
        close(pipefd[1]);             // parent doesn't need write end

        char buf[128];
        int n = read(pipefd[0], buf, sizeof(buf));  // read what child wrote
        buf[n] = '\0';

        printf("parent read from pipe: %s", buf);
        close(pipefd[0]);
    }

    return 0;
}
