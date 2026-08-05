#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>

#define PORT 2003
#define IP "127.0.0.1"

int main()
{
    int num1, num2, result;
    char op;

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    printf("INFO:Created server socket\n");

    struct sockaddr_in servinfo;
    servinfo.sin_family = AF_INET;
    servinfo.sin_port = htons(PORT);
    servinfo.sin_addr.s_addr = inet_addr(IP);

    int bin = bind(sock_fd, (struct sockaddr*) &servinfo, sizeof(servinfo));
    listen(sock_fd, 5);
    printf("LISTENING:mul server is listening\n");

    struct sockaddr_in clinfo;
    socklen_t clilen = sizeof(clinfo);

    while(1)
    {
        int data_fd = accept(sock_fd, (struct sockaddr*) &clinfo, &clilen);
        printf("ACCEPTED:accepted a connection\n");

        recv(data_fd, &num1, sizeof(num1), 0);
        recv(data_fd, &num2, sizeof(num2), 0);
        recv(data_fd, &op, sizeof(op), 0);

        printf("client data: %d %d %c\n", num1, num2, op);

        result = num1 * num2;
        printf("Result is %d\n", result);
        printf("Sending result to client....\n");
        send(data_fd, &result, sizeof(result), 0);

        close(data_fd);

    }

    close(sock_fd);
    return 0;
}
