#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 5000
#define IP "127.0.0.1"

int main(int argc, char** argv) {


    int socketfd = socket(AF_INET,SOCK_STREAM,0);

    if ( socketfd < 0 ) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in server_addr;
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if ( inet_pton(AF_INET,IP,&server_addr.sin_addr) <= 0 ) {
        perror("inter_pton failed");
        exit(EXIT_FAILURE);
    }

    if ( connect(socketfd,(struct sockaddr*)&server_addr,sizeof(server_addr)) < 0 ) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    char operation;
    printf("Enter the operation you want: ");
    scanf("%c",&operation);

    send(socketfd,&operation,1,0);

    char message[1024];


    ssize_t recieved = recv(socketfd,message,sizeof(message),0);

    if ( recieved > 0 ) {
        message[recieved] = '\0';
        printf("Returned %s\n",message);
    }

    close(socketfd);

    printf("Enter two numbers: ");
    int n1,n2;
    scanf("%d %d",&n1,&n2);

    
}
