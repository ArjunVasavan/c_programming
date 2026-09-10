#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ctype.h>

#define PORT 8080
#define BUF_SIZE 1024

int is_goodbye(char *msg)
{
    for (int i = 0; msg[i]; i++)
        msg[i] = tolower(msg[i]);

    if (strstr(msg, "bye") || strstr(msg, "quit") || strstr(msg, "see you later"))
        return 1;
    return 0;
}

int main()
{
    int sock;
    struct sockaddr_in server;
    socklen_t server_len = sizeof(server);
    char buf[BUF_SIZE];

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    printf("udp client ready, type bye/quit to stop\n");

    while (1) {
        printf("> ");
        if (!fgets(buf, BUF_SIZE, stdin))
            break;

        buf[strcspn(buf, "\n")] = 0;
        if (strlen(buf) == 0)
            continue;

        sendto(sock, buf, strlen(buf), 0, (struct sockaddr *)&server, server_len);

        int leaving = is_goodbye(buf);

        int n = recvfrom(sock, buf, BUF_SIZE - 1, 0, NULL, NULL);
        if (n < 0) {
            perror("recvfrom");
            break;
        }
        buf[n] = 0;
        printf("server: %s\n", buf);

        if (leaving)
            break;
    }

    close(sock);
    return 0;
}
