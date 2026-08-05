#include <stdio.h>
#include <pthread.h>

typedef struct {

    int start;
    int end;

} thread_limit;

void *factorial( void* arg ) {

    unsigned long int result = 1;

    int start  = ((thread_limit*)arg)->start;
    int end  = ((thread_limit*)arg)->end;

    for ( int i = start ; i <= end ; i++ ) {

        result*=i;

    }

    return (void*)result;
}


int main(int argc, char** argv) {
    
    int n;

    printf("Enter the n value : ");
    scanf("%d",&n);

    thread_limit limit[3];
    limit[0].start = 1; 
    limit[0].end = ( n / 3 ); 
    limit[1].start =( ( n / 3 ) + 1 ); 
    limit[1].end = ( ( n / 3 ) * 2 ); 
    limit[2].start = ( ( ( n / 3 ) * 2 ) + 1 ); 
    limit[2].end = n; 
    pthread_t tid[3];

    for ( int i = 0 ; i < 3  ; i++ ) {

        pthread_create(&tid[i],NULL,factorial,(void*)&limit[i]);

    }

    int result = 1;
    int sum;

    for ( int i = 0 ; i < 3 ; i++ ) {

        pthread_join(tid[i],(void**)&sum);
        result*=sum;
    }

    printf("Result -> %d\n",result);

}
