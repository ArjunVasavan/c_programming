#include <stdio.h>
#include <pthread.h>

void *print_x( void* arg) {

    while (1) {

        printf("x");
    
    }

}

int main(int argc, char** argv) {
    
    pthread_t tid;

    printf("Process Started\n");

    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);


    pthread_create(&tid,&attr,print_x,NULL);

    pthread_join(tid,NULL);


}
