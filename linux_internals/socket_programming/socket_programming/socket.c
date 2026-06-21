#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

#define IP  "172.217.24.195" /* www.google.se */
#define PORT 80 /* http */

/* NOTE: What well learned
 * i learned about strace which show what system call is used as its an debugging tool
 * i accidentally used UDP send and recv inspite of TCP
 */

int main(int argc, char** argv) {
    
    int socket_fd;
    struct sockaddr_in sock_addr; /* Dr Birch Forgot about adding struct here */

    memset(&sock_addr, 0, sizeof(sock_addr)); // IMPORTANT: initialize struct

    socket_fd = socket( AF_INET, SOCK_STREAM, 0);

    if ( socket_fd < 0 ) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if ( inet_pton(AF_INET,IP,&sock_addr.sin_addr) != 1 ) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }

    sock_addr.sin_port = htons(PORT); /* converting lower to big endian */

    sock_addr.sin_family = AF_INET;

    /* next step is to connect to host */

    int received_from_connect = connect(socket_fd,(const struct sockaddr*)&sock_addr,sizeof(sock_addr));

    if ( received_from_connect != 0 ) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];

    char* data;

    data = "HEAD / HTTP/1.0\r\n\r\n"; // FIX: HTTP requires \r\n

    // FIX: use send() for TCP, not sendto()
    // FIX: sizeof(data) is wrong (pointer), use strlen
    send(socket_fd, data, strlen(data), 0);

    socklen_t receive_len;

    struct sockaddr_in r_addr;

    // FIX: recvfrom() not needed for TCP, also receive_len was uninitialized
    int bytes = recv(socket_fd, buffer, sizeof(buffer) - 1, 0);

    if (bytes > 0) {
        buffer[bytes] = '\0'; // null terminate
        printf("%s\n", buffer); // print response
    }

    close(socket_fd); // IMPORTANT: free resource
}
