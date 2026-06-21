#include <signal.h>                                                      
#include <stdio.h>                                                        
#include <unistd.h>                                                       
#include <stdlib.h>

void handler(int num, siginfo_t * info , void* ucontext ) {

    printf("Signal %d received\n", info->si_signo);                                  
    printf("Signal Address is %p\n",info->si_addr);
    exit(1);

}                                                                         

int main() {                                                              

    struct sigaction sa;                                                                                                                              
    sigemptyset(&sa.sa_mask);                                             
    sa.sa_sigaction = handler;                                              
    sa.sa_flags = SA_SIGINFO;                                                      
    sigaction(SIGSEGV, &sa, NULL);                                         
    int *ptr = (int*) 1;
    *ptr = 10;
    while (1) sleep(1);                                                   

}                                                                               
