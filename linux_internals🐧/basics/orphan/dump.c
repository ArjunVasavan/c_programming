#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv) {

    pid_t zombie_child_pid = fork();

    pid_t parent_pid = getpid();

    pid_t old_pid = parent_pid;

    if ( zombie_child_pid > 0 ){

        sleep(5);

        printf("Child is now an zombie\n");

        pid_t end_child = fork();

        if ( end_child == 0 ){

            char string_buffer[100];

            sprintf(string_buffer,"/proc/%d/status",zombie_child_pid);

            int count = 0;
            char reader;
            printf("STATUS\n");
            int read_fd = open(string_buffer,O_RDONLY);

            if ( read_fd == -1 ){
                printf("error opening status file\n");
                return 1;
            }

            while ( read(read_fd,&reader,1) ) {

                printf("%c",reader);

                if (reader == '\n'){
                    count++;
                }

                if (count == 3){
                    break;
                }
            }

            sleep(5);

            parent_pid = getpid();
            if (parent_pid != old_pid ){
                printf("\nChild zombie %d is terminated by init\n",zombie_child_pid);
                return 1;
            }
        }

    } else if (zombie_child_pid == 0 ){

        printf("A child created with %d\n",getpid());

        printf("Child process running \n");
    }
}

