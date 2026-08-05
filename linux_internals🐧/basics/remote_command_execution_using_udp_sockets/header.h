#ifndef HEAD_H

#define HEAD_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/wait.h>


#define PORT 2000
#define IP "127.0.0.1"

typedef struct {

    char data_buf[65];

    int pack_no;

    int n_flag;

} data_packet ;


typedef struct {

    char command[100];

    int no_of_times;

} command_request_packet;

typedef struct {

    char data[65];

    int pack_no;

} acknowledgement_packet;

#endif
