#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int sig, siginfo_t *info, void *ucontext)
{
    if (info->si_code == CLD_EXITED) {
        printf("Child exited normally with status %d\n",
               info->si_status);
    }
}

int main(void)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO | SA_NOCLDWAIT;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGCHLD, &sa, NULL);

    pid_t pid = fork();

    if (pid == 0) {   // CHILD
        printf("CHILD\n");
        return 0;   
    } else {

        sleep(1);
        printf("PARENT\n");

        return 0;      
    }
}

