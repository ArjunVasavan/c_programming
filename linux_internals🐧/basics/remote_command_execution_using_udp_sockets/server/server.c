#include "../header.h"
int main(int argc, char** argv) {

    data_packet data;
    command_request_packet cmd;
    acknowledgement_packet ack;

    int sockfd = socket(AF_INET,SOCK_DGRAM,0);

    if ( sockfd < 0 ) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;

    memset(&server_addr,0,sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(IP); 


    if ( bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr)) < 0 ) {

        perror("bind failed");
        exit(EXIT_FAILURE);

    }

    printf("UDP Server listening on port %d\n",PORT);
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    ssize_t recieved = recvfrom(sockfd,&cmd,sizeof(cmd),0,(struct sockaddr*)&client_addr,&client_len);

    if ( recieved < 0 ) {
        perror("recvfrom failed");
        exit(EXIT_FAILURE);
    }

    printf("PORT Number : %d\n",ntohs(client_addr.sin_port));
    printf("IP address  : %s\n",inet_ntoa(client_addr.sin_addr));

    printf("Command        : %s\n",cmd.command);
    printf("Number of times: %d\n",cmd.no_of_times);

    int file_fd = open("file.txt",O_CREAT|O_WRONLY|O_TRUNC,0666);

    if ( file_fd == -1 ) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }


    char* string[2];
    string[0] = cmd.command;
    string[1] = NULL;

    for ( int i = 1 ; i <= cmd.no_of_times ; i++ ) {

        dup2(file_fd,STDOUT_FILENO);
        pid_t pid = fork();
        if ( pid == 0 ){
            execvp(cmd.command,string);
        }
        wait(NULL);
    }

    close(file_fd);

    file_fd = open("file.txt",O_RDONLY);

    char buffer[65];

    int read_count = 0;

    int pack_counter = 0;

    while ( (read_count = read(file_fd,buffer,64) ) > 0 ) {

        memcpy(data.data_buf,buffer,read_count);
        data.n_flag = read_count;
        data.pack_no = pack_counter;
        pack_counter+=1;
        sendto(sockfd,&data,sizeof(data),0,(struct sockaddr*)&client_addr,client_len);

        recvfrom(sockfd,&ack,sizeof(ack),0, (struct sockaddr*)&client_addr,&client_len);

        if ( ack.pack_no != data.pack_no ) {

            printf("Entered Ack sending");
        
            while (ack.pack_no != data.pack_no) {
                sendto(sockfd,&data,sizeof(data),0,(struct sockaddr*)&client_addr,client_len);
                recvfrom(sockfd,&ack,sizeof(ack),0, (struct sockaddr*)&client_addr,&client_len);
            }

        }

    }

    close(sockfd);
}
