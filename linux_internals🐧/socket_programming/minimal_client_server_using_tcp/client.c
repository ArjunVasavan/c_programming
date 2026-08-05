#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

/*
 
 NOTE: These PORT and IP is mandatory in client to connect

*/
#define PORT 2000
#define IP "127.0.0.1"

int main() {
    // Create TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("socket failed");
        return 1;
    }
    
    // Setup server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    
    // Convert IP address
    if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("inet_pton failed");
        close(sockfd);
        return 1;
    }
    
    // Connect to server
    if(connect(sockfd, (struct sockaddr*)&server_addr, 
               sizeof(server_addr)) < 0) {
        perror("connect failed");
        close(sockfd);
        return 1;
    }
    
    printf("Connected to server\n");
    
    // Send data
    char *message = "Hello from client";
    send(sockfd, message, strlen(message), 0);
    
    // Receive response
    char buffer[1024] = {0};
    ssize_t received = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    if(received > 0) {
        buffer[received] = '\0';
        printf("Server: %s\n", buffer);
    }
    
    // Cleanup
    close(sockfd);
    
    return 0;
}

