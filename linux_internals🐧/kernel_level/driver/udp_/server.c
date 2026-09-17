#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ctype.h>

#define PORT 8080
#define BUF_SIZE 1024

int is_goodbye(char *msg) {
    for (int i = 0; msg[i]; i++)
        msg[i] = tolower(msg[i]);

    if (strstr(msg, "bye") || strstr(msg, "quit") || strstr(msg, "see you later"))
        return 1;
    return 0;
}

int main() {
    int sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char buf[BUF_SIZE];

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        return 1;
    }

    printf("udp server up on %d\n", PORT);

    while (1) {
        int n = recvfrom(sock, buf, BUF_SIZE - 1, 0, (struct sockaddr *)&client, &client_len);
        if (n < 0) {
            perror("recvfrom");
            break;
        }
        buf[n] = 0;
        printf("client [%s:%d]: %s\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port), buf);

        if (is_goodbye(buf)) {
            char *msg = "bye then";
            sendto(sock, msg, strlen(msg), 0, (struct sockaddr *)&client, client_len);
            printf("client said bye, shutting down\n");
            break;
        }

        char reply[BUF_SIZE + 16];
        sprintf(reply, "got it: %s", buf);
        sendto(sock, reply, strlen(reply), 0, (struct sockaddr *)&client, client_len);
    }

    close(sock);
    return 0;
}
