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
    printf("INFO:Created relay socket\n");

    struct sockaddr_in servinfo;
    servinfo.sin_family = AF_INET;
    servinfo.sin_port = htons(PORT);
    servinfo.sin_addr.s_addr = inet_addr(IP);

    int ret = bind(sock_fd, (struct sockaddr *)&servinfo, sizeof(servinfo));

    listen(sock_fd, 5);
    printf("LISTENING:relay server is listening\n");

    struct sockaddr_in clinfo;
    socklen_t clilen = sizeof(clinfo);
    
    char op;
    int port;
    while(1)
    {
        int data_fd = accept(sock_fd, (struct sockaddr*)&clinfo, &clilen);
        recv(data_fd, &op, sizeof(op), 0);
        
        int ip;
        switch(op)
        {
            case '+':
                port = 2001;
                break;
            case '-':
                port = 2002;
                break;
            case '*':
                port = 2003;
                break;
            case '/':
                port = 2004;
                break;
            case '%':
                port = 2005;
                break;
        }
        printf("relay server accepted connection\n");

        send(data_fd, &port, sizeof(port), 0);

        close(data_fd);
    }

    close(sock_fd);
    return 0;
}


