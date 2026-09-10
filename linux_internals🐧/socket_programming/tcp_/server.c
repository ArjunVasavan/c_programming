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
    int server_fd, client_fd;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    char buf[BUF_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return 1;
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    listen(server_fd, 1);
    printf("listening on %d\n", PORT);

    client_fd = accept(server_fd, (struct sockaddr *)&addr, &addr_len);
    if (client_fd < 0) {
        perror("accept");
        return 1;
    }
    printf("client connected\n");

    while (1) {
        int n = recv(client_fd, buf, BUF_SIZE - 1, 0);
        if (n <= 0) {
            printf("client dropped\n");
            break;
        }
        buf[n] = 0;
        printf("client: %s\n", buf);

        if (is_goodbye(buf)) {
            char *msg = "bye then";
            send(client_fd, msg, strlen(msg), 0);
            break;
        }

        char reply[BUF_SIZE + 16];
        sprintf(reply, "got it: %s", buf);
        send(client_fd, reply, strlen(reply), 0);
    }

    close(client_fd);
    close(server_fd);
    return 0;
}
