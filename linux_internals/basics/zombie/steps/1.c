#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
    pid_t zomb_pid = fork();

    if (zomb_pid < 0) {
        perror("fork");
        exit(1);
    }

    /* ---------------- CHILD (becomes zombie) ---------------- */
    if (zomb_pid == 0) {
        printf("Child started (pid=%d)\n", getpid());
        for (int i = 1; i <= 3; i++) {
            printf("%d ", i);
            fflush(stdout);
            sleep(1);
        }
        printf("\nChild exiting\n");
        _exit(0);   // child exits → zombie (parent doesn't wait)
    }

    /* ---------------- PARENT ---------------- */
    sleep(3);
    printf("\nZombie process has been created (pid=%d)\n", zomb_pid);

    pid_t sec_child = fork();

    if (sec_child < 0) {
        perror("fork");
        exit(1);
    }

    /* -------- Second child: inspector -------- */
    if (sec_child == 0) {

        char path[64];
        snprintf(path, sizeof(path), "/proc/%d/status", zomb_pid);

        int fd = open(path, O_RDONLY);
        if (fd == -1) {
            perror("open /proc status");
            exit(1);
        }

        char ch;
        int lines = 0;

        printf("\n--- Zombie status ---\n");
        while (read(fd, &ch, 1) == 1) {
            write(STDOUT_FILENO, &ch, 1);
            if (ch == '\n')
                lines++;
            if (lines == 3)
                break;
        }
        close(fd);

        printf("\nInspector sleeping...\n");
        sleep(5);

        /* Parent exits → zombie reaped by init */
        printf("Parent exited → zombie %d reaped by init/systemd\n", zomb_pid);
        exit(0);
    }

    /* Parent exits WITHOUT wait() → zombie cleaned by init */
    sleep(2);
    exit(0);
}

