#include <stdio.h>
#include <pthread.h>

//RACE CONDITION
 
int count = 0; // Here both thread share same data segment
// to prevent this race condition use it as local

void* thread_fun( void* argv) {

    while (1) {

        count = 0; // this count acts as an shared memory
        count+=5;
        count+=10;
        printf("%d \n",count);
    
    }

}
int main(int argc, char** argv) {
    
    printf("RACE CONDITION EXAMPLE <use ./a.out | grep -v 15 >\n");
    pthread_t tid1,tid2;

    pthread_create(&tid1,NULL,thread_fun,NULL);
    pthread_create(&tid2,NULL,thread_fun,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
}

//TODO: use ./a.out | grep -v 15
// ERROR : an condition called race condition happens
