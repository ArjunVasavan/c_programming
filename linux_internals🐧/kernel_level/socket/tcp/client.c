#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_PORT 2325
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    const char *server_ip = (argc > 1) ? argv[1] : "127.0.0.1";
    int sock_fd;
    struct sockaddr_in server_addr;
    char send_buf[] = "Hello from userspace client";
    char recv_buf[BUFFER_SIZE];
    ssize_t n;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address: %s\n", server_ip);
        close(sock_fd);
        return 1;
    }

    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sock_fd);
        return 1;
    }

    printf("Connected to %s:%d\n", server_ip, SERVER_PORT);

    n = send(sock_fd, send_buf, strlen(send_buf), 0);
    if (n < 0) {
        perror("send");
        close(sock_fd);
        return 1;
    }
    printf("Sent: %s\n", send_buf);

    memset(recv_buf, 0, sizeof(recv_buf));
    n = recv(sock_fd, recv_buf, sizeof(recv_buf) - 1, 0);
    if (n < 0) {
        perror("recv");
        close(sock_fd);
        return 1;
    } else if (n == 0) {
        printf("Server closed the connection before replying\n");
    } else {
        recv_buf[n] = '\0';
        printf("Received: %s\n", recv_buf);
    }

    close(sock_fd);
    return 0;
}
