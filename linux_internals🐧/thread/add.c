#include <stdio.h>
#include <pthread.h>
#include <time.h>

struct sum {

    int x;
    int y;


};

int result;

void* add(void* arg ) {

    struct sum *temp =(struct sum*) arg;


    result = temp->x+temp->y;
    return &result;
}


int main(int argc, char** argv) {
    
    struct sum s;

    s.x = 10;
    s.y = 20;

    pthread_t tid;
    int* res;
    pthread_create(&tid,NULL,add,&s);
    pthread_join(tid,(void **)&res);

    printf("Result -> %d\n",*res);
}
