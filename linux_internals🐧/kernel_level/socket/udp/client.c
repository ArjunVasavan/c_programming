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
    socklen_t addr_len = sizeof(server_addr);
    char send_buf[] = "Hello from userspace UDP client";
    char recv_buf[BUFFER_SIZE];
    ssize_t n;

    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
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

    n = sendto(sock_fd, send_buf, strlen(send_buf), 0,
              (struct sockaddr *)&server_addr, addr_len);
    if (n < 0) {
        perror("sendto");
        close(sock_fd);
        return 1;
    }
    printf("Sent to %s:%d: %s\n", server_ip, SERVER_PORT, send_buf);

    memset(recv_buf, 0, sizeof(recv_buf));
    n = recvfrom(sock_fd, recv_buf, sizeof(recv_buf) - 1, 0,
                (struct sockaddr *)&server_addr, &addr_len);
    if (n < 0) {
        perror("recvfrom");
        close(sock_fd);
        return 1;
    }

    recv_buf[n] = '\0';
    printf("Received: %s\n", recv_buf);

    close(sock_fd);
    return 0;
}
