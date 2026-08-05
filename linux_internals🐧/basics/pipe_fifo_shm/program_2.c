#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

//TODO: reads from SHM and writes to FIFO 

void reverse(char* buffer ) {

    int i = 0;

    int len  = strlen(buffer) - 1;

    while (i < len ) {

        buffer[i] ^= buffer[len];
        buffer[len] ^= buffer[i];
        buffer[i] ^= buffer[len];
        len-=1;
        i+=1;

    }

}


int main(int argc, char** argv) {

    int shmid = shmget( 'A' , 1024 , 0666 | IPC_CREAT );

    char* str = (char*) shmat(shmid,NULL,0);

    char recieved_buffer[20];

    strcpy(recieved_buffer,str);

    printf("RECIEVED : %s\n",str);

    reverse(recieved_buffer);

    printf("RECIEVED STRING[REVERSED]: %s\n",recieved_buffer);

    int fd = open("/tmp/myfifo",O_WRONLY);

    write(fd,recieved_buffer,strlen(recieved_buffer)+1);

    close(fd);
    shmdt(str);
    return 0;


}
