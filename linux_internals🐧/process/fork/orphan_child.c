#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv) {
    
    int ret = fork();

    if ( ret == -1 ){
        perror("fork failed\n");
        return 1;
    } else if ( ret == 0 ) {

        printf("child started \n");

        printf("PPID of child before sleep is %d\n",getppid());

        sleep(5);

        printf("PPID of child after sleep is %d\n",getppid());

        printf("Child terminated\n");

        return 0;
    } else {
    
        printf("Parent called\n");

        sleep(2);

        printf("Parent dead\n");

        return 0;
    }

}
