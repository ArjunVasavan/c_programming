#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv) {
    
    printf("Hello\n");
    // execl("/bin/ls","ls",(char*)NULL);
    // execlp("ls","ls","-l",(char*)NULL);
    char* arr[] = {"/bin/ls","ls","-l",NULL}; 
    // execv("/bin/ls",arr);
    execv(arr[0],arr+1);
    int ret = fork();

    if( ret == 0 ){
    printf("World\n");
    }


}
