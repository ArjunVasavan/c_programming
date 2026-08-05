#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>


void copy(int fd_r,int fd_w ) {

    char ch[100];

    int ret = 0;

    while ( (ret = read(fd_r,ch,100)) != 0  ) {

        write(fd_w,ch,ret);

    }

}


int main(int argc, char** argv) {

    if ( argc < 2 ) {

        errno = EINVAL;
        perror("arcgc");
        exit(1);

    }

    char* src_name;
    char* dst_name;

    if ( argc == 4 ) {

        if ( strcmp(argv[1],"-p") != 0 ) {
            errno = EINVAL;
            perror("-p is not present");
            exit(1);
        }

        src_name = argv[2];
        dst_name = argv[3];

    } else {
    
        src_name = argv[1];
        dst_name = argv[2];
    }
    
    int fd_r = open(src_name,O_RDONLY);

    int fd_w = open(dst_name,O_WRONLY|O_EXCL|O_CREAT,0666);

    if ( fd_w == -1 ) {
        char writer[100] = "Already present\n";
        write(1,writer,sizeof(writer));
        char option[50] = "Do you want to overwrite?\n1) Yes\n2) No\nchoice=>";
        write(1,option,sizeof(option));

        char string_choice[10];

        read(0,string_choice,sizeof(int));

        int choice = atoi(string_choice);

        switch (choice) {
        
            case 1:{ 
                fd_w = open(dst_name,O_WRONLY|O_TRUNC,0666);
                copy(fd_r,fd_w); 
                char success[] ="copied succes";
                write(1,success,sizeof(success));
                break;
            }

            case 2: exit(0);

            default:{

                printf("Entered value is %d\n",choice);
                char error_print[] = "[ERROR]: enter 1 or 2 \n";
                write(1,error_print,sizeof(error_print));
                exit(0);
            }
        }


    } else {

        char writer[100] = "Not present\n";
        write(1,writer,sizeof(writer));
        copy(fd_r,fd_w);
        char writer_1[100] = "Successfully copied\n";
        write(1,writer_1,sizeof(writer_1));
    }

    if ( argc == 4 ) {

        struct stat st;
        fstat(fd_r,&st);
        fchmod(fd_w,st.st_mode);

        printf("Changed mode\n");
    }
    
}
