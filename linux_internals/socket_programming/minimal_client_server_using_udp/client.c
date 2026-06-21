#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 2000
#define IP "127.0.0.1"

int main() {
    // Create UDP socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0) {
        perror("socket failed");
        return 1;
    }

    
    // Setup server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr)); // removing all those garbage values
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT); // 2000
    server_addr.sin_addr.s_addr = inet_addr(IP); // converting decimal dot to n/w format
    
    // Send data (no connect needed for UDP)
    char *message = "Hello from UDP client";
    sendto(sockfd, message, strlen(message), 0,
           (struct sockaddr*)&server_addr, sizeof(server_addr));
    
    // Receive response
    char buffer[1024];
    struct sockaddr_in from_addr;
    socklen_t from_len = sizeof(from_addr);
    
    ssize_t received = recvfrom(sockfd, buffer, sizeof(buffer)-1, 0,
                               (struct sockaddr*)&from_addr, &from_len);
    
    if(received > 0) {
        buffer[received] = '\0';
        printf("Server: %s\n", buffer);
    }
    
    close(sockfd);
    return 0;
}
