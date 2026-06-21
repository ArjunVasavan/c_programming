#include <stdio.h>
#include <pthread.h>
#include <time.h>

struct sum {
    int x;
    int y;
};

int result;

void* add(void* arg ) {

    // struct sum *temp =(struct sum*) arg;

    int* temp = (int*)arg;

    int size = temp[0];
    for ( int i = 1 ; i <= size ; i++  ) {

        temp[size+1]+=temp[i];
        
    }


    // result = temp->x+temp->y;
    // return &result;
    
    return NULL;
}


int main(int argc, char** argv) {
    
    // struct sum s;

    // s.x = 10;
    // s.y = 20;

    int array[] = {5,1,2,3,4,5,0};

    pthread_t tid;
    pthread_create(&tid,NULL,add,array);
    pthread_join(tid,NULL);

    printf("Result -> %d\n",array[array[0]+1]);
}
