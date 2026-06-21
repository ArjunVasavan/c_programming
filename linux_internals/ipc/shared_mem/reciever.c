#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
int main(int argc, char** argv) {
    
    int shmid = shmget('A',4,0666);

    if ( shmid == -1 ){

        perror("shmget");

        return 1;
    }

    int *ptr = shmat(shmid,NULL,0);

    printf("Value recieved -> %d\n",*ptr);

    shmdt(ptr);

    printf("SHM detatched\n");
}
