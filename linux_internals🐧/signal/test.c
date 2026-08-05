#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static int count = 0;
void handler(int num){


    printf("Hello\n");
    count+=1;

    if ( count == 5 ){

        signal(SIGINT,SIG_DFL);
    }
}

int main(int argc, char** argv) {

    printf("process pid is %d\n",getpid());

    printf("Process is running\n");

    signal(SIGINT,handler);

    while (1);

}
