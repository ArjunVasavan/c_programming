#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char** argv) {
    
    int ret = fork();

    if( ret == 0 ){

    printf("Hello\n");
    char* arr[] = {"/bin/ls","ls","-l",NULL}; 
    execv(arr[0],arr+1);
    // execl("/bin/ls","ls",(char*)NULL);

    }else {
    
        wait(&ret);
    printf("World\n");
    }


}
