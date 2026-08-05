#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>

#define PORT 2000
#define IP "127.0.0.1"

int main()
{
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in servinfo;
    servinfo.sin_family = AF_INET;
    servinfo.sin_port = htons(PORT);
    servinfo.sin_addr.s_addr = inet_addr(IP);

    char op;
    int num1, num2, result, port;
    printf("Enter num1: ");
    scanf("%d", &num1);
    printf("Enter num2: ");
    scanf("%d", &num2);
    printf("Enter arithmetic operator: ");
    scanf(" %c", &op);

    printf("INFO:Created relay socket\n");

    int ret = connect(sock_fd, (struct sockaddr*) &servinfo, sizeof(servinfo));
    printf("SUCCESS:relay connection successful\n");

    send(sock_fd, &op, sizeof(op), 0);
    recv(sock_fd, &port, sizeof(port), 0);

    //printf("SERVER IP %lu\n", );
    printf("SERVER PORT %d\n", port);

    close(sock_fd);
    
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    printf("INFO:Created server socket\n");

    struct sockaddr_in serviinfo;
    serviinfo.sin_family = AF_INET;
    serviinfo.sin_port = htons(port);
    serviinfo.sin_addr.s_addr = inet_addr(IP);

    int ret1 = connect(socket_fd, (struct sockaddr*)&serviinfo, sizeof(serviinfo));
    printf("SUCCESS: Server connection successful\n");
    
    send(socket_fd, &num1, sizeof(num1), 0);
    send(socket_fd, &num2, sizeof(num2), 0);
    send(socket_fd, &op, sizeof(op), 0);

    recv(socket_fd, &result, sizeof(result), 0);
    printf("RESULT: %d\n", result);

    close(socket_fd);

    return 0;
}
