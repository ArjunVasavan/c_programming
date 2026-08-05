#include <netinet/in.h>
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

    // Bind socket  NOTE: sockaddr becuase server_addr is sockaddr_in type 

    if(bind(sockfd, (struct sockaddr*)&server_addr, 
            sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(sockfd);
        return 1;
    }

    printf("UDP Server listening on port 2000...\n");

    char buffer[1024];
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Receive data NOTE: bind reads sockaddr our client_addr is sockaddr_in type

    ssize_t received = recvfrom(sockfd, buffer, sizeof(buffer)-1, 0,
                                (struct sockaddr*)&client_addr, 
                                &client_len);

    if(received < 0) {
        perror("recvfrom failed");
    }

    printf("Port number: %d\n",ntohs(client_addr.sin_port));
    printf("IP address : %s\n",inet_ntoa(client_addr.sin_addr));

    buffer[received] = '\0';
    printf("Client: %s\n", buffer);

    // Send response back
    char *response = "Hello from UDP server";
    sendto(sockfd, response, strlen(response), 0,
           (struct sockaddr*)&client_addr, client_len);

    close(sockfd);
    return 0;
}

