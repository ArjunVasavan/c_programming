#include <stdio.h>
#include <pthread.h>
 
int count = 0;

void* thread_fun( void* argv) {

    while (1) {

        count = 0;
        count+=5;
        count+=10;
        printf("%d \n",count);
    
    }

}
int main(int argc, char** argv) {
    
    pthread_t tid1,tid2;

    pthread_create(&tid1,NULL,thread_fun,NULL);
    pthread_create(&tid2,NULL,thread_fun,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
}

//TODO: use ./a.out | grep -v 15
// ERROR : an condition called race condition happens
