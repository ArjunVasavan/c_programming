#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/stat.h>
//TODO: create shm and read from FIFO and print on terminal

void capital_convert(char* str) {
    int i = 0;

    while (str[i]) {
    
        if ( str[i] >= 'a' && str[i] <= 'z' ) {

            str[i]-=32;

        }
        i+=1;
    }
}

int main(int argc, char** argv) {


    int fd[2];

    pipe(fd);

    int shmid = shmget( 'A' , 1024 , 0666 | IPC_CREAT );

    char* str = (char*) shmat(shmid,NULL,0);

    mkfifo("/tmp/myfifo",0666);

    pid_t pid = fork();

    if ( pid == 0 ) { // CHILD

        char child_buffer[20];

        close(fd[1]);

        read(fd[0],child_buffer,sizeof(child_buffer));

        capital_convert(child_buffer);

        printf("CHILD RECIEVED: %s\n",child_buffer);

        strcpy(str,child_buffer);

        close(fd[0]);

        shmdt(str);

        return 0;

    } else { // PARENT

        char input_buffer[20];
        printf("Enter the string: ");
        scanf("%[^\n]",input_buffer);

        close(fd[0]);

        write(fd[1],input_buffer,sizeof(input_buffer));

        close(fd[1]);

        wait(NULL);

        int fifo_fd = open("/tmp/myfifo",O_RDONLY);

        char output[20];

        read(fifo_fd,output,sizeof(output));

        printf("FIFO OUTPUT : %s\n",output);

        close(fifo_fd);

        shmdt(str);

        shmctl(shmid,IPC_RMID,NULL);


    }



}
