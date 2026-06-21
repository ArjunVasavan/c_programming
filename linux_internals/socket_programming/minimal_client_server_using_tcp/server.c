#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 2000
#define IP "127.0.0.1"

int main() {
    // Create TCP socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0) {
        perror("socket failed");
        return 1;
    }
    
    // Setup server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(IP);
    
    // Bind socket to address
    if(bind(server_fd, (struct sockaddr*)&server_addr, 
            sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(server_fd);
        return 1;
    }
    
    // Listen for connections
    if(listen(server_fd, 5) < 0) {
        perror("listen failed");
        close(server_fd);
        return 1;
    }
    
    printf("Server listening on port %d...\n",PORT);
    
    // Accept client connection
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, 
                          &client_len);
    if(client_fd < 0) {
        perror("accept failed");
        close(server_fd);
        return 1;
    }

    /* 
     
      NOTE: if you dont want to pass client info use 
      => accept(sock_fd,NULL,NULL);

    */
    
    printf("Client connected from %s:%d\n",
           inet_ntoa(client_addr.sin_addr),
           ntohs(client_addr.sin_port));
    
    // Receive data
    char buffer[1024] = {0};
    ssize_t received = recv(client_fd, buffer, sizeof(buffer)-1, 0);
    if(received > 0) {
        buffer[received] = '\0';
        printf("Client: %s\n", buffer);
    }
    
    // Send response
    char *response = "Hello from server";
    send(client_fd, response, strlen(response), 0);
    
    // Cleanup
    close(client_fd);
    close(server_fd);
    
    return 0;
}

