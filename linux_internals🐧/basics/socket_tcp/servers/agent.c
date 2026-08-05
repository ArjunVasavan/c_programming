#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 5000
#define IP "127.0.0.1"
int main(int argc, char** argv) {

    int server_fd = socket(AF_INET,SOCK_STREAM,0);

    if ( server_fd <  0 ) {

        perror("Socket failed");
        exit(EXIT_FAILURE);

    }

    struct sockaddr_in server_addr;

    memset(&server_addr,0,sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(IP);

    if ( bind(server_fd,(struct sockaddr*)&server_addr, sizeof(server_addr)) < 0 ) {
        perror("bind failed");
        close(server_fd);
        return 1;
    }

    if ( listen(server_fd,5) < 0 ) {

        perror("listen failed");
        close(server_fd);
        return 1;
    }

    printf("Server is now listening on port %d\n",PORT);

    //accepting client connection

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_fd = accept(server_fd,(struct sockaddr*)&client_addr,&client_len);

    if ( client_fd < 0 ) {
        perror("accept failed\n");
        close(server_fd);
        return 1;
    }

    printf("Client connected from %s:%d\n",
           inet_ntoa(client_addr.sin_addr),
           ntohs(client_addr.sin_port));

    char buffer;

    ssize_t recieved = recv(client_fd,&buffer,1,0);

    if ( recieved > 0 ) {
        printf("Client: %c\n",buffer);
    }

    char response[1024];

    switch (buffer) {
    
        case '+': {

            strcpy(response,"5001");
            break;
        }
        case '-': {

            strcpy(response,"5002");
            break;
        }
        case '*': {

            strcpy(response,"5003");
            break;
        }
        case '/': {

            strcpy(response,"5004");
            break;
        }
        case '%': {

            strcpy(response,"5005");
            break;
        }
        
        default:{
            printf("Error Operation\n");
            exit(EXIT_FAILURE);
        }

    }

    send(client_fd,response,strlen(response),0);
    printf("Sending Successfull\n");

    printf("Closing...\n");
    close(client_fd);
    close(server_fd);

    return 0;
}
