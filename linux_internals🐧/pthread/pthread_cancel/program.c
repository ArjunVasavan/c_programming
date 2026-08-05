#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_fun(void* arg ) {

    int i , res;
    res = pthread_setcancelstate(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
    // res = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
    // res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
    for ( int i = 0 ; i <= 10 ; i++ ) {


        printf("Value: %d\n",i);

        sleep(1);
    }

    pthread_exit(NULL);
}


int main(int argc, char** argv) {

    int res;

    pthread_t a_thread;

    res = pthread_create(&a_thread,NULL,thread_fun,NULL);

    sleep(3);

    printf("Canceling thread\n");

    res = pthread_cancel(a_thread);

    if ( res != 0 ) {
        perror("Thread Cancellation");
    }
    
}
