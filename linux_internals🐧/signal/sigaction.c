#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>
void handler(int num, siginfo_t * info , void* ucontext ) {

    printf("SEGV called\n");
    printf("id of sigino is %d\n",info->si_signo);
    printf("Address is %p\n",info->si_addr);
    printf("code is %d\n",info->si_code);
    exit(1);

}


int main(int argc, char** argv) {
    
    printf("Process started\n");

    struct sigaction newact;
    bzero(&newact,sizeof(newact));

    newact.sa_sigaction = handler;
    newact.sa_flags = SA_SIGINFO;

    sigaction(SIGSEGV,&newact,NULL); 
    int*ptr = NULL;
    printf("%d\n",*ptr);
}
