/*
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                                                                            ┃
┃  DOCUMENTATION HEADER                                                      ┃
┃                                                                            ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃                                                                            ┃
┃  Author          Arjun Vasavan                                             ┃
┃  Date            December 05, 2025                                         ┃
┃  Description     Program to implement dup1 and dup2                        ┃
┃                                                                            ┃
┃                                                                            ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛


*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>

void my_dup1(int fd)
{
    printf("fd --> %d\n",fd);
    int st_fd = dup(1);
    close(1);

    int new_fd = dup(fd);
    printf("Hello\n");
    fflush(stdout);
    close(new_fd);

    int last = dup(st_fd);
    printf("World\n");
    fflush(stdout);
}

void my_dup2(int fd)
{
    int dup1 = dup(1);
    printf("Hello\n");
    fflush(stdout);

    int new_fd = dup2(fd,1);
    printf("World\n");
    fflush(stdout);

    int n_dup = dup2(dup1,new_fd);
    printf("Hello\n");

}

int main(int argc,char **argv)
{
    int fd ;
    int choice = atoi(argv[1]);

    if(argc == 3){
        if(choice == 1){
            fd = open(argv[2],O_CREAT | O_EXCL | O_WRONLY,0666);
            printf("WE are executing Dup 1 system\n");
            if (fd == -1){
                if (errno == EEXIST){
                    printf("File already exists. Clear file content? (Y/N): ");
                    char ch;
                    scanf(" %c", &ch);

                    if (ch == 'Y' || ch == 'y'){
                        fd = open(argv[2], O_TRUNC | O_WRONLY);
                        my_dup1(fd);
                        return 1;
                    }   
                    else{
                        printf("Operation cancelled.\n");
                        return 0;
                    }
                }
                else{
                    perror("File open error");
                    return 1;
                }
            }
            my_dup1(fd);
        }else if(choice == 2){
            fd = open(argv[2],O_CREAT | O_EXCL | O_WRONLY,0666);
            printf("WE are executing Dup 2 system\n");
            if (fd == -1){
                if (errno == EEXIST){
                    printf("File already exists. Clear file content? (Y/N): ");
                    char ch;
                    scanf(" %c", &ch);

                    if (ch == 'Y' || ch == 'y'){
                        fd = open(argv[2], O_TRUNC | O_WRONLY);
                        my_dup2(fd);
                    }   
                    else{
                        printf("Operation cancelled.\n");
                        return 0;
                    }
                }
                else{
                    perror("File open error");
                    return 1;
                }
            }
            my_dup2(fd);
        }

        else{
            perror("Error in File\n");
        }

    }
    else{
        printf("Enter the correct arguments");
        return 1;
    }
}
